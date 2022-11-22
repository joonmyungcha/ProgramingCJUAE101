#include <stdio.h>
#pragma warning(disable:4996) 

struct marriage			//marriage형 구조체 선언
{
	char name[20];		//이름
	int age;			//나이
	char sex;			//성별
	double height;		//키
};

int main(void)
{
	struct marriage m1 = { "Andy", 22, 'm', 187.5 };		//구조체 변수 선언 및 초기화
	struct marriage* mp = &m1;		//구조체 변수의 주소를 포인터 mp에 연결

	printf("name : %s\n", mp->name);		//구조체 변수의 name 요소에 접근하여 출력
	printf("age : %d\n", mp->age);
	printf("sex : %c\n", mp->sex);
	printf("height : %.1lf\n", mp->height);
	

	return 0;
}
