#include <stdio.h>
#define Min_num 1												//구구단의 곱셈 최소, 최대 숫자 지정
#define Max_num 9

int main(void)
{
	int i, j;													//곱할 두 숫자 변수 선언
	printf("Input number of Mulltiplication Table : ");			//단수 입력창 출력 및 단수 입력
	scanf_s("%d", &i);											

	for (j = Min_num; j <= Max_num; j++)						//출력문 9번 반복, 반복 제어 변수 j
	{
		printf("%d * %d = %d\n", i, j, i * j);					//입력 단수에 1~9까지 변하면서 구구단 출력
	}

	return 0;
}