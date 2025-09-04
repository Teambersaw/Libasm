section .text
	global ft_strlen

ft_strlen:
	xor		rcx, rcx ; rax = 0 (counter)
	cmp		rdi, 0x0 ; si la string est NULL
	je		.end

	.loop:
		cmp		byte [rdi + rcx], 0 ; compare current char with null terminator
		je		.end
		inc		rcx
		jmp		.loop

	.end:
		mov rax, rcx
		ret

