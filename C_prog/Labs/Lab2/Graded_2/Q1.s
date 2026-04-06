	.file	"Q1.c"
	.text
	.globl	auth_token
	.data
	.align 4
	.type	auth_token, @object
	.size	auth_token, 4
auth_token:
	.long	43617
	.globl	RECOVERED_TOKEN
	.align 4
	.type	RECOVERED_TOKEN, @object
	.size	RECOVERED_TOKEN, 4
RECOVERED_TOKEN:
	.long	43617
	.section	.rodata
.LC0:
	.string	"%d "
.LC1:
	.string	" Exit"
	.align 8
.LC2:
	.string	"ALERT: You didn't find the correct token in the assembly file."
.LC3:
	.string	"%d\n"
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
	subq	$80, %rsp
	movl	$10, -80(%rbp)
	movl	$99, -76(%rbp)
	movl	$50, -72(%rbp)
	movl	$99, -68(%rbp)
	movl	$30, -64(%rbp)
	movl	$99, -60(%rbp)
	movl	$20, -56(%rbp)
	movl	$99, -52(%rbp)
	movl	$40, -48(%rbp)
	movl	$99, -44(%rbp)
	movl	$5, -24(%rbp)
	movl	$0, -4(%rbp)
	jmp	.L2
.L8:
	movl	-4(%rbp), %eax
	movl	%eax, -8(%rbp)
	movl	-4(%rbp), %eax
	movl	%eax, -12(%rbp)
	jmp	.L3
.L5:
	movl	-12(%rbp), %eax
	cltq
	movl	-80(%rbp,%rax,4), %edx
	movl	-8(%rbp), %eax
	cltq
	movl	-80(%rbp,%rax,4), %eax
	cmpl	%eax, %edx
	jge	.L4
	movl	-12(%rbp), %eax
	movl	%eax, -8(%rbp)
.L4:
	addl	$1, -12(%rbp)
.L3:
	movl	-12(%rbp), %eax
	cmpl	-24(%rbp), %eax
	jl	.L5
	movl	-8(%rbp), %eax
	cltq
	movl	-80(%rbp,%rax,4), %eax
	movl	%eax, -28(%rbp)
	movl	-4(%rbp), %eax
	cltq
	movl	-80(%rbp,%rax,4), %edx
	movl	-8(%rbp), %eax
	cltq
	movl	%edx, -80(%rbp,%rax,4)
	movl	-4(%rbp), %eax
	cltq
	movl	-28(%rbp), %edx
	movl	%edx, -80(%rbp,%rax,4)
	movl	$0, -16(%rbp)
	jmp	.L6
.L7:
	movl	-16(%rbp), %eax
	cltq
	movl	-80(%rbp,%rax,4), %eax
	movl	%eax, %esi
	movl	$.LC0, %edi
	movl	$0, %eax
	call	printf
	addl	$1, -16(%rbp)
.L6:
	cmpl	$9, -16(%rbp)
	jle	.L7
	movl	$.LC1, %edi
	call	puts
	addl	$1, -4(%rbp)
.L2:
	movl	-24(%rbp), %eax
	subl	$1, %eax
	cmpl	%eax, -4(%rbp)
	jl	.L8
	movl	RECOVERED_TOKEN(%rip), %edx
	movl	auth_token(%rip), %eax
	cmpl	%eax, %edx
	je	.L9
	movl	$.LC2, %edi
	call	puts
	movl	$1, %eax
	jmp	.L14
.L9:
	movl	RECOVERED_TOKEN(%rip), %eax
	movl	%eax, %esi
	movl	$.LC3, %edi
	movl	$0, %eax
	call	printf
	movl	$9, -20(%rbp)
	jmp	.L11
.L13:
	movl	-20(%rbp), %eax
	cltq
	movl	-80(%rbp,%rax,4), %eax
	cmpl	$99, %eax
	je	.L12
	movl	-20(%rbp), %eax
	cltq
	movl	-80(%rbp,%rax,4), %eax
	movl	%eax, %esi
	movl	$.LC3, %edi
	movl	$0, %eax
	call	printf
.L12:
	subl	$1, -20(%rbp)
.L11:
	cmpl	$0, -20(%rbp)
	jg	.L13
	movl	$0, %eax
.L14:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (GNU) 8.5.0 20210514 (Red Hat 8.5.0-26.0.1)"
	.section	.note.GNU-stack,"",@progbits
