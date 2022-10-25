#include<stdio.h>
#define number 5
void print_ary(int *pa);

int main(void)
{
	int ary[number] = { 10, 20, 30, 40, 50 };

	print_ary(ary);

	return 0;

}

void print_ary(int *pa)
{
	int i;

	for (i = 0; i < number; i++)
	{
		printf("%d", pa[i]);
	}
}
