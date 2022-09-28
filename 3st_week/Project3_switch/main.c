#include <stdio.h>

int main(void)
{
	int A, B;
	char op;
	int res;
	printf("Input your arithmetic operation.\n");
	scanf_s("%d%c%d", &A, &op, 1, &B);

	switch (op)
	{
	case'+':
		res = A + B;
		break;
	case'-':
		res = A - B;
		break;
	case'*':
		res = A * B;
		break;
	case'/':
		res = A / B;
		break;
	}
	printf("%d%c%d=%d\n", A, op, B, res);

	return 0;
}