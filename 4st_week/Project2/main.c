#include <stdio.h>
#define StandardAge 20													//���س��� 20���� ����

int main(void)
{
	int age, chestsize;													//����, �����ѷ� ������ ���� ����
	char size;															//������ ������ ���� ����
	int Maxchestsize, Minchestsize;										//���� �� �� ������ ������ ����

	printf("Input your age and chestsize : \n");						//����, �����ѷ� �Է�â ���
	scanf_s("%d%d", &age, &chestsize);									//����, �����ѷ� �Է�

	if (age < StandardAge)												//���� ���̺��� ���� �� ������ �� �� ������ �� �ʱ�ȭ
	{
		Minchestsize = 85;
		Maxchestsize = 95;
	}
	else if(age >= StandardAge)											//���� ���̺��� ���ų� ���� ���� ���ο� ������ �� �� ������ �� �ʱ�ȭ
	{
		Minchestsize = 90;
		Maxchestsize = 100;
	}

	if (chestsize < Minchestsize)										//�� �Լ����� �̾�޾� if, else if ���
	{
		size = 'S';														//�����ѷ� Minchestsize �̸��� �� size������ S ����
	}
	else if ((chestsize >= Minchestsize) && (chestsize < Maxchestsize))
	{
		size = 'M';														/*�����ѷ� Minchestsize ���� ũ�ų� ���� Maxchestsize ���� ���� ���� ��
																		�� ���� ��� ���� �� size ������ M ����*/
	}
	else if (chestsize >= Maxchestsize)
	{
		size = 'L';														//�����ѷ� Maxchestsize ���� ũ�ų� ���� �� size������ L ����
	}

	printf("your size is %c.\n", size);									//������ ���

	return 0;
}

