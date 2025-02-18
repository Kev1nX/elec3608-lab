#  NERV -- Naive Educational RISC-V Processor
#
#  Copyright (C) 2020  N. Engelhardt <nak@yosyshq.com>
#  Copyright (C) 2020  Claire Xenia Wolf <claire@yosyshq.com>
#
#  Permission to use, copy, modify, and/or distribute this software for any
#  purpose with or without fee is hereby granted, provided that the above
#  copyright notice and this permission notice appear in all copies.
#
#  THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
#  WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
#  MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
#  ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
#  WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
#  ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
#  OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.

TOOLCHAIN_PREFIX?=riscv64-unknown-elf-
VERILATOR = verilator

all: test1.out test2.out test3.out test4.out

%.out: %.hex
	cp $^ firmware.hex
	python testbench.py -t

%.elf : %.s
	$(TOOLCHAIN_PREFIX)gcc -march=rv32i -mabi=ilp32 -Os -Wall -Wextra -Wl,-Bstatic,-T,sections.lds,--strip-debug -ffreestanding -nostdlib -o $@ $^
	$(TOOLCHAIN_PREFIX)as -march=rv32i -mabi=ilp32 -a $^ > $*.lst

%.hex : %.elf
	$(TOOLCHAIN_PREFIX)objcopy -O verilog $< $@

clean:
	rm -rf test3.elf test3.hex testbench testbench.vcd gtkwave.log 
	rm -rf *.vcd *.lst *.hex *.out *.elf
	rm -rf disasm.o disasm.s checks/ cexdata/ obj_dir

rundocker:
	../common/rundocker
