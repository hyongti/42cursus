section .text
	global _ft_write
	; ssize_t	ft_write(int filedes == rdi , const void *buf == rsi, size_t nbyte == rdx)
	extern ___error

_ft_write:
	mov rax, 0x2000004	; syscall은 rax를 참조함
	syscall				; syscall의 리턴 값은 레지스터 rax에 담기며, 리턴값(errno)의 범위는 -4095부터 -1 사이
	jc err				; jc(jump if carry)는 carry flag가 켜질 때 jump. carry flag는 최상단 비트가 바뀔 때 켜짐.
	ret

err:
	push rax		;syscall write가 실패하면서 반환한 에러 번호가 저장 되어있다.
	call ___error	;___errno가 에러 번호가 저장 되어야 할곳의 주소를 rax에 리턴하기 때문에 
					;위에서 스택에 에러 번호를 담아둠
	pop qword[rax]	;ft_write.s:42: error: instruction not supported in 64-bit mode
	mov rax, -1		;각괄호[]는 그 안에 있는 값을 주소로 인식하여, 그 주소가 가리키는 곳을 찾아가라는 의미이다
	ret				;qword 는 뒤의 주소를 64bit체제에 맞게 변환하여 준다.