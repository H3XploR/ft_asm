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
	cmp	r10, 0		;if (r10 == 0) goto erreur_chaine_vide
	jz	erreur_chaine_vide
	pop	rsi
	pop	rdi
	push	rdi		;rdi = arg1
	push	rsi		;rsi = arg2
	call	ft_strlen
	mov	rcx, rax	;rcx = longueur numero
	dec	rcx		;rcx = (longueur numero) - 1
	xor	r11, r11	;clean r11 = 0
	mov	byte r11b, [rdi + rcx] ;r11b = *(arg1 + rcx)
	mov	r12, 0		;index = 0
loop_base_search:
	cmp	r12, r10
	jg	fin_chaine_base
	cmp	[rsi + r12], r11b; if( *(arg2 + index) == r11b) goto trouve
	je	char_trouve
	inc	r12
	jmp	loop_base_search
	ret
erreur_chaine_vide:
	mov	rax, 0
	ret
fin_chaine_base:
	mov rax, 0
	ret
char_trouve:
	mov rax, r12
