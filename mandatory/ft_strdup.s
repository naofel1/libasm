global ft_strdup
extern malloc, ft_strlen, ft_strcpy, __errno_location

section .text
ft_strdup:
	call ft_strlen
	inc rax
	push rdi
	mov rdi, rax
	call malloc WRT ..plt
	cmp rax, 0
	jl errno
	pop r10
	mov rdi, rax
	mov rsi, r10
	call ft_strcpy
	ret

errno:
	neg rax
	mov rdi, rax
	call __errno_location WRT ..plt
	mov [rax], rdi
	mov rax, -1
	ret
