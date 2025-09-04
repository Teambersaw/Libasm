section .text
	global ft_strcpy

ft_strcpy:
	; rdi = destination, rsi = source
	xor rcx, rcx
	.loop:
		cmp	byte [rsi + rcx], 0 ; check if current byte is null
		je	.end ; if null, end loop
		mov	r8b, byte [rsi + rcx] ; same as mov [rdi + rcx], [rsi + rcx]
		mov byte [rdi + rcx], r8b
		inc	rcx
		jmp	.loop

	.end:
		mov byte [rdi + rcx], 0
		mov rax, rdi
		ret



