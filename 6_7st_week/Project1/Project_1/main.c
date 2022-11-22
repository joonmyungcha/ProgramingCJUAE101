#include <stdio.h>

#define Length 4	//비밀번호 길이 지정
#define STOP 6		//5번 틀리면 종료하기 위한 상수 지정							
#define first_input_Stop 1	//첫번째 틀림을 확인하기 위한 상수 지정
#define End_sys 1
void input_PW(int* num, int size);	//비밀번호를 입력받기 위한 함수
int print_PW(int* num, int size);	//입력받은 비밀번호 출력하기 위한 함수
int input(int* num, int size);		//입력 숫자를 배열의 각 인덱스값에 넣기 위한 함수
int answer(int* num, int size);		//정답 숫자를 배열의 각 인덱스값에 넣기 위한 함수

int main(void)
{
	int answer_pw[Length] = { 0, 5, 1, 3 };		//정답 배열 ary[0]~ary[3]까지 정수형 선언 후 값 초기화
	int input_pw[Length];		//입력하는 배열 선언
	int k = first_input_Stop;	//여러번 틀렸을 때 함수 종료를 위한 정수 선언 및 초기화
	int input_run = 0;			//입력상황 예외처리
	printf("Input 1 to run. If you put another character, this system will end.\n");		//입력상황 예외처리
	scanf_s("%d", &input_run);																//입력상황 예외처리 정수 입력
	
	if (input_run == End_sys)
	{
		while (1)
		{
			input_PW(input_pw, Length);		//비밀번호 입력 함수 호출
			print_PW(input_pw, Length);		//입력 비밀번호 출력 함수 호출

			if (input(input_pw, Length) == answer(answer_pw, Length))		//입력배열과 정답배열의 각 인덱스 값이 같을 때
			{
				printf("normal termination");	//정답입니다 출력 후 while문 빠져나와서 main함수 종료
				break;
			}

			else if (input(input_PW, Length) != answer(answer_pw, Length))	//각 인덱스 값이 다를 때
			{
				printf("%d times wrong\n", k);
				k++;	//k값 1부터 1씩 증가하면서 오류횟수 출력
				if (k == STOP)	//5번 틀렸을 시 종료 문구 출력 후 while문 빠져나와 비밀번호 입력 시스템 종료
				{
					printf("stop password system");
					break;
				}
			}
		}
	}
	else
	{
		printf("End system.");
	}

	return 0;
}



void input_PW(int* num, int size)		//함수 정의
{
	for (int i = 0; i < size; i++)		//반복문을 통하여 입력 비밀번호 배열의 0번 배열부터 3번 배열까지 각 인덱스에 숫자 입력
	{
		printf("input %dth password ", i);
		scanf_s("%d", &num[i]);
	}
}

int print_PW(int* num, int size)		//반복문을 통하여 입력받은 배열의 각 인덱스 숫자 출력
{
	int res[Length] = { 0 };
	for (int i = 0; i < size; i++)
	{
		res[i] = num[i];

		printf("%dth num = %d \t", i, num[i]);
	}
	printf("\n");
	return *res;		//res 배열로 반환
}

int input(int* num, int size)		//입력받은 배열의 0번배열~3번배열까지의 각 인덱스 비교를 위해 하나하나씩 정렬
{
	int res1[Length] = { 0 };		
	for (int i = 0; i < size; i++)	//0~3 배열까지 반복하여 값 대입
	{
		res1[i] = num[i];
		return *res1;				//res1로 반환
	}
}


int answer(int* num, int size)		//정답 배열의 각 인덱스 값을 입력배열의 각 인덱스와 비교하기 위해 하나하나씩 정렬
{
	int res2[Length] = { 0 };		
	for (int i = 0; i < size; i++)
	{
		res2[i] = num[i];
		return *res2;
	}
}
