section .text
	global ft_write
	extern __errno_location

ft_write:
	mov	rax, 1 ; sys_write
	syscall
	cmp rax, 0
	js error ; jump if signed
	ret

error:
	neg rax
	mov rdi, rax
	call __errno_location wrt ..plt
	mov [rax], rdi
	mov rax, -1
	ret