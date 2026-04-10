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
	xor	r8, r8
	mov	r8, rax
	cmp	r10, 1		;if (r10 == 0) goto erreur_chaine_vide
	dec	r10		;r10 = (longueur chaine base) - 1
	jle	erreur_chaine_vide
	jmp	check_plus_and_minus
continue:
	pop	rsi
	pop	rdi
	push	rdi		;rdi = arg1
	push	rsi		;rsi = arg2
	push	r8
	call	ft_strlen
	mov	rcx, rax	;rcx = longueur numero
	dec	rcx		;rcx = (longueur numero) - 1
	xor	r14, r14	;init result final a 0
	xor	r11, r11	;clean r11 = 0
	mov	r13, 1		;pow = 1
loop:
	cmp	rcx, 0
	jl	end
	mov	byte r11b, [rdi + rcx] ;r11b = *(arg1 + rcx)
	cmp	r11b, 45
	je	end_neg
	cmp	r11b, 43
	je	end
	xor	r12, r12	;index_base = 0
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
	pop	r14
	pop	r14
	ret
erreur_illegale_char_base:
	mov	rax, 0
	pop	r14
	pop	r14
	ret
fin_chaine_base:
	mov rax, 0
	pop	r14
	pop	r14
	pop	r14
	ret
char_trouve:
	imul	r12, r13	;index * pow
	xor	r8, r8
	pop	r8
	imul	r13, r8		;pow * longueur_base
	push	r8
	add	r14, r12	;resultat final a renvoyer
	dec	rcx		;index_nb - 1
	jmp	loop
end:
	mov	rax, r14
	pop	rdi
	pop	rsi
	pop	r14
	ret
end_neg:
	mov	rax, r14
	pop	rdi
	pop	rsi
	pop	r14
	neg	rax
	ret
check_plus_and_minus:
	mov	r15, r10
loop_check_plus_and_minus:
	cmp	byte [rdi + r15], 45
	je	erreur_illegale_char_base
	cmp	byte [rdi + r15], 43
	je	erreur_illegale_char_base
	dec	r15
	cmp	r15, 0
	jl	continue
	jmp	loop_check_plus_and_minus
