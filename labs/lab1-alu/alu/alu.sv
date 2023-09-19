// a simple alu
//
`include "constants.svh"

`default_nettype none

//
module alu(
    input [4:0] alu_function,
    input [31:0] op_a,
    input [31:0] op_b,
    output logic [31:0] result,
    output result_eq_zero);

    // Implement the zero flag
    assign result_eq_zero = 1'b0;

    // Compute result
    always_comb begin
        case (alu_function)
            `ALU_ADD:   result = op_a + op_b;
            `ALU_SUB:   result = op_a - op_b;
            `ALU_XOR:   result = op_a ^ op_b;
            `ALU_OR :   result = op_a | op_b;
            `ALU_AND:   result = op_a & op_b;
            `ALU_SLL:   result = op_a << op_b;
            `ALU_SRL:   result = op_a >> op_b;
            `ALU_SRA:   result = $signed(op_a) >>> $signed(op_b);
            `ALU_SLT:   result = (($signed(op_b)-$signed(op_a)) > 0)? 'b1:'b0;
            `ALU_SLTU:  result = ($unsigned(op_a) < $unsigned(op_b))? 'b1:'b0;

            default: result = `ZERO;
        endcase
    end

// added logic
    always_comb begin
        case(result)
            'b0: result_eq_zero = 1'b1;
            default: result_eq_zero = 1'b0;
        endcase
    end
endmodule
