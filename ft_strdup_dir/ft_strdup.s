;ft_strdup

section .note.GNU-stack
section .text

extern	malloc
extern  ft_strlen
global ft_strdup

ft_strdup:
	call	ft_strlen
	push	rax
	mov	rdi, rax
	inc	rdi
	call	malloc	WRT ..plt
	mov	ecx, 0
	pop	r9
loop:
	mov	r10, [r9b + ecx]
	cmp	r10, 0
	je	end
	mov	[rax + ecx], r10
	inc	ecx
	jmp	loop
end:
	mov	[rax + ecx], 0
	ret
