#include <stdio.h>
#pragma warning(disable:4996) // C4996 에러를 무시

typedef struct
{						//구조체 book형으로 재정의, book형 구조체 선언
	char title[80];		//제목
	char author[80];	//저자
	int page;			//페이지
	int price;			//가격
} book;

void input_data(book* pray);	//3개의 책 정보를 입력받는 함수
void print_data(book* pray);	//3개의 책 정보를 출력하여 정렬하는 함수

int main(void)
{
	book list[3];		//요소가 3개인 구조체 배열 list 선언

	input_data(list);	//책 정보 입력
	printf("sort three books.\n");	//책 정보 출력
	print_data(list);

	return 0;
}



void input_data(book* pray)			//구조체 배열을 포인터로 접근
{
	for (int i = 0; i < 3; i++)		//3개의 책 정보를 반복하여 입력받음
	{
		printf("%dst book's title : ", i + 1);
		scanf("%s", pray->title);	//연산자를 사용하여 배열 요소의 title에 접근함
		printf("Author : ");
		scanf("%s", pray->author);
		printf("Page : ");
		scanf("%d", &pray->page);
		printf("Price : ");
		scanf("%d", &pray->price);
		pray++;						//첫번째 배열 모두 입력 시 다음 배열을 위한 pray 증가
		printf("\n");
	}
	printf("\n");
}

void print_data(book* pray)
{
	for (int i = 0; i < 3; i++)		//3개의 입력받은 책 정보를 출력함
	{
		printf("%dst book : %s\t%s\t%d\t%d\n", i + 1, pray->title, pray->author, pray->page, pray->price);
		pray++;						//연산자로 배열 요소의 구조체 변수에 접근하여 출력 후 증가. 3번 반복
	}
}
