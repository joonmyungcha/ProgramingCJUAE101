#include <stdio.h>
#define Min_num 1												//�������� ���� �ּ�, �ִ� ���� ����
#define Max_num 9

int main(void)
{
	int i, j;													//���� �� ���� ���� ����
	printf("Input number of Mulltiplication Table : ");			//�ܼ� �Է�â ��� �� �ܼ� �Է�
	scanf_s("%d", &i);											

	for (j = Min_num; j <= Max_num; j++)						//��¹� 9�� �ݺ�, �ݺ� ���� ���� j
	{
		printf("%d * %d = %d\n", i, j, i * j);					//�Է� �ܼ��� 1~9���� ���ϸ鼭 ������ ���
	}

	return 0;
}