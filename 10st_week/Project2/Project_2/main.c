#include <stdio.h>
#pragma warning(disable:4996) // C4996 ������ ����

typedef struct
{						//����ü book������ ������, book�� ����ü ����
	char title[80];		//����
	char author[80];	//����
	int page;			//������
	int price;			//����
} book;

void input_data(book* pray);	//3���� å ������ �Է¹޴� �Լ�
void print_data(book* pray);	//3���� å ������ ����Ͽ� �����ϴ� �Լ�

int main(void)
{
	book list[3];		//��Ұ� 3���� ����ü �迭 list ����

	input_data(list);	//å ���� �Է�
	printf("sort three books.\n");	//å ���� ���
	print_data(list);

	return 0;
}



void input_data(book* pray)			//����ü �迭�� �����ͷ� ����
{
	for (int i = 0; i < 3; i++)		//3���� å ������ �ݺ��Ͽ� �Է¹���
	{
		printf("%dst book's title : ", i + 1);
		scanf("%s", pray->title);	//�����ڸ� ����Ͽ� �迭 ����� title�� ������
		printf("Author : ");
		scanf("%s", pray->author);
		printf("Page : ");
		scanf("%d", &pray->page);
		printf("Price : ");
		scanf("%d", &pray->price);
		pray++;						//ù��° �迭 ��� �Է� �� ���� �迭�� ���� pray ����
		printf("\n");
	}
	printf("\n");
}

void print_data(book* pray)
{
	for (int i = 0; i < 3; i++)		//3���� �Է¹��� å ������ �����
	{
		printf("%dst book : %s\t%s\t%d\t%d\n", i + 1, pray->title, pray->author, pray->page, pray->price);
		pray++;						//�����ڷ� �迭 ����� ����ü ������ �����Ͽ� ��� �� ����. 3�� �ݺ�
	}
}
