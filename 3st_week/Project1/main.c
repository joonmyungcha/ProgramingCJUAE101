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
		printf("ǥ���Դϴ�.\n");
	}
	else
	{
		printf("ü�߰����� �ʿ��մϴ�.\n");
	}

	return 0;
}