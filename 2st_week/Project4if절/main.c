#include <stdio.h>
int main(void)
{
	double weight, height, bmi;

	printf("������(kg)�� Ű(cm) �Է� : ");
	scanf_s("%lf%lf", &weight, &height);

	height = height / 100;
	bmi = weight / (height * height);

	if (20.0 <= bmi < 25.0)						//if~else���� ����Ͽ� bmi�� ������ ������.
	{
		printf("ǥ���Դϴ�.\n");				//bmi�� ���� ���� ���� �� ǥ���Դϴ� ��� �� �ٹٲ�
	}
	else
	{
		printf("ü�߰����� �ʿ��մϴ�.\n");		//bmi�� ���� ���� ���� �ƴ� �� ü�߰����� �ʿ��մϴ� ��� �� �ٹٲ�
	}

	return 0;
}