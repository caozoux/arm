.text //code section
.globl _start
_start:

	mov w6, 8
	//mov w5, #0xa3
	ldr w5, =0xe6e8800c
	bl _asm_data_format
cycl:
	mov w4, 0x35
	bl _asm_putch
	b cycl

	mov x2, 0
	ldr w0, =0xe6e8800c
	mov x1, 0x36
	strb w1, [x0]
	add x2, x2, 1
	cmp x2, 20
	bl test
	b.lo _start
	ldr x1, =msg  // buffer to write
	mov x2, len   // size of buffer
	mov x8, 64    // sys_write() is at index 64 in kernel functions table
	svc #0        // generate kernel call sys_write(stdout, msg, len);
	
	mov x0, 123 // exit code
	mov x8, 93  // sys_exit() is at index 93 in kernel functions table
	svc #0      // generate kernel call sys_exit(123);

	//w4 putch char
_asm_putch:
	ldr x1, =0xe6e88010
	ldr x2, [x1]
	and x2, x2, #(1<<5)
	cmp x2, #0
	b.eq _asm_putch
	ldr w0, =0xe6e8800c
	strb w4, [x0]
	ldr x1, =0xe6e88010
	mov x0, #~(3<<5)
	str x0, [x1]
	ret

	//x5 data, x6 size
_asm_data_format:
	mov x0, x6
	sub x0, x0, 1
	mov x1, 4
	mul x0, x0, x1

	mov x1, x5
	lsr x1, x1, x0
	and x1, x1, 0x0f
	cmp x1, 9
	b.gt  ch1
	add x1, x1, #0x30
	b ch2
ch1:
	sub x1, x1, #10
	add x1, x1, #0x61
ch2:
	mov w4, w1
	ldr x1, =0xe6e88010
	ldr x2, [x1]
	and x2, x2, #(1<<5)
	cmp x2, #0
	b.eq _asm_putch
	ldr w0, =0xe6e8800c
	strb w4, [x0]
	ldr x1, =0xe6e88010
	mov x0, #~(3<<5)
	str x0, [x1]

	sub w6, w6, 1
	cmp w6, 0
	b.gt _asm_data_format
	ret

_invalid:
	mov x0, 0
	ret

_ret_uboot:
	b _invalid

.data //data section
msg:
    .ascii      "Hello, ARM!\n"
len = . - msg
