#include <stdio.h>
#include <stdlib.h>					//malloc, free 함수 사용을 위한 헤더파일
				
#define remove_first 1				//자기 자신을 제외하기 위한 상수 
#define remove_comparison 2			//비교 회수는 입력 숫자의 갯수보다 1회 적으므로 2
#define start_num 2					//1을 제외하고 2부터 시작함
#define next_num 1					//다음 배열의 인덱스와 비교하기 위한 1
#define MaxCol 5					//5개의 정수를 나열하고 다음 줄로 넘어감
#define remove_own 2

void sort_ary(int num, int* pray);	//2부터 입력 숫자까지 배열을 순서대로 정렬하는 함수
void compare(int num, int* pray);	//배열의 앞과 뒤의 숫자들의 나눗셈이 0이 되면 그 숫자를 0으로 바꿔주는 함수
void print_ary(int num, int* pray);	//2부터 입력 숫자-1 까지 소수만 출력하는 함수

int main(void)
{
	int i, j;						//반복 변수 선언
	int Max_num;					//입력받을 변수 선언
	int* pi;						//동적 할당 영역을 연결할 포인터

	printf("Input an integer greater than or equal to 2 : ");			//최대 양수를 입력받음
	scanf_s("%d", &Max_num);

	pi = (int*)malloc((Max_num - remove_first) * sizeof(int));		//1을 제외하므로 입력한 수-1 개수의 배열 선언

	if(pi==NULL)										//메모리 부족 시 예외 처리 구문
	{
		printf("ERROR. \n");
		exit(1);
	}

	sort_ary(Max_num, pi);			//함수 호출
	compare(Max_num, pi);
	print_ary(Max_num, pi);
	
	free(pi);													//할당한 메모리 영역 반환

	return 0;
}




void compare(int num, int* pray)
{								
	int i = 0;									//배열을 다시 나열하기 위해 반복변수 초기화
	while (1)									//배열의 뒤의 숫자가 앞의 숫자로 나눠질 때 뒤의 숫자를 0으로 만들어줌
	{
		while ((pray[i] == 0) && (i < (num - remove_comparison)))	//비교 횟수를 만족하지 않을 때
		{															//0으로 된 숫자로는 나누지 않고 반복변수를 증가시켜 다음 나누기로 넘어감
			i++;
		}
		if (i == (num - remove_comparison)) break;			//마지막 숫자는 나누기 비교를 하지 않음
		//비교 횟수를 만족했을 때 반복문 탈출
		for (int j = i + next_num; j < (num - remove_first); j++)	//i번째 배열을 뒤의 모든 인덱스 숫자들로 나누어주는 반복문
		{
			if (pray[j] % pray[i] == 0)								//배열의 뒤의 숫자가 앞의 숫자로 나눠질 때 
			{
				pray[j] = 0;										//뒤의 숫자를 0으로 만들어줌
			}

		}i++;													//i로 모두 나누어 나눠지는 숫자를 0으로 바꿔주고,
	}															//증가하여 i + 1로 뒤의 숫자들과 다시 나눠줌. while문 반복

}

void sort_ary(int num, int* pray)
{
	for (int i = 0; i < (num - remove_first); i++)//1과 자기 자신을 제외한 숫자로 나눠야 하므로 
	{											//2부터 시작하여 입력한 수까지 배열에 대입해줌
		pray[i] = i + start_num;					//최대 입력 숫자 10일 시 2,3,4,5,6,7,8,9,10 각각의 인덱스에 대입
	}
}

void print_ary(int num, int* pray)
{
	for (int i = 0; i < (num - remove_own); i++)				//앞에서 정해진 배열의 값들을 처음부터 입력한 수-1까지 나열
	{
		if (pray[i] != 0)											//0이 되지 않은 숫자들은 그대로 출력
		{
			printf("%d\t", pray[i]);
		}
		else if (pray[i] == 0)									//나누어져서 0이 된 숫자들은 X로 출력
		{
			printf("%c\t", 'X');
		}
		if ((i + 1) % MaxCol == 0)								//5개의 정수 출력 후 줄 바꿈
		{
			printf("\n");
		}
	}
}
