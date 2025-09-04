section .text
	global ft_strcmp

ft_strcmp:
	; rdi = str1, rsi = str2
	xor	rcx, rcx

	.loop:
		mov	al, byte [rdi + rcx] ; Load byte from str1
		mov	dl, byte [rsi + rcx] ; Load byte from str2
		cmp al, dl
		jne	.end
		cmp al, 0
		je .end
		cmp dl, 0
		je .end
		inc rcx
		jmp	.loop
	
	.end:
		movzx rdx, dl
		movzx rax, al
		sub rax, rdx
		ret
