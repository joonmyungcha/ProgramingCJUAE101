#include <stdio.h>

int main(void)
{
	int A, B;															//입력할 두 정수 변수 선언
	char op;															//사칙연산 식 문자형 변수 선언
	int res;															//사칙연산 결과값 정수 변수 선언
	printf("Input your arithmetic operation.\n");						//사칙연산 입력착 출력
	scanf_s("%d%c%d", &A, &op, 1, &B);									//%d 정수, %c 문자, %d 사칙연산 입력/ 1은 입력 문자가 하나이므로

	if (op == '+')														//연산식 변수가 문자 +와 같을 때
	{
		res = A + B;													//결과값 A+B가 res에 대입
	}
	else if (op == '-')													//앞의 조건 외에 연산식 변수가 문자 -와 같을 때
	{
		res = A - B;
	}
	else if (op == '/')													//앞의 조건 외에 연산식 변수가 문자 /와 같을 때
	{
		res = A / B;
	}
	else if (op == '*')													//앞의 조건 외에 연산식 변수가 문자 *와 같을 때
	{
		res = A * B;
	}

	printf("%d%c%d=%d\n", A, op, B, res);								//사칙연산식 전체 출력

	return 0;
}