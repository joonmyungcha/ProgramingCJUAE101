#include <stdio.h>

#define Length 4	//��й�ȣ ���� ����
#define STOP 6		//5�� Ʋ���� �����ϱ� ���� ��� ����							
#define first_input_Stop 1	//ù��° Ʋ���� Ȯ���ϱ� ���� ��� ����
#define End_sys 1
void input_PW(int* num, int size);	//��й�ȣ�� �Է¹ޱ� ���� �Լ�
int print_PW(int* num, int size);	//�Է¹��� ��й�ȣ ����ϱ� ���� �Լ�
int input(int* num, int size);		//�Է� ���ڸ� �迭�� �� �ε������� �ֱ� ���� �Լ�
int answer(int* num, int size);		//���� ���ڸ� �迭�� �� �ε������� �ֱ� ���� �Լ�

int main(void)
{
	int answer_pw[Length] = { 0, 5, 1, 3 };		//���� �迭 ary[0]~ary[3]���� ������ ���� �� �� �ʱ�ȭ
	int input_pw[Length];		//�Է��ϴ� �迭 ����
	int k = first_input_Stop;	//������ Ʋ���� �� �Լ� ���Ḧ ���� ���� ���� �� �ʱ�ȭ
	int input_run = 0;			//�Է»�Ȳ ����ó��
	printf("Input 1 to run. If you put another character, this system will end.\n");		//�Է»�Ȳ ����ó��
	scanf_s("%d", &input_run);																//�Է»�Ȳ ����ó�� ���� �Է�
	
	if (input_run == End_sys)
	{
		while (1)
		{
			input_PW(input_pw, Length);		//��й�ȣ �Է� �Լ� ȣ��
			print_PW(input_pw, Length);		//�Է� ��й�ȣ ��� �Լ� ȣ��

			if (input(input_pw, Length) == answer(answer_pw, Length))		//�Է¹迭�� ����迭�� �� �ε��� ���� ���� ��
			{
				printf("normal termination");	//�����Դϴ� ��� �� while�� �������ͼ� main�Լ� ����
				break;
			}

			else if (input(input_PW, Length) != answer(answer_pw, Length))	//�� �ε��� ���� �ٸ� ��
			{
				printf("%d times wrong\n", k);
				k++;	//k�� 1���� 1�� �����ϸ鼭 ����Ƚ�� ���
				if (k == STOP)	//5�� Ʋ���� �� ���� ���� ��� �� while�� �������� ��й�ȣ �Է� �ý��� ����
				{
					printf("stop password system");
					break;
				}
			}
		}
	}
	else
	{
		printf("End system.");
	}

	return 0;
}



void input_PW(int* num, int size)		//�Լ� ����
{
	for (int i = 0; i < size; i++)		//�ݺ����� ���Ͽ� �Է� ��й�ȣ �迭�� 0�� �迭���� 3�� �迭���� �� �ε����� ���� �Է�
	{
		printf("input %dth password ", i);
		scanf_s("%d", &num[i]);
	}
}

int print_PW(int* num, int size)		//�ݺ����� ���Ͽ� �Է¹��� �迭�� �� �ε��� ���� ���
{
	int res[Length] = { 0 };
	for (int i = 0; i < size; i++)
	{
		res[i] = num[i];

		printf("%dth num = %d \t", i, num[i]);
	}
	printf("\n");
	return *res;		//res �迭�� ��ȯ
}

int input(int* num, int size)		//�Է¹��� �迭�� 0���迭~3���迭������ �� �ε��� �񱳸� ���� �ϳ��ϳ��� ����
{
	int res1[Length] = { 0 };		
	for (int i = 0; i < size; i++)	//0~3 �迭���� �ݺ��Ͽ� �� ����
	{
		res1[i] = num[i];
		return *res1;				//res1�� ��ȯ
	}
}


int answer(int* num, int size)		//���� �迭�� �� �ε��� ���� �Է¹迭�� �� �ε����� ���ϱ� ���� �ϳ��ϳ��� ����
{
	int res2[Length] = { 0 };		
	for (int i = 0; i < size; i++)
	{
		res2[i] = num[i];
		return *res2;
	}
}
