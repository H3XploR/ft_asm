;ft_strcmp
section .note.GNU-stack 
section .text
global ft_strcmp

ft_strcmp:
	mov	rcx, 0
loop:
	mov	r8b, [rdi+rcx]
	mov	r9b, [rsi+rcx]
	cmp	r8b, r9b
	jz	ok
	jne	diff
	inc	rcx
	jmp	loop

diff:
	sub	r8b, r9b	
	mov	rax, r8
	ret
ok:
	xor rax, rax
	ret
