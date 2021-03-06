section	.text
	global	_ft_strcpy
	; char	*ft_strcpy(char *dst == rdi, const char *src == rsi)

_ft_strcpy:
			mov		rcx, 0			; 카운터 인덱스로 사용할 레지스터 rcx를 0으로 초기화
			cmp		rsi, 0			; rsi가 NULL인지 아닌지 판단
			je		return			; 리턴시 rax에 rdi값을 넣어둬서 src가 널이면
									; dst 리턴
			jmp		copy

increment:
			inc		rcx
			jmp		copy
copy:
			mov		dl, BYTE [rsi + rcx]
			mov		BYTE [rdi + rcx], dl
			cmp		dl, 0				; cmp 연산이 레지스터만 지원
			jnz		increment			; jump not zero 위에서 부터 순서대로 진행
										; 되기 때문에 increment로 올라가면 
										; copy를 반복할수 있다.
return:
			mov		rax, rdi			; return 하기 전에 dst주소를 넣어준다.
			ret