#include<stdio.h>

typedef enum { CYAN, MAGENTA, YELLOW = 5, BLACK }COLOR;		//열거형 선언 후 color로 재정의. 왼쪽부터 0,1,5,6
typedef enum { UP, DOWN, LEFT, RIGHT } ARROW;				//열거형 선언 후 arrow로 재정의. 왼쪽부터 0,1,2,3

int main(void)
{
	COLOR my_color = YELLOW, c;		//열거형 변수 선언 및 5로 초기화, 반복변수 선언
	ARROW direction = UP;			//열거형 arrow direction 변수 선언 및 1로 초기화

	for (c = CYAN; c <= BLACK; c++)	//CYAN=0, BLACK=6, 6번 반복
	{
		direction++;				//arrow 열거형 반복문 들어오자마자 1 증가해서 2가 됨, 증가연산
		direction = direction % 4;	//4로 나누기 연산한 값을 다시 대입함. 2,3,0,1 반복
		if (c == my_color) break;	//6번 반복문이 YELLOW=5 가 되면 반복문 탈출, 즉 5번 반복임
	}
									// 2,3,0,1 반복되면서 5번째 탈출이니 2로 나옴, arrow 열거형에서 2는 LEFT
	switch (direction)	//열거 벰버 판단
	{
	case UP:			//UP일 때 UP 출력
		printf("Current direction : UP"); 
		break;
	case DOWN: 
		printf("Current direction : DOWN");
		break;
	case LEFT: 
		printf("Current direction : LEFT");	//2인 LEFT 이므로 LEFT 출력
		break;
	case RIGHT: 
		printf("Current direction : RIGHT");
		break;
	default:
		printf("ERROR");
		break;
	}
	return 0;
}