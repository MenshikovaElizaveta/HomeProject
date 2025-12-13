	.file	"optSort.c"
	.text
	.p2align 4
	.globl	bubbleSort
	.type	bubbleSort, @function
bubbleSort:
.LFB16:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rdi, %rbp
	movslq	%esi, %rdi
	movl	$4, %esi
	pushq	%rbx
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	movq	%rdi, %rbx
	subq	$8, %rsp
	.cfi_def_cfa_offset 32
	call	calloc@PLT
	movq	%rax, %rdi
	testl	%ebx, %ebx
	jle	.L1
	movl	%ebx, %edx
	movq	%rbp, %rsi
	salq	$2, %rdx
	call	memcpy@PLT
	movq	%rax, %rdi
	leaq	4(%rax), %r8
	cmpl	$1, %ebx
	je	.L1
	.p2align 4,,10
	.p2align 3
.L3:
	cmpl	$1, %ebx
	jle	.L20
	leal	-2(%rbx), %edx
	movq	%rdi, %rax
	leaq	(%r8,%rdx,4), %rsi
	.p2align 4,,10
	.p2align 3
.L5:
	movq	(%rax), %xmm0
	pshufd	$0xe5, %xmm0, %xmm1
	movd	%xmm0, %ecx
	movd	%xmm1, %edx
	cmpl	%edx, %ecx
	jle	.L4
	pshufd	$225, %xmm0, %xmm0
	movq	%xmm0, (%rax)
.L4:
	addq	$4, %rax
	cmpq	%rsi, %rax
	jne	.L5
	subl	$1, %ebx
	cmpl	$1, %ebx
	jne	.L3
.L1:
	addq	$8, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 24
	movq	%rdi, %rax
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	ret
	.p2align 4,,10
	.p2align 3
.L20:
	.cfi_restore_state
	subl	$1, %ebx
	jmp	.L3
	.cfi_endproc
.LFE16:
	.size	bubbleSort, .-bubbleSort
	.ident	"GCC: (Ubuntu 13.3.0-6ubuntu2~24.04) 13.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
