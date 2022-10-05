#include <stdio.h>


int main(void)
{
	int i, j;
	printf("Input Mulltiplication Table number : ");
	scanf_s("%d", &i);

	for (j = 1; j <= 9; j++)
	{
		printf("%d * %d = %d\n", i, j, i * j);
	}

	return 0;
}