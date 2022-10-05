#include <stdio.h>

int main(void)
{
	int A, B;															
	char op;
	int res;
	printf("Input your arithmetic operation.\n");
	scanf_s("%d%c%d", &A, &op, 1, &B);

	switch (op)													//switch절 사용, 변수 op가 무슨 문자인지 확인
	{
	case'+':													//문자 +일 때 다음 계산식의 결과값 res, break로 끝내줌 
		res = A + B;
		break;
	case'-':													//문자 -일 때
		res = A - B;
		break;
	case'*':													//문자 *일 때
		res = A * B;
		break;
	case'/':													//문자 / 일 때
		res = A / B;											
		break;
	}
	printf("%d%c%d=%d\n", A, op, B, res);						//사칙연산식 출력

	return 0;
}