.section .text
.global _start
_start:
    # these first three instructions are I-type
    xori x1, zero, 0xe1 #e1
    addi x2, x1, 11 #ec
    ori x3, zero, 0x36 # 36

    # remaining instruction types
    slli x2, x2, 16 #EC0000 - shift left 16
    slli x10, x1, 24 # E1000000
    add x10, x10, x2 # E1EC0000
    slli x3, x3, 8 # 3600
    addi x3, x3, 8 # 3608
    add x10, x3, x10 # E1EC 3608

    ebreak
