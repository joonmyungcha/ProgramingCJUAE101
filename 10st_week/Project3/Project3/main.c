#include<stdio.h>
#pragma warning(disable:4996) 

typedef struct
{							//����ü cracker������ ������, cracker�� ����ü ����
	int price;
	int calories;
} cracker;

int main(void)
{
	cracker basasak;		//����ü ���� ����
	printf("Input price and calories of basasak : ");
	scanf("%d%d", &basasak.price, &basasak.calories);		//����ü ������ ��ҿ� ���� �Է�
	printf("price of basasak : %dwon\n", basasak.price);	//���� ���
	printf("calories of basasak : %dkcal\n", basasak.calories);	

	return 0;
}