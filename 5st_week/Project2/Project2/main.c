#include <stdio.h>
#define MinNum 2															//2이상의 정수를 입력해야 하므로 2를 최소 정수로 지정
#define MaxCol 5															//한줄에 최대 5칸이므로 5를 최대 칸수로 지정

int main(void)
{
	int i, j;																//반복 횟수를 세기 위한 제어 변수
	int num;																//입력 정수 변수 선언
	int pn;																	//소수 변수 선언
	int cnt = 0;															//한줄 칸 수를 세기 위한 제어 변수
	printf("Input an integer greater than or equal to 2 : ");				//정수 입력창 출력 및 정수 입력
	scanf_s("%d", &num);
	for (i = MinNum; i <= num; i++)											//i가 2부터 입력 정수값 까지 증가하면서 반복
	{																		
		pn = 1;																//정수 입력시 모든 정수에서 pn에 1을 대입하지만, 
																			//자기자신보다 작은 숫자들로 나머지 연산 시 0이 나오면 가정취소
		for (j = MinNum; j < i; j++)										//중첩 반복문 적용, j가 2부터 i보다 1 작은 숫자까지 반복
		{																	
			if ((i % j) == 0)												//소수는 약수가 1과 자기자신 뿐이므로, 1이나 자기자신으로 나누었을 때만 나머지 0
			{																//자기 자신보다 낮은 숫자들로 나머지 연산 시 0이 나오면 0을 pn에 대입
				pn = 0;														//가정 취소
				break;
			}

		}
		if (pn == 1)														//pn이 1일 때(소수일 때)
		{
			printf("%5d", i);												//5개의 칸을 만들어 놓고 오른쪽으로 정렬하며 반복되는 i(소수일 경우만) 출력
			cnt++;															//칸 수 변수 0부터 증가연산
			if ((cnt % MaxCol) == 0)										//칸 수 변수를 최대 칸수 5로 나누었을 때 나머지가 0이면
			{
				printf("\n");												//한 줄 띄움
			}
		}
	}
	
	return 0;
}