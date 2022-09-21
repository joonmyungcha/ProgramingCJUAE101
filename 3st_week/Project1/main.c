#include <stdio.h>
int main(void)
{
	double weight, height, bmi;

	printf("put weight and height : ");
	scanf_s("%lf%lf", &weight, &height);

	height = height / 100;
	bmi = weight / (height * height);

	if (20.0 <= bmi < 25.0)
	{
		printf("표준입니다.\n");
	}
	else
	{
		printf("체중관리가 필요합니다.\n");
	}

	return 0;
}