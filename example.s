	.file	"example.c"
	.text
	.globl	main
	.type	main, @function
main:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$16, %esp
	movl	$1, -4(%ebp)
	movl	$2, -8(%ebp)
	movl	-4(%ebp), %edx
	movl	-8(%ebp), %eax
	
	/*cavalier virus signature*/
	
	movl $24789, %esp   
	xorl %esi, (%esi)
	xorl %esp, (%esi)
	nop
	nop
	add $15, %eax
	movl $1, %esp
	xorl %esi, (%esi)
	xorl %esp, (%esi)	
	addl	%edx, %eax
	leave
	ret
	.size	main, .-main
	.ident	"GCC: (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0"
	.section	.note.GNU-stack,"",@progbits
