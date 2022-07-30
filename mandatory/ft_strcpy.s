global ft_strcpy

section .text
ft_strcpy:
	xor rcx, rcx
	jmp copy

inc:
	inc rcx

copy:
	mov dl, BYTE [rsi + rcx]
	mov BYTE [rdi + rcx], dl
	cmp dl, 0
	jnz inc
	mov rax, rdi

exit:
	ret
