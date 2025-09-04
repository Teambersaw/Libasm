section .text
	global ft_read
	extern __errno_location

ft_read:
	xor rax, rax ; sys_read
	syscall
	test rax, rax ; update flags (OF=0, ZF/SF depend on rax)
	js error	; jump if rax rax is signed
	ret

error:
	neg rax
	mov rdi, rax
	call __errno_location wrt ..plt
	mov [rax], rdi
	mov rax, -1
	ret

