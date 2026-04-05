;ft_strlen.s
BITS 64; pour specifier automatiquement a NASM que je veux les instruction en 64bits
section .note.GNU-stack noalloc noexec nowrite progbits

section .text		; start of code segment
	global ft_strlen; declare _start to be visible in the generated object file

ft_strlen:
	
	ret
