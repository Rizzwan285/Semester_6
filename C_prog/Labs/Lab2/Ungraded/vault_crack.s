	.file	"vault_crack.c"
	.text
	.globl	MASTER_KEY
	.data
	.align 4
	.type	MASTER_KEY, @object
	.size	MASTER_KEY, 4
MASTER_KEY:
	.long	210
	.globl	FOUND_KEY
	.bss
	.align 4
	.type	FOUND_KEY, @object
	.size	FOUND_KEY, 4
FOUND_KEY:
	.zero	4
	.section	.rodata
.LC0:
	.string	"Calculated Security Code: %d\n"
.LC1:
	.string	"Accessing sector %d...\n"
	.align 8
.LC2:
	.string	"ALERT: You didn't find the correct key in the assembly file."
.LC3:
	.string	"VAULT OPEN. DATA: "
.LC4:
	.string	"%d "
.LC5:
	.string	"Access Denied."
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$64, %rsp
	movl	$4, -12(%rbp)
	movl	$1, -16(%rbp)
	movl	-12(%rbp), %edx
	movl	-16(%rbp), %eax
	leal	(%rdx,%rax), %ecx
	movl	-12(%rbp), %edx
	movl	-16(%rbp), %eax
	addl	%edx, %eax
	imull	%ecx, %eax
	movl	%eax, -20(%rbp)
	movl	-20(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC0, %edi
	movl	$0, %eax
	call	printf
	movl	$0, -4(%rbp)
	jmp	.L2
.L3:
	movl	-4(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC1, %edi
	movl	$0, %eax
	call	printf
	addl	$1, -4(%rbp)
.L2:
	cmpl	$2, -4(%rbp)
	jle	.L3
	movl	FOUND_KEY(%rip), %edx
	movl	MASTER_KEY(%rip), %eax
	cmpl	%eax, %edx
	je	.L4
	movl	$.LC2, %edi
	call	puts
	jmp	.L5
.L4:
	movl	-20(%rbp), %eax
	movl	%eax, %edi
	call	verify_access
	testl	%eax, %eax
	je	.L6
	movl	$1, -64(%rbp)
	movl	$6, -60(%rbp)
	movl	$2, -56(%rbp)
	movl	$7, -52(%rbp)
	movl	$3, -48(%rbp)
	movl	$8, -44(%rbp)
	movl	$4, -40(%rbp)
	movl	$9, -36(%rbp)
	movl	$5, -32(%rbp)
	movl	$10, -28(%rbp)
	movl	$10, -24(%rbp)
	movl	$.LC3, %edi
	movl	$0, %eax
	call	printf
	movl	$1, -8(%rbp)
	jmp	.L7
.L8:
	movl	-8(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC4, %edi
	movl	$0, %eax
	call	printf
	addl	$1, -8(%rbp)
.L7:
	movl	-8(%rbp), %eax
	cmpl	-24(%rbp), %eax
	jle	.L8
	movl	$10, %edi
	call	putchar
	jmp	.L5
.L6:
	movl	$.LC5, %edi
	call	puts
.L5:
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (GNU) 8.5.0 20210514 (Red Hat 8.5.0-26.0.1)"
	.section	.note.GNU-stack,"",@progbits
