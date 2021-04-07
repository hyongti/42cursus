section .text
	global _ft_strdup
	; char	*ft_strdup(const char *s1 == rdi);
	extern _ft_strlen
	extern _ft_strcpy
	extern _malloc

_ft_strdup:
	call	_ft_strlen		; ft_strlen은 strdup과 마찬가지로 문자열의 주소를 인자로 받음
	add		rax, 1			; ft_strlen의 반환값에 1을 더한 만큼 (sizeof(char) * (len + 1))메모리를 할당해야 함
	push	rdi				; 그러기 위해 잠시 원래 rdi에 담겨있던 값은 스택으로 푸시
	mov		rdi, rax		; malloc의 rdi로는 size가 들어가므로 ft_strlen의 리턴값을 rdi에 mov
	call	_malloc			; malloc 호출
	pop		r9				; 스택에 넣어놨던 rdi는 ft_strcpy의 두 번째 인자(rsi)로 사용해줘야 함. 바로 rsi로 pop하지 않은 이유는 혹시 rsi에 어떤 값이 들어있을 수도 있기 때문
	mov		rdi, rax		; malloc의 반환값인 문자열의 주소를 ft_strcpy의 첫 번째 인자(rdi)로 사용하기 위해 mov
	push	rsi				; 원래 rsi에 담겨있던 값은 잠시 스택으로 push
	mov		rsi, r9			; r9에 담아놨던 값을 rsi로 이동
	call	_ft_strcpy		; ft_strcpy call 리턴값은 rax에 저장된다.
	mov		rdi, r9			; 원래 rdi에 있던 값을 넣어주기
	pop		rsi				; 원래 rsi에 있던 값을 넣어주기
	ret

