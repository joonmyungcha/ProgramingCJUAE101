#include<stdio.h>

void input_data(int* pa, int* pb);
void swap_data(void);
void print_data(int a, int b);

int a, b;

int main(void)
{
	input_data(&a, &b);					//�� ���� ������ �ּҸ� �����ͷ� �Լ��� ������. �Լ� ȣ��
	swap_data();
	print_data(a, b);

	return 0;
}

void input_data(int* pa, int* pb)		//�� ������ �Է¹޴� �Լ�, ���� ������ �ּҸ� �����ͷ� �ҷ���
{
	printf("Input two integers: ");
	scanf_s("%d%d", pa, pb);
}

void swap_data(void)					//�Է¹��� �� ������ ��ġ�� �ٲ��־����ϴ�.
{
	int temp;

	temp = a;
	a = b;
	b = temp;
}

void print_data(int a, int b)			//��ġ�� �ٲ� �� ���� ��� �Լ�
{
	printf("Swap two inegers : %d, %d", a, b);
}
