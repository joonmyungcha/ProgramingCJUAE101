#include<stdio.h>
#include<stdlib.h>

#define repeat_num 5

typedef struct train Train;

struct train 
{
	int seats;
	struct train* next;		//다음 객차를 연결할 포인터,구조체 자신을 가리키는 포인터 멤버
};

int main(void)
{
	Train* head = NULL, * tail = NULL;		//구조체 변수 NULL로 초기화
	int i;									//반복 변수 선언
	for (i = 0; i < repeat_num; i++)					//5번 반복
	{
		if (head == NULL)					//처음 헤드가 NULL로 초기화 되어있으므로 
		{
			head = tail = (Train*)malloc(sizeof(Train));	//tail에 구조체 동적 메모리 seats와 next를 할당해주고 head에 대입
		}
		else												//두번째 반복횟수부터 head에 대입된 tail 구조체 변수의 next 요소에 동적 메모리 seats와 next 할당 후 
		{
			tail->next = (Train*)malloc(sizeof(Train));		
			tail = tail->next;								//연결해줌
		}
	}

	printf("head ->");										//결과 출력
		for (int i = 0; i < repeat_num ; i++)
		{
			printf("- seats / next -");
			

		}
		printf(" <- tail");

	return 0;
}