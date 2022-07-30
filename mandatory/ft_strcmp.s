global ft_strcmp

section .text
ft_strcmp:
	mov r10b, BYTE [rdi]
	mov r11b, BYTE [rsi]
	cmp r10b, 0
	jz exit
	cmp r11b, 0
	jz exit
	cmp r10b, r11b
	jnz exit
	inc rdi
	inc rsi
	jmp ft_strcmp

exit:
	movzx rax, r10b
	movzx rbx, r11b
	sub rax, rbx
	ret
