#include <stdio.h>
int main(void)
{
	double weight, height, bmi;						//몸무게, 키, bmi 실수형 동시 선언

	printf("몸무게(kg)와 키(cm) 입력 : ");			//몸무게와 키 입력 메세지 출력
	scanf_s("%lf%lf", &weight, &height);			//%lf로 실수형 몸무게와 키 입력, 변수 앞에 &로 지정

	height = height / 100;							//키 m단위 환산
	bmi = weight / (height * height);				//bmi 계산식

	((bmi >= 20.0) && (bmi < 25.0))					//20이상 25미만의 두 범위 논리곱 연산자
		? printf("표준입니다.\n")					//? 두 범위가 모두 참일 때, 표준입니다 출력
		: printf("체중관리가 필요합니다.\n");		//: 두 범위 모두 중 하나라도 거짓일 때 체중관리가 필요합니다 출력

	return 0;
}