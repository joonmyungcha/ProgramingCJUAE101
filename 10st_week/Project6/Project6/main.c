#include<stdio.h>

typedef enum { CYAN, MAGENTA, YELLOW = 5, BLACK }COLOR;		//������ ���� �� color�� ������. ���ʺ��� 0,1,5,6
typedef enum { UP, DOWN, LEFT, RIGHT } ARROW;				//������ ���� �� arrow�� ������. ���ʺ��� 0,1,2,3

int main(void)
{
	COLOR my_color = YELLOW, c;		//������ ���� ���� �� 5�� �ʱ�ȭ, �ݺ����� ����
	ARROW direction = UP;			//������ arrow direction ���� ���� �� 1�� �ʱ�ȭ

	for (c = CYAN; c <= BLACK; c++)	//CYAN=0, BLACK=6, 6�� �ݺ�
	{
		direction++;				//arrow ������ �ݺ��� �����ڸ��� 1 �����ؼ� 2�� ��, ��������
		direction = direction % 4;	//4�� ������ ������ ���� �ٽ� ������. 2,3,0,1 �ݺ�
		if (c == my_color) break;	//6�� �ݺ����� YELLOW=5 �� �Ǹ� �ݺ��� Ż��, �� 5�� �ݺ���
	}
									// 2,3,0,1 �ݺ��Ǹ鼭 5��° Ż���̴� 2�� ����, arrow ���������� 2�� LEFT
	switch (direction)	//���� ���� �Ǵ�
	{
	case UP:			//UP�� �� UP ���
		printf("Current direction : UP"); 
		break;
	case DOWN: 
		printf("Current direction : DOWN");
		break;
	case LEFT: 
		printf("Current direction : LEFT");	//2�� LEFT �̹Ƿ� LEFT ���
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