#include<stdio.h>
#include<string.h>

#define Max_str_Len 80									//배열의 최대 크기 지정

#pragma warning(disable:4996)							// C4996 에러를 무시

void input_words(char* str1, char* str2, char* str3);	//세 문자 입력 받는 함수
void swap(char* str1, char* str2, char* str3);			//세 문자 사전 순서대로 바꿔주는 함수

int main(void)
{
	char str1[Max_str_Len];								//입력받을 세 문자 배열 선언
	char str2[Max_str_Len];
	char str3[Max_str_Len];

	printf("Input three words : ");	
	input_words(str1, str2, str3);						//문자 세개를 입력받는다.
	swap(str1, str2, str3);								//입력 받은 세 문자를 사전 순서대로 바꿔주는 함수 호출
	printf("%s, %s, %s", str1, str2, str3);				//순서를 바꿔준 세 문자를 출력한다.

	return 0;
}



void input_words(char* str1, char* str2, char* str3)
{
	scanf("%s%s%s", str1, str2, str3);
}


void swap(char* str1, char* str2, char* str3)		//함수 정의, 입력받은 세 문자의 순서를 사전에서 먼저 나오는 순으로 바꿔준다.
{
	char temp[Max_str_Len];							//임의의 배열 변수 선언

	if (strcmp(str1, str2) > 0)						//str1이 사전 순서에서 str2보다 나중에 오면
	{
		strcpy(temp, str1);							//str2를 str1에 대입
		strcpy(str1, str2);
		strcpy(str2, temp);
	}
	if (strcmp(str1, str3) > 0)						//str1이 str3보다 나중에 오면
	{
		strcpy(temp, str1);							//str3을 str1에 대입
		strcpy(str1, str3);
		strcpy(str3, temp);
	}
	if (strcmp(str2, str3) > 0)						//str2가 str3보다 나중에 오면
	{
		strcpy(temp, str2);							//str3를 str2에 대입
		strcpy(str2, str3);
		strcpy(str3, temp);
	}
}