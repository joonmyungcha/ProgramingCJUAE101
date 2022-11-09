#include <stdio.h>
#include <string.h>

#define Max_str_Len 80				//배열의 최대 크기 지정
#define std_len	17					//문자의 6번째 부터 *로 표시하기 위한 상수 지정

#pragma warning(disable:4996) 

void input_word(char* input);		//단어 입력받는 함수
void put_star(char* input, char* output, char* star);	//6번째 문자부터 *로 생략하기 위한 함수


int main(void)
{
	char input_str[Max_str_Len];			//입력받는 배열 출력하는 배열, 별로 생략하기 위한 배열 선언
	char output_str[Max_str_Len];
	char star[Max_str_Len] = "*";
	
	printf("Input word : ");
	input_word(input_str);					//문자 입력 함수 호출
	put_star(input_str, output_str, star);	//*로 생략하기 위한 함수 호출
	printf("Input word : %s, Omitted word : %s", input_str, output_str);

	return 0;
}



void input_word(char* input)
{
	scanf("%s", input);
}

void put_star(char* input, char* output, char* star)		//함수 정의, 선언한 배열을 포인터로 불러옴
{
	int len;		//6번이라는 기준을 정하기 위해 임의의 정수 변수 선언
	len = (int)(strlen(input));			//len = 입력받은 문자의 길이

	if (len <= std_len)					//문자의 길이가 5보다 작거나 같을 때
	{
		strcpy(output, input);			//입력받은 문자 배열을 출력 문자 배열에 대입한다.
	}
	else//5보다 클 땐
	{
		strncpy(output, input, std_len);	//입력 문자 배열 중 5번째 까지만 출력 문자로 대입한 후
		output[std_len] = '\0';				//널문자로 문자를 종료해준다.
		for (int i = 0; i < len - std_len; i++)	//입력받은 문자의 크기에서 앞의 5개의 문자를 제외한 만큼 
		{
			strcat(output, star);		//5번째의 출력 문자 뒤에 *을 반복하여 대입해준다
		}

	}
}
