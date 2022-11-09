#include <stdio.h>
#include <string.h>

#pragma warning(disable:4996)		//C4996 에러를 무시

#define Max_str_Len 80				//배열의 최대 크기 지정

int main(void)
{
	char str[Max_str_Len];		//배열 선언
	strcpy(str, "wine");		//"wine" 을 배열 str에 대입
	strcat(str, "apple");		//"apple"을 wine 뒤에 붙여넣음
	strncpy(str, "pear", 1);	//"pear"에서 첫번째 문자 하나만 str에서 바꿔줌
	str[10] = '\0';				//문자 배열의 마지막에 널 문자 대입
	printf("%s, %d\n", str, (int)(strlen(str)));	//배열 str 출력 후 str 배열의 길이를 강제형변환 하여 %d 정수로 출력

	return 0;
}