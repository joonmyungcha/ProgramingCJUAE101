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
		Minchestsize = 85;����
		Maxchestsize = 95;
	}
	else if(age >= StandardAge)
	{
		Minchestsize = 90;
		Maxchestsize = 100;
	}

	if (chestsize < Minchestsize)										//if, else if, else if�� ���
	{
		size = 'S';														//�����ѷ� Minchestsize ������ �� size������ S ����
	}
	else if ((chestsize >= Minchestsize) && (chestsize < Maxchestsize))
	{
		size = 'M';														/*�����ѷ� Minchestsize ���� ũ�� Maxchestsize ���� ���� ���� ��
																		�� ���� ��� ���� �� size ������ M ����*/
	}
	else if (chestsize >= Maxchestsize)
	{
		size = 'L';														//�����ѷ� Maxchestsize ���� Ŭ �� size������ L ����
	}

	printf("your size is %c.\n", size);

	return 0;
}

