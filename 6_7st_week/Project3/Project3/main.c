#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define m 2     //행의 개수 지정
#define n 3     //열의 개수 지정
#define Max_Num 10      //무작위 정수의 최대값 지정
#define End_sys 1

void GenRandSeed();     //시간에 따라 무작위 정수가 바뀌기 위한 함수 
void matrix_mul(int A[][n], int B[][m]);        //행렬 곱셈을 위한 함수
void input_A(int A[][n], int row, int column);  //2차원 배열에 무작위 정수 생성하는 함수
void input_B(int B[][m], int row, int column); 

int main(void)
{
    int input_run = 0;			//입력상황 에외처리
    printf("Input 1 to run. If you put another character, this system will end.\n");
    scanf_s("%d", &input_run);

    if (input_run == End_sys)
    {
        printf("rows and columns of the first matrix : %d*%d\n", m, n); //행렬의 행과 열 수 출력
        printf("rows and columns of the Second matrix : %d*%d\n", n, m);

        int Matrix_A[m][n] = { 0 }; //무작위 정수 입력받을 2차원 배열 선언 및 초기화
        int Matrix_B[n][m] = { 0 };

        GenRandSeed();      //시간에 따라 바뀌는 무작위 정수 함수 호춡

        input_A(Matrix_A, m, n);    //배열에 무작위 정수 생성하는 함수 호출
        input_B(Matrix_B, n, m);

        printf("First Matrix : \n");  //2차원 배열 A 행과 열 반복하며 출력
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                printf("%d\t", Matrix_A[i][j]);
            }
            printf("\n");
        }
        printf("\n");

        printf("Second Matrix : \n");  //2차원 배열 B 행과 열 반복하며 출력
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                printf("%d\t", Matrix_B[i][j]);
            }
            printf("\n");
        }
        printf("\n");

        matrix_mul(Matrix_A, Matrix_B); //배열 A와 B 곱하는 함수 호출
    }
    else
    {
        printf("End system.");
    }

    return 0;
}


void GenRandSeed()  //함수 정의
{
    srand((unsigned int)(time(NULL)));
}

void input_A(int A[][n], int row, int column)   //2차원 배열 A에 무작위 정수 생성하는 함수 정의
{
    for (int i = 0; i < row; i++)   //반복문을 사용하여 행을 반복
    {
        for (int j = 0; j < column; j++)    //하나의 행 안에서 열 반복
        {
            A[i][j] = ((unsigned int)rand() % Max_Num); //각 좌표값에 무작위 정수 생성
        }
    }
}

void input_B(int B[][m], int row, int column)   //배열 B에 무작위 정수 생성
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            B[i][j] = ((unsigned int)rand() % Max_Num);
        }
    }
}

void matrix_mul(int A[][n], int B[][m]) //두 2차원 배열 행렬의 곱셈 연산 및 출력 정의
{
    int S[m][m];    //결과값인 2*2 행렬 선언

    for (int i = 0; i < m; i++) 
    {
        for (int j = 0; j < m; j++)
        {
            S[i][j] = 0;        

            for (int k = 0; k < n; k++)
            {
                S[i][j] += A[i][k] * B[k][j];   //각 행과 열을 반복하여 곱한 후 더한 값을 배열 S에 대입
            }
        }
    }

    printf("Multiplication of first matrix and second matrix : \n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d\t", S[i][j]);    //3*3 배열 행과 열 반복하며 배열 출력
        }
        printf("\n");
    }
}