;ft_read
section .note.GNU-stack noalloc noexec nowrite progbits

section .text

extern __errno_location
global ft_read

ft_read:
	mov	rax, 0
	syscall
	cmp	rax, 0
	jge	end
	mov	r8, rax
	call	__errno_location WRT ..plt
	neg	r8
	mov	[rax], r8
	mov	rax, -1
	ret
end:
	ret
