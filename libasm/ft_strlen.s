section .text
	global _ft_strlen
	; ft_strlen(arg0 = rdi = char *s)

_ft_strlen:
	mov 	rax, 0	; rax레지스터에 0을 저장한다.
	jmp 	count	; count로 이동

count:
	cmp 	BYTE [rdi + rax], 0
	je 		return					; 위의 값이 0이면 해당되는 인덱스에 '\0'이 담겨있는 것이므로 exit라벨로 점프
	inc	 	rax						; 아니면 rax += 1
	jmp 	count					; 다시 count라벨로 이동

return:
	ret								; rax를 리턴