;ft_write
section .note.GNU-stack noalloc noexec nowrite progbits

section .text

extern __errno_location
global ft_write

ft_write:
	mov	rax, 1
	syscall
	cmp	rax, -1
	je	err

err:
	call __errno_location
