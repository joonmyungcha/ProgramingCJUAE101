#include <stdio.h>
#include <stdlib.h>					//malloc, free �Լ� ����� ���� �������
				
#define remove_first 1				//�ڱ� �ڽ��� �����ϱ� ���� ��� 
#define remove_comparison 2			//�� ȸ���� �Է� ������ �������� 1ȸ �����Ƿ� 2
#define start_num 2					//1�� �����ϰ� 2���� ������
#define next_num 1					//���� �迭�� �ε����� ���ϱ� ���� 1
#define MaxCol 5					//5���� ������ �����ϰ� ���� �ٷ� �Ѿ
#define remove_own 2

void sort_ary(int num, int* pray);	//2���� �Է� ���ڱ��� �迭�� ������� �����ϴ� �Լ�
void compare(int num, int* pray);	//�迭�� �հ� ���� ���ڵ��� �������� 0�� �Ǹ� �� ���ڸ� 0���� �ٲ��ִ� �Լ�
void print_ary(int num, int* pray);	//2���� �Է� ����-1 ���� �Ҽ��� ����ϴ� �Լ�

int main(void)
{
	int i, j;						//�ݺ� ���� ����
	int Max_num;					//�Է¹��� ���� ����
	int* pi;						//���� �Ҵ� ������ ������ ������

	printf("Input an integer greater than or equal to 2 : ");			//�ִ� ����� �Է¹���
	scanf_s("%d", &Max_num);

	pi = (int*)malloc((Max_num - remove_first) * sizeof(int));		//1�� �����ϹǷ� �Է��� ��-1 ������ �迭 ����

	if(pi==NULL)										//�޸� ���� �� ���� ó�� ����
	{
		printf("ERROR. \n");
		exit(1);
	}

	sort_ary(Max_num, pi);			//�Լ� ȣ��
	compare(Max_num, pi);
	print_ary(Max_num, pi);
	
	free(pi);													//�Ҵ��� �޸� ���� ��ȯ

	return 0;
}




void compare(int num, int* pray)
{								
	int i = 0;									//�迭�� �ٽ� �����ϱ� ���� �ݺ����� �ʱ�ȭ
	while (1)									//�迭�� ���� ���ڰ� ���� ���ڷ� ������ �� ���� ���ڸ� 0���� �������
	{
		while ((pray[i] == 0) && (i < (num - remove_comparison)))	//�� Ƚ���� �������� ���� ��
		{															//0���� �� ���ڷδ� ������ �ʰ� �ݺ������� �������� ���� ������� �Ѿ
			i++;
		}
		if (i == (num - remove_comparison)) break;			//������ ���ڴ� ������ �񱳸� ���� ����
		//�� Ƚ���� �������� �� �ݺ��� Ż��
		for (int j = i + next_num; j < (num - remove_first); j++)	//i��° �迭�� ���� ��� �ε��� ���ڵ�� �������ִ� �ݺ���
		{
			if (pray[j] % pray[i] == 0)								//�迭�� ���� ���ڰ� ���� ���ڷ� ������ �� 
			{
				pray[j] = 0;										//���� ���ڸ� 0���� �������
			}

		}i++;													//i�� ��� ������ �������� ���ڸ� 0���� �ٲ��ְ�,
	}															//�����Ͽ� i + 1�� ���� ���ڵ�� �ٽ� ������. while�� �ݺ�

}

void sort_ary(int num, int* pray)
{
	for (int i = 0; i < (num - remove_first); i++)//1�� �ڱ� �ڽ��� ������ ���ڷ� ������ �ϹǷ� 
	{											//2���� �����Ͽ� �Է��� ������ �迭�� ��������
		pray[i] = i + start_num;					//�ִ� �Է� ���� 10�� �� 2,3,4,5,6,7,8,9,10 ������ �ε����� ����
	}
}

void print_ary(int num, int* pray)
{
	for (int i = 0; i < (num - remove_own); i++)				//�տ��� ������ �迭�� ������ ó������ �Է��� ��-1���� ����
	{
		if (pray[i] != 0)											//0�� ���� ���� ���ڵ��� �״�� ���
		{
			printf("%d\t", pray[i]);
		}
		else if (pray[i] == 0)									//���������� 0�� �� ���ڵ��� X�� ���
		{
			printf("%c\t", 'X');
		}
		if ((i + 1) % MaxCol == 0)								//5���� ���� ��� �� �� �ٲ�
		{
			printf("\n");
		}
	}
}
