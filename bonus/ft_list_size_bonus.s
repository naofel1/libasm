global ft_list_size

section .text
ft_list_size:
	xor rax, rax
	jmp count

inc:
	inc rax
	mov rdi, [rdi + 8]

count:
	cmp rdi, 0
	jnz inc
	ret
