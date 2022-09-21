#include <stdio.h>
int main(void)
{
	char ch;													//문자열은 char형으로 변수 선언
	
	printf("문자 입력 : ");										//문자 입력 입력창 출력
	scanf_s("%c", &ch);											//%c로 문자 입력 및 &로 ch변수 지정
	printf("%c문자의 아스키 코드 값은 %d입니다.", ch, ch);		//%c는 문자 변수이고 아스키 코드는 정수이므로 %d, 각 값을 ch ch로 지정

	return 0;
}