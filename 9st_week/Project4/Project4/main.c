#include<stdio.h>


void add_by_pointer(int* pa, int* pb, int* pr);	


int main(void)
{
	int a = 10, b = 20, res = 0;
	add_by_pointer(&a, &b, &res);		//30�� ����� ���Ͽ� �� ������ �����ִ� �Լ� ȣ��
	printf("%d", res);
	return 0;
}

void add_by_pointer(int* pa, int* pb, int* pr)
{
	*pr = *pa + *pb;		//������ �ּҸ� �����ͷ� �޾ƿ� �����ش�.
}
