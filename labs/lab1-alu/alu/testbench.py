import pyverilator
from ctypes import c_int32, c_uint32
import math

ALU_ADD = 1
ALU_SUB = 2

ALU_SLL = 3
ALU_SRL = 4
ALU_SRA = 5
ALU_SLT = 7
ALU_SLTU = 8

ALU_XOR = 9
ALU_OR  = 10
ALU_AND = 11
ALUSYM = { ALU_ADD: '+', ALU_SUB: '-', ALU_XOR: '^', ALU_OR: '|',ALU_AND: '&',ALU_SLL: '<<',ALU_SRL: '>>',ALU_SRA:'>>>', ALU_SLT:'*<',ALU_SLTU:'<'}

def s32(value):
    return -(value & 0x80000000) | (value & 0x7fffffff)

def s32u(value):
    return value & 0xffffffff
def uint32(v):
    return c_uint32(v).value

# This is the function we are trying to emulate in our system verilog 
def alu(alu_function, a, b):
    if alu_function == ALU_ADD:
        r = a + b
    elif alu_function == ALU_SUB:   
        r = a - b
    elif alu_function == ALU_XOR:   
        r = a ^ b
    elif alu_function == ALU_OR:
        r = a | b
    elif alu_function == ALU_AND:
        r = a & b
    elif alu_function == ALU_SLL:
        r = a << b
    elif alu_function == ALU_SRL:
        r = (a % 0x100000000) >> b 
    elif alu_function == ALU_SRA:
        r =  s32(a) >> b
    elif alu_function == ALU_SLT:
        if (s32(a) < s32(b)):
            r = 1
        else:
            r = 0
    elif alu_function == ALU_SLTU:
        if (s32u(a)< b):
            r = 1
        else:
            r = 0
    else:
        r = 0
    r = uint32(r)
    zero = 1 if (r == 0) else 0
    return (r, zero)

def test_alu(tb, alu_function, a, b):
    tb.io.alu_function = alu_function
    tb.io.op_a = a
    tb.io.op_b = b

    (cresult, ceq) = alu(alu_function, a, b)     # computer result
    vresult = uint32(tb.io.result)                  # verilog result
    veq = uint32(tb.io.result_eq_zero)
    ok = cresult == vresult and ceq == veq
    print("{:08x} {} {:08x}\tresult={:08x},{} (cresult={:08x},{}) {}".\
            format(a, ALUSYM[alu_function], b, vresult, veq, cresult, ceq, ok));
    return ok

tb = pyverilator.PyVerilator.build('alu.sv')
ok = test_alu(tb, ALU_ADD, 1, 2); 
ok = test_alu(tb, ALU_ADD, 0xffffffff, 2); 
ok = test_alu(tb, ALU_ADD, 0x7fffffff, 0xFF); 
ok = test_alu(tb, ALU_SUB, 0xdeadbeef, 0xdeadbeef); 
ok = test_alu(tb, ALU_SUB, 0xdeadbeef, 2); 
ok = test_alu(tb, ALU_SUB, 0xe1e10, 0xdeadbeef); 

## custom test case
# 1
print(" ------ lab question 1 ------")
ok = test_alu(tb, ALU_ADD, 0xffffffff, 1); # -1+1 see if add sets the result_eq_zero
ok = test_alu(tb, ALU_SUB, 0, 0) # adding and subbing zeros
ok = test_alu(tb, ALU_ADD, 0, 0)
# 2
print(" ------ lab question 2 ------")
# XOR TESTS
ok = test_alu(tb, ALU_XOR, -1, 1)
ok = test_alu(tb, ALU_XOR, 0xffffffff, 1)
ok = test_alu(tb, ALU_XOR, 0xffffffff, 0x1)
ok = test_alu(tb, ALU_XOR, 0xdeadbeef, 0xdeadbeef)
ok = test_alu(tb, ALU_XOR, 0x1234abcd, 0xabcd1234) # B9F9 B9F9
# OR TESTS
ok = test_alu(tb, ALU_OR, -1, 1)
ok = test_alu(tb, ALU_OR, 0xffffffff, 1)
ok = test_alu(tb, ALU_OR, 0xffffffff, 0x1)
ok = test_alu(tb, ALU_OR, 0xdeadbeef, 0xdeadbeef)
ok = test_alu(tb, ALU_OR, 0x1234abcd, 0xabcd1234) # BBFD BBFD
# AND TESTS
ok = test_alu(tb, ALU_AND, -1, 1)
ok = test_alu(tb, ALU_AND, 0xffffffff, 1)
ok = test_alu(tb, ALU_AND, 0xffffffff, 0x1)
ok = test_alu(tb, ALU_AND, 0xdeadbeef, 0xdeadbeef)
ok = test_alu(tb, ALU_AND, 0x1234abcd, 0xabcd1234) # 0204 0204
# 3
print(" ------ lab question 3 ------")
print("SLL")
ok = test_alu(tb, ALU_SLL, -1, 1)
ok = test_alu(tb, ALU_SLL, 0xffffffff, 1)
ok = test_alu(tb, ALU_SLL, 0xffffffff, 0x1)
ok = test_alu(tb, ALU_SLL, 0xdeadbeef, 0xdeadbeef)
ok = test_alu(tb, ALU_SLL, 0x1234abcd, 0xabcd1234)
print("SRL")
ok = test_alu(tb, ALU_SRL, 0, 0)
ok = test_alu(tb, ALU_SRL, -1, 2)
ok = test_alu(tb, ALU_SRL, 0xffffffff, 2)
ok = test_alu(tb, ALU_SRL, 0xffffffff, 0x2)
ok = test_alu(tb, ALU_SRL, 0xdeadbeef, 0xdeadbeef)
ok = test_alu(tb, ALU_SRL, 0x1234abcd, 0xabcd1234)
print("SRA")
ok = test_alu(tb, ALU_SRA, -1, 2)
ok = test_alu(tb, ALU_SRA, 0xffffffff, 2)
ok = test_alu(tb, ALU_SRA, 0xffffffff, 0x2)
ok = test_alu(tb, ALU_SRA, 0xdeadbeef, 0xdeadbeef)
ok = test_alu(tb, ALU_SRA, 0x1234abcd, 0xabcd1234)
print("SLT")
ok = test_alu(tb, ALU_SLT, -1, 2)
ok = test_alu(tb, ALU_SLT, 0xffffffff, 2)
ok = test_alu(tb, ALU_SLT, 0xffffffff, 0x2)
ok = test_alu(tb, ALU_SLT, 0xdeadbeef, 0xdeadbeef)
ok = test_alu(tb, ALU_SLT, 0x1234abcd, 0xabcd1234)
print("SLTU")
ok = test_alu(tb, ALU_SLTU, -1, 2)
ok = test_alu(tb, ALU_SLTU, 0xffffffff, 2)
ok = test_alu(tb, ALU_SLTU, 0xffffffff, 0x2)
ok = test_alu(tb, ALU_SLTU, 0xdeadbeef, 0xdeadbeef)
ok = test_alu(tb, ALU_SLTU, 0x1234abcd, 0xabcd1234)
