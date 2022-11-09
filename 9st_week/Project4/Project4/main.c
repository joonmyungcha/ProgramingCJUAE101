#include<stdio.h>


void add_by_pointer(int* pa, int* pb, int* pr);	


int main(void)
{
	int a = 10, b = 20, res = 0;
	add_by_pointer(&a, &b, &res);		//30을 만들기 위하여 두 정수를 더해주는 함수 호출
	printf("%d", res);
	return 0;
}

void add_by_pointer(int* pa, int* pb, int* pr)
{
	*pr = *pa + *pb;		//정수의 주소를 포인터로 받아와 더해준다.
}
