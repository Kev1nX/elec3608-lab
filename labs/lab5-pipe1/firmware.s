/*
 *  NERV -- Naive Educational RISC-V Processor
 *
 *  Copyright (C) 2020  Claire Xenia Wolf <claire@yosyshq.com>
 *
 *  Permission to use, copy, modify, and/or distribute this software for any
 *  purpose with or without fee is hereby granted, provided that the above
 *  copyright notice and this permission notice appear in all copies.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 *  WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 *  MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 *  ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 *  WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 *  ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 *  OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 *
 */
# addi x10, zero, 0
# addi x10, x10, 1
# addi x10, x10, 2
# addi x10, x10, 3
# addi x10, x10, 4
# addi x10, x10, 5
# addi x10, x10, 6
# addi x10, x10, 7
# addi x10, x10, 8
# addi x10, x10, 9
# addi x10, x10, 10

.section .text
.global main
.global _start

_start:
    addi x8, zero, 10
    addi x9, zero, 0
    addi x10, zero, 0
loop:
    addi x9, x9, 1
    add x10, x10, x9
    bne x9, x8, loop
    addi x1,zero,0
ebreak
