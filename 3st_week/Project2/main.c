#include <stdio.h>
#define StandardAge 20													//기준나이 20으로 지정

int main(void)
{
	int age, chestsize;													//나이, 가슴둘레 정수형 변수 선언
	char size;															//사이즈 문자형 변수 선언
	int Maxchestsize, Minchestsize;										//기준 될 두 사이즈 정수형 선언

	printf("Input your age and chestsize : \n");						//나이, 가슴둘레 입력창 출력
	scanf_s("%d%d", &age, &chestsize);									//나이, 가슴둘레 입력

	if (age < StandardAge)												//기준 나이보다 적을 때 기준이 될 두 사이즈 값 초기화
	{
		Minchestsize = 85;
		Maxchestsize = 95;
	}
	else if(age >= StandardAge)											//기준 나이보다 많거나 같을 때의 새로운 기준이 될 두 사이즈 값 초기화
	{
		Minchestsize = 90;
		Maxchestsize = 100;
	}

	if (chestsize < Minchestsize)										//위 함수값을 이어받아 if, else if 사용
	{
		size = 'S';														//가슴둘레 Minchestsize 미만일 때 size변수에 S 대입
	}
	else if ((chestsize >= Minchestsize) && (chestsize < Maxchestsize))
	{
		size = 'M';														/*가슴둘레 Minchestsize 보다 크거나 같고 Maxchestsize 보다 작은 조건 중
																		두 조건 모두 참일 시 size 변수에 M 대입*/
	}
	else if (chestsize >= Maxchestsize)
	{
		size = 'L';														//가슴둘레 Maxchestsize 보다 크거나 같을 때 size변수에 L 대입
	}

	printf("your size is %c.\n", size);									//사이즈 출력

	return 0;
}

