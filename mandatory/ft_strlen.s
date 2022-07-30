global ft_strlen

section .text
ft_strlen:
	xor rax, rax
	jmp count

inc:
	inc rax

count:
	cmp BYTE [rdi + rax], 0
	jnz inc
	ret
