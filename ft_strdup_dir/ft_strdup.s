;ft_strdup

section .note.GNU-stack
section .text

extern	malloc
extern  ft_strlen
global ft_strdup

ft_strdup:
	push	rdi
	call	ft_strlen
	mov	rdi, rax
	inc	rdi
	call	malloc	WRT ..plt
	mov	rcx, 0
	pop	r9
loop:
	mov	r10b, [r9 + rcx]
	cmp	r10b, 0
	je	end
	mov	[rax + rcx], r10
	inc	rcx
	jmp	loop
end:
	mov	byte [rax + rcx], 0
	ret
