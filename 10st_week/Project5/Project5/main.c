#include<stdio.h>
#include<stdlib.h>

#define repeat_num 5

typedef struct train Train;

struct train 
{
	int seats;
	struct train* next;		//���� ������ ������ ������,����ü �ڽ��� ����Ű�� ������ ���
};

int main(void)
{
	Train* head = NULL, * tail = NULL;		//����ü ���� NULL�� �ʱ�ȭ
	int i;									//�ݺ� ���� ����
	for (i = 0; i < repeat_num; i++)					//5�� �ݺ�
	{
		if (head == NULL)					//ó�� ��尡 NULL�� �ʱ�ȭ �Ǿ������Ƿ� 
		{
			head = tail = (Train*)malloc(sizeof(Train));	//tail�� ����ü ���� �޸� seats�� next�� �Ҵ����ְ� head�� ����
		}
		else												//�ι�° �ݺ�Ƚ������ head�� ���Ե� tail ����ü ������ next ��ҿ� ���� �޸� seats�� next �Ҵ� �� 
		{
			tail->next = (Train*)malloc(sizeof(Train));		
			tail = tail->next;								//��������
		}
	}

	printf("head ->");										//��� ���
		for (int i = 0; i < repeat_num ; i++)
		{
			printf("- seats / next -");
			

		}
		printf(" <- tail");

	return 0;
}