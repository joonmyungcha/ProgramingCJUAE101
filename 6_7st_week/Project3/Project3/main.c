#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define m 2     //���� ���� ����
#define n 3     //���� ���� ����
#define Max_Num 10      //������ ������ �ִ밪 ����
#define End_sys 1

void GenRandSeed();     //�ð��� ���� ������ ������ �ٲ�� ���� �Լ� 
void matrix_mul(int A[][n], int B[][m]);        //��� ������ ���� �Լ�
void input_A(int A[][n], int row, int column);  //2���� �迭�� ������ ���� �����ϴ� �Լ�
void input_B(int B[][m], int row, int column); 

int main(void)
{
    int input_run = 0;			//�Է»�Ȳ ����ó��
    printf("Input 1 to run. If you put another character, this system will end.\n");
    scanf_s("%d", &input_run);

    if (input_run == End_sys)
    {
        printf("rows and columns of the first matrix : %d*%d\n", m, n); //����� ��� �� �� ���
        printf("rows and columns of the Second matrix : %d*%d\n", n, m);

        int Matrix_A[m][n] = { 0 }; //������ ���� �Է¹��� 2���� �迭 ���� �� �ʱ�ȭ
        int Matrix_B[n][m] = { 0 };

        GenRandSeed();      //�ð��� ���� �ٲ�� ������ ���� �Լ� ȣ��

        input_A(Matrix_A, m, n);    //�迭�� ������ ���� �����ϴ� �Լ� ȣ��
        input_B(Matrix_B, n, m);

        printf("First Matrix : \n");  //2���� �迭 A ��� �� �ݺ��ϸ� ���
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                printf("%d\t", Matrix_A[i][j]);
            }
            printf("\n");
        }
        printf("\n");

        printf("Second Matrix : \n");  //2���� �迭 B ��� �� �ݺ��ϸ� ���
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                printf("%d\t", Matrix_B[i][j]);
            }
            printf("\n");
        }
        printf("\n");

        matrix_mul(Matrix_A, Matrix_B); //�迭 A�� B ���ϴ� �Լ� ȣ��
    }
    else
    {
        printf("End system.");
    }

    return 0;
}


void GenRandSeed()  //�Լ� ����
{
    srand((unsigned int)(time(NULL)));
}

void input_A(int A[][n], int row, int column)   //2���� �迭 A�� ������ ���� �����ϴ� �Լ� ����
{
    for (int i = 0; i < row; i++)   //�ݺ����� ����Ͽ� ���� �ݺ�
    {
        for (int j = 0; j < column; j++)    //�ϳ��� �� �ȿ��� �� �ݺ�
        {
            A[i][j] = ((unsigned int)rand() % Max_Num); //�� ��ǥ���� ������ ���� ����
        }
    }
}

void input_B(int B[][m], int row, int column)   //�迭 B�� ������ ���� ����
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            B[i][j] = ((unsigned int)rand() % Max_Num);
        }
    }
}

void matrix_mul(int A[][n], int B[][m]) //�� 2���� �迭 ����� ���� ���� �� ��� ����
{
    int S[m][m];    //������� 2*2 ��� ����

    for (int i = 0; i < m; i++) 
    {
        for (int j = 0; j < m; j++)
        {
            S[i][j] = 0;        

            for (int k = 0; k < n; k++)
            {
                S[i][j] += A[i][k] * B[k][j];   //�� ��� ���� �ݺ��Ͽ� ���� �� ���� ���� �迭 S�� ����
            }
        }
    }

    printf("Multiplication of first matrix and second matrix : \n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d\t", S[i][j]);    //3*3 �迭 ��� �� �ݺ��ϸ� �迭 ���
        }
        printf("\n");
    }
}