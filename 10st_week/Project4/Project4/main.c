#include <stdio.h>
#pragma warning(disable:4996) 

struct marriage			//marriage�� ����ü ����
{
	char name[20];		//�̸�
	int age;			//����
	char sex;			//����
	double height;		//Ű
};

int main(void)
{
	struct marriage m1 = { "Andy", 22, 'm', 187.5 };		//����ü ���� ���� �� �ʱ�ȭ
	struct marriage* mp = &m1;		//����ü ������ �ּҸ� ������ mp�� ����

	printf("name : %s\n", mp->name);		//����ü ������ name ��ҿ� �����Ͽ� ���
	printf("age : %d\n", mp->age);
	printf("sex : %c\n", mp->sex);
	printf("height : %.1lf\n", mp->height);
	

	return 0;
}
