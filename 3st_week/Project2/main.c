#include <stdio.h>
#define StandardAge 20

int main(void)
{
	int age, chestsize;
	char size;
	int Maxchestsize, Minchestsize;

	printf("Input your age and chestsize : \n");
	scanf_s("%d%d", &age, &chestsize);

	if (age < StandardAge)
	{
		Minchestsize = 85;기준
		Maxchestsize = 95;
	}
	else if(age >= StandardAge)
	{
		Minchestsize = 90;
		Maxchestsize = 100;
	}

	if (chestsize < Minchestsize)										//if, else if, else if절 사용
	{
		size = 'S';														//가슴둘레 Minchestsize 이하일 때 size변수에 S 대입
	}
	else if ((chestsize >= Minchestsize) && (chestsize < Maxchestsize))
	{
		size = 'M';														/*가슴둘레 Minchestsize 보다 크고 Maxchestsize 보다 작은 조건 중
																		두 조건 모두 참일 시 size 변수에 M 대입*/
	}
	else if (chestsize >= Maxchestsize)
	{
		size = 'L';														//가슴둘레 Maxchestsize 보다 클 때 size변수에 L 대입
	}

	printf("your size is %c.\n", size);

	return 0;
}

