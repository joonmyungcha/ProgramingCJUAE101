#include<stdio.h>
#pragma warning(disable:4996) 

typedef struct
{							//구조체 cracker형으로 재정의, cracker형 구조체 선언
	int price;
	int calories;
} cracker;

int main(void)
{
	cracker basasak;		//구조체 변수 선언
	printf("Input price and calories of basasak : ");
	scanf("%d%d", &basasak.price, &basasak.calories);		//구조체 변수의 요소에 정보 입력
	printf("price of basasak : %dwon\n", basasak.price);	//정보 출력
	printf("calories of basasak : %dkcal\n", basasak.calories);	

	return 0;
}