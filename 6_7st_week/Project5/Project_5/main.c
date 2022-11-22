#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define Num_shots 100						//100번 쏠 때의 상수 지정
#define jump_row 10							//한개의 열에 10개 출력된 후 행 바꾸기 위한 상수 지정
#define End_sys 1

int main(void)
{
	int input_run = 0;
	printf("Input 1 to run. If you put another character, this system will end.\n");		//입력상황 예외처리
	scanf_s("%d", &input_run);

	if (input_run == End_sys)
	{
		double Vertical[Num_shots] = { 0 };				//100개의 난수 생성을 위한 수직, 수평 실수 변수 초기화
		double Horizon[Num_shots] = { 0 };

		double Vertical_V[Num_shots] = { 0 };				//균등분포 난수를 표준정규분포로 바꾸는 수식의 1단계를 위한 배열 V 선언
		double Horizon_V[Num_shots] = { 0 };

		double Vertical_Z[Num_shots] = { 0 };				//2단계 수식을 위한 Z와 K 그리고 조건 만족 시 사용 할 Z에 대한 배열 선언
		double Vertical_K[Num_shots] = { 0 };				//수직 배열
		double rVertical_Z[Num_shots] = { 0 };

		double Horizon_Z[Num_shots] = { 0 };				//수평 배열
		double Horizon_K[Num_shots] = { 0 };	
		double rHorizon_Z[Num_shots] = { 0 };

		double Vertical_X[Num_shots] = { 0 };				//수식 4단계를 위한 배열 X 선언
		double Horizon_X[Num_shots] = { 0 };

		srand((time(NULL)));				//시간마다 무작위 변수 초기화 함수


		for (int i = 0; i < Num_shots; i++)					//수직 수평 배열에 반복문을 통하여
		{
			Vertical[i] = (double)rand() / RAND_MAX;		//0~1 범위의 실수형 난수 100개 생성
			Horizon[i] = (double)rand() / RAND_MAX;			//RAND_MAX 값은 32767 이다.
		}

		printf("\n\nVertical 100\n\n ");					//수직, 수평 난수값 출력
		for (int j = 0; j < Num_shots; j++)
		{
			if (j % jump_row == 0)
			{
				printf("\n");						//10개의 난수 한 열에 출력 후 행 바꿈
			}
			printf("%.3lf\t", Vertical[j]);
		}


		printf("\n\nHorizon 100\n\n");
		for (int j = 0; j < Num_shots; j++)
		{
			if (j % jump_row == 0)
			{
				printf("\n");
			}
			printf("%.3lf\t", Horizon[j]);

		}
		printf("\n");

		int a = 0;				//4단계 2번 조건 불만족 시 배열의 위치를 고정하기 위한 변수 초기화 해줌.
		while (1)				//수직 r1에 관한 1~4번 수식
		{
			if (Vertical_K[Num_shots - 1] < 1 - Vertical[Num_shots - 1])				//3단게 1번조건 만족 후 break를 쓰지 않았기에, 
			{																		//for문을 통해 99번째 배열이 while문으로 들어왔을 때 while문 탈출
				rVertical_Z[Num_shots - 1] = Vertical_Z[Num_shots - 1];
				break;
			}
			for (int i = a; i < Num_shots; i++)
			{

				Vertical_V[i] = (sqrt(2 / exp(1.0)) * (2 * Vertical[i] - 1));		//1단계 수식
				Vertical_Z[i] = Vertical_V[i] / Vertical[i];						//2단계	수식
				Vertical_K[i] = 0.25 * (pow(Vertical_Z[i], 2));						//2단계	수식
				if (Vertical_K[i] < 1 - Vertical[i])								//3단계 1번조건 만족 시 그 값을 Z에 새로 대입 후 while문으로 
				{
					rVertical_Z[i] = Vertical_Z[i];
				}
				else if ((Vertical_K[i] >= (0.259 / Vertical[i]) + 0.35) && (Vertical_K[i] > -log10(Vertical[i])))		//3단계 2번조건 만족 시
				{
					Vertical[i] = (double)rand() / RAND_MAX;						//난수를 다시 생성
					a = i;
					break;															//for 문 나와 while 문으로 다시 들어가 3단계 1번조건 만족시킬 떄까지 반복함
				}
			}
		}
		for (int i = 0; i < Num_shots; i++)												//4단계 수식
		{
			Vertical_X[i] = 0 + rVertical_Z[i] * 1.2;								//평균 0, 표준편차 1.2 
		}

		int b = 0;																	//수평 r2에 관한 1~4단계
		while (1)
		{
			if (Horizon_K[Num_shots - 1] < 1 - Horizon[Num_shots - 1])
			{
				rHorizon_Z[Num_shots - 1] = Horizon_Z[Num_shots - 1];
				break;
			}
			for (int i = a; i < Num_shots; i++)
			{

				Horizon_V[i] = (sqrt(2 / exp(1.0)) * (2 * Horizon[i] - 1));
				Horizon_Z[i] = Horizon_V[i] / Horizon[i];
				Horizon_K[i] = 0.25 * (pow(Horizon_Z[i], 2));
				if (Horizon_K[i] < 1 - Horizon[i])
				{
					rHorizon_Z[i] = Horizon_Z[i];
				}
				else if ((Horizon_K[i] >= (0.259 / Horizon[i]) + 0.35) && (Horizon[i] > -log10(Horizon[i])))
				{
					Horizon[i] = (double)rand() / RAND_MAX;
					b = i;
					break;
				}
			}
		}
		for (int i = 0; i < Num_shots; i++)
		{
			Horizon_X[i] = 0 + rHorizon_Z[i] * 1.0;								//평균 0, 표준편차 1.0
		}

		printf("\nVertical X1 100\n ");								//1~4번 수식을 통한 X 배열 출력
		for (int j = 0; j < Num_shots; j++)
		{
			if (j % jump_row == 0)
			{
				printf("\n");
			}
			printf("%.3lf\t", Vertical_X[j]);
		}
		printf("\nHorizon X2 100\n ");
		for (int j = 0; j < Num_shots; j++)
		{
			if (j % jump_row == 0)
			{
				printf("\n");
			}
			printf("%.3lf\t", Horizon_X[j]);
		}

		printf("\n\n");

		int count = 0;										//명중하는 개수를 세기위한 변수 초기화

		for (int i = 0; i < Num_shots; i++)					//앞에서 출력한 X1, X2 각각 100개의 값들이 명중 좌표인 2*2 사각형에 들어갈 때 조건.
		{													//X1, X2가 -1~1 범위를 만족할 때  
			if (((Vertical_X[i] >= -1.0) && (Vertical_X[i] <= 1.0)) && ((Horizon_X[i] >= -1.0) && (Horizon_X[i] <= 1.0)))
				count++;									//명중 횟수는 하나하나씩 증가. 반복문을 통해 조건을 만족한 개수 출력	
		}

		printf("Number of hits : %d , Hit rate : %.3lf\n", count, (double)count / Num_shots);	//명중 횟수와 확류 출력

	}
	else
	{
	printf("End system.");
	}

	return 0;
}
