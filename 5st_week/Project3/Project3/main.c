#include <stdio.h>

int sum(int A, int B);											//sum, sub, mul, div , rem 함수 선언
int sub(int A, int B);
int mul(int A, int B);
int div(int A, int B);
int rem(int A, int B);

int main(void)													//4st_week project3 이용
{
	int A, B;
	char op;
	int res;
	printf("Input your arithmetic operation.\n");
	scanf_s("%d%c%d", &A, &op, 1, &B);

	switch (op)													
	{
	case'+':													
		res = sum(A, B);										//sum, sub, mul, div, rem 함수 호출
		break;
	case'-':													
		res = sub(A, B);
		break;
	case'*':													
		res = mul(A, B);
		break;
	case'/':													
		res = div(A, B);
		break;
	case'%':													
		res = rem(A, B);
		break;
	}
	printf("%d%c%d=%d\n", A, op, B, res);						

	return 0;
}

int sum(int A, int B)											//sum, sub, mul, div , rem 함수 정의 시작
{
	int temp;													//두 정수의 계산값 저장할 변수
	
	temp = A + B;												
	
	return temp;												//temp 값을 반환
}
int sub(int A, int B)
{
	int temp;
	
	temp = A - B;
	
	return temp;
}
int mul(int A, int B)
{
	int temp;

	temp = A * B;
	
	return temp;
}
int div(int A, int B)
{
	int temp;
	
	temp = A / B;
	
	return temp;
}
int rem(int A, int B)
{
	int temp;

	temp = A % B;

	return temp;
}





