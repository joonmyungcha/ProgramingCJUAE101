#include<stdio.h>
#define Minchestsize 90													//Minchestsize 90���� ����
#define Maxchestsize 100												//Maxchestsize 100���� ����
int main(void)
{
	int chestsize;														//�����ѷ� �����ڷ��� ���� ����
	char size;															//���ڿ� char������ ���� ����
	
	printf("Input your chest size : \n");								//�����ѷ� �Է�â ���
	scanf_s("#d", &chestsize);											//�����ѷ� �Է�
																		
	if (chestsize <= Minchestsize)										//if, else if, else if�� ���
	{
		size = 'S';														//�����ѷ� Minchestsize ������ �� size������ S ����
	}
	else if ((chestsize > Minchestsize) && (chestsize <= Maxchestsize))	
	{
		size = 'M';														/*�����ѷ� Minchestsize ���� ũ�� Maxchestsize ���� ���� ���� ��
																		�� ���� ��� ���� �� size ������ M ����*/
	}
	else if (chestsize > Maxchestsize)
	{
		size = 'L';														//�����ѷ� Maxchestsize ���� Ŭ �� size������ L ����
	}
	
	printf("size : %c\n", size);										//���ڴ� %c�� ���

	return 0;
}