#include<stdio.h>
#define Minchestsize 90													//Minchestsize 90으로 지정
#define Maxchestsize 100												//Maxchestsize 100으로 지정
int main(void)
{
	int chestsize;														//가슴둘레 정수자료형 변수 선언
	char size;															//문자열 char형으로 변수 선언
	
	printf("Input your chest size : \n");								//가슴둘레 입력창 출력
	scanf_s("#d", &chestsize);											//가슴둘레 입력
																		
	if (chestsize <= Minchestsize)										//if, else if, else if절 사용
	{
		size = 'S';														//가슴둘레 Minchestsize 이하일 때 size변수에 S 대입
	}
	else if ((chestsize > Minchestsize) && (chestsize <= Maxchestsize))	
	{
		size = 'M';														/*가슴둘레 Minchestsize 보다 크고 Maxchestsize 보다 작은 조건 중
																		두 조건 모두 참일 시 size 변수에 M 대입*/
	}
	else if (chestsize > Maxchestsize)
	{
		size = 'L';														//가슴둘레 Maxchestsize 보다 클 때 size변수에 L 대입
	}
	
	printf("size : %c\n", size);										//문자는 %c로 출력

	return 0;
}