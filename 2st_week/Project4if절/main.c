#include <stdio.h>
int main(void)
{
	double weight, height, bmi;

	printf("몸무게(kg)와 키(cm) 입력 : ");
	scanf_s("%lf%lf", &weight, &height);

	height = height / 100;
	bmi = weight / (height * height);

	if (20.0 <= bmi < 25.0)						//if~else절을 사용하여 bmi의 범위를 정해줌.
	{
		printf("표준입니다.\n");				//bmi가 범위 안의 값을 때 표준입니다 출력 후 줄바꿈
	}
	else
	{
		printf("체중관리가 필요합니다.\n");		//bmi가 범위 안의 값이 아닐 때 체중관리가 필요합니다 출력 후 줄바꿈
	}

	return 0;
}