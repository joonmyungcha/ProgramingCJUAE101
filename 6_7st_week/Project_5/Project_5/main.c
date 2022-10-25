#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define Num_shots 100						//100�� �� ���� ��� ����
#define jump_row 10							//�Ѱ��� ���� 10�� ��µ� �� �� �ٲٱ� ���� ��� ����
#define End_sys 1

int main(void)
{
	int input_run = 0;
	printf("Input 1 to run. If you put another character, this system will end.\n");		//�Է»�Ȳ ����ó��
	scanf_s("%d", &input_run);

	if (input_run == End_sys)
	{
		double Vertical[Num_shots] = { 0 };				//100���� ���� ������ ���� ����, ���� �Ǽ� ���� �ʱ�ȭ
		double Horizon[Num_shots] = { 0 };

		double Vertical_V[Num_shots] = { 0 };				//�յ���� ������ ǥ�����Ժ����� �ٲٴ� ������ 1�ܰ踦 ���� �迭 V ����
		double Horizon_V[Num_shots] = { 0 };

		double Vertical_Z[Num_shots] = { 0 };				//2�ܰ� ������ ���� Z�� K �׸��� ���� ���� �� ��� �� Z�� ���� �迭 ����
		double Vertical_K[Num_shots] = { 0 };				//���� �迭
		double rVertical_Z[Num_shots] = { 0 };

		double Horizon_Z[Num_shots] = { 0 };				//���� �迭
		double Horizon_K[Num_shots] = { 0 };	
		double rHorizon_Z[Num_shots] = { 0 };

		double Vertical_X[Num_shots] = { 0 };				//���� 4�ܰ踦 ���� �迭 X ����
		double Horizon_X[Num_shots] = { 0 };

		srand((time(NULL)));				//�ð����� ������ ���� �ʱ�ȭ �Լ�


		for (int i = 0; i < Num_shots; i++)					//���� ���� �迭�� �ݺ����� ���Ͽ�
		{
			Vertical[i] = (double)rand() / RAND_MAX;		//0~1 ������ �Ǽ��� ���� 100�� ����
			Horizon[i] = (double)rand() / RAND_MAX;			//RAND_MAX ���� 32767 �̴�.
		}

		printf("\n\nVertical 100\n\n ");					//����, ���� ������ ���
		for (int j = 0; j < Num_shots; j++)
		{
			if (j % jump_row == 0)
			{
				printf("\n");						//10���� ���� �� ���� ��� �� �� �ٲ�
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

		int a = 0;				//4�ܰ� 2�� ���� �Ҹ��� �� �迭�� ��ġ�� �����ϱ� ���� ���� �ʱ�ȭ ����.
		while (1)				//���� r1�� ���� 1~4�� ����
		{
			if (Vertical_K[Num_shots - 1] < 1 - Vertical[Num_shots - 1])				//3�ܰ� 1������ ���� �� break�� ���� �ʾұ⿡, 
			{																		//for���� ���� 99��° �迭�� while������ ������ �� while�� Ż��
				rVertical_Z[Num_shots - 1] = Vertical_Z[Num_shots - 1];
				break;
			}
			for (int i = a; i < Num_shots; i++)
			{

				Vertical_V[i] = (sqrt(2 / exp(1.0)) * (2 * Vertical[i] - 1));		//1�ܰ� ����
				Vertical_Z[i] = Vertical_V[i] / Vertical[i];						//2�ܰ�	����
				Vertical_K[i] = 0.25 * (pow(Vertical_Z[i], 2));						//2�ܰ�	����
				if (Vertical_K[i] < 1 - Vertical[i])								//3�ܰ� 1������ ���� �� �� ���� Z�� ���� ���� �� while������ 
				{
					rVertical_Z[i] = Vertical_Z[i];
				}
				else if ((Vertical_K[i] >= (0.259 / Vertical[i]) + 0.35) && (Vertical_K[i] > -log10(Vertical[i])))		//3�ܰ� 2������ ���� ��
				{
					Vertical[i] = (double)rand() / RAND_MAX;						//������ �ٽ� ����
					a = i;
					break;															//for �� ���� while ������ �ٽ� �� 3�ܰ� 1������ ������ų ������ �ݺ���
				}
			}
		}
		for (int i = 0; i < Num_shots; i++)												//4�ܰ� ����
		{
			Vertical_X[i] = 0 + rVertical_Z[i] * 1.2;								//��� 0, ǥ������ 1.2 
		}

		int b = 0;																	//���� r2�� ���� 1~4�ܰ�
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
			Horizon_X[i] = 0 + rHorizon_Z[i] * 1.0;								//��� 0, ǥ������ 1.0
		}

		printf("\nVertical X1 100\n ");								//1~4�� ������ ���� X �迭 ���
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

		int count = 0;										//�����ϴ� ������ �������� ���� �ʱ�ȭ

		for (int i = 0; i < Num_shots; i++)					//�տ��� ����� X1, X2 ���� 100���� ������ ���� ��ǥ�� 2*2 �簢���� �� �� ����.
		{													//X1, X2�� -1~1 ������ ������ ��  
			if (((Vertical_X[i] >= -1.0) && (Vertical_X[i] <= 1.0)) && ((Horizon_X[i] >= -1.0) && (Horizon_X[i] <= 1.0)))
				count++;									//���� Ƚ���� �ϳ��ϳ��� ����. �ݺ����� ���� ������ ������ ���� ���	
		}

		printf("Number of hits : %d , Hit rate : %.3lf\n", count, (double)count / Num_shots);	//���� Ƚ���� Ȯ�� ���

	}
	else
	{
	printf("End system.");
	}

	return 0;
}
