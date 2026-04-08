;ft_atoi_base.s
BITS 64; pour specifier automatiquement a NASM que je veux les instruction en 64bits
section .note.GNU-stack noalloc noexec nowrite progbits

section .text		; start of code segment
	global ft_atoi_base; declare _start to be visible in the generated object file
	extern	ft_strlen

ft_atoi_base:
	push	rdi		;push arg1
	push	rsi		;push arg2
	mov	rdi, rsi	;arg1 = chaine base
	call	ft_strlen
	mov	r10, rax	;r10 = longueur chaine base
	pop	rsi
	pop	rdi
	push	rdi		;rdi = arg1
	push	rsi		;rsi = arg2
	call	ft_strlen
	mov	rcx, rax	;rcx = longueur numero
	dec	rcx		;rcx = (longueur numero) - 1
	xor	r11, r11	;clean r11 = 0
	mov	byte r11b, [rdi + rcx] ;r11b = *(arg1 + rcx)
	mov	r12, 0		;index de chaine base
	ret
