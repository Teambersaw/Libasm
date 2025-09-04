section .text
	global ft_strdup
	extern ft_strlen
	extern ft_strcpy
	extern malloc
	extern __errno_location

; char *ft_strdup(const char *s) ; rdi = s
ft_strdup:
	push	rdi
	call	ft_strlen ; rdi from strdup to strlen
	inc		rax ; for null terminator value of buffer
	mov		rdi, rax ; for malloc argument size
	call	malloc wrt ..plt
	cmp		rax, 0
	je		error ; jump if NULL
	pop		rsi
	mov		rdi, rax ; destination for strcpy
	call	ft_strcpy
	ret

error:
	neg rax
	mov rdi, rax
	call __errno_location wrt ..plt
	mov [rax], rdi
	mov rax, 0
	ret
