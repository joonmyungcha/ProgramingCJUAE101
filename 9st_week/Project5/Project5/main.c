#include<stdio.h>

void input_data(int* pa, int* pb);
void swap_data(void);
void print_data(int a, int b);

int a, b;

int main(void)
{
	input_data(&a, &b);					//두 정수 변수의 주소를 포인터로 함수에 대입함. 함수 호출
	swap_data();
	print_data(a, b);

	return 0;
}

void input_data(int* pa, int* pb)		//두 정수를 입력받는 함수, 정수 변수의 주소를 포인터로 불러옴
{
	printf("Input two integers: ");
	scanf_s("%d%d", pa, pb);
}

void swap_data(void)					//입력받은 두 정수의 위치를 바꿔주었습니다.
{
	int temp;

	temp = a;
	a = b;
	b = temp;
}

void print_data(int a, int b)			//위치를 바꾼 두 정수 출력 함수
{
	printf("Swap two inegers : %d, %d", a, b);
}
