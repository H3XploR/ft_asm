;ft_strcpy

section .note.GNU-stack
section .text
global ft_strcpy

ft_strcpy:
	mov	rcx, 0
loop:
	mov	r10b, [rsi + rcx]
	cmp	r10b, 0
	je	end
	mov	[rdi + rcx], r10b
	inc	rcx
	jmp	loop
end:
	mov	byte [rdi + rcx], 0
	lea	rax, [rdi]
	ret
