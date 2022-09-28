#include <stdio.h>

int main(void)
{
	int A, B;
	char op;
	int res;
	printf("Input your arithmetic operation.\n");
	scanf_s("%d%c%d", &A, &op, 1, &B);

	if (op == '+')
	{
		res = A + B;
	}
	else if (op == '-')
	{
		res = A - B;
	}
	else if (op == '/')
	{
		res = A / B;
	}
	else if (op == '*')
	{
		res = A * B;
	}

	printf("%d%c%d=%d\n", A, op, B, res);

	return 0;
}