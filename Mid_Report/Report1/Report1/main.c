#include <stdio.h>
#define row 3                   //연립방정식을 2차원 배열 행렬로 표현하기 위한 행과 열 지정, 미지수가 3개인 연립 일차방정식 문제
#define column 3                
#define res_column 4            //방정식 결과값을 포함한 열의 수 지정
#define End_sys 1               //1 입력 시 시스템 실행하기 위한 상수 지정
 
void input_form(double mat[row][res_column]);       //3개의 연립일차방정식을 입력하는 함수
double det_Matrix(double mat[row][column]);         //행렬의 값 계산하는 함수
void findSolution(double mat[row][res_column]);     //크래머 공식을 사용하여 연립방정식의 해를 구하는 함수

int main(void)
{
    int input_run = 0;
    printf("Input 1 to run. If you put another character, this system will end.\n");		//입력상황 예외처리
    scanf_s("%d", &input_run);

    if (input_run == End_sys)
    {
        printf("\nCramer's Rule\n\n");

        double equation[row][res_column];                //크레머 공식을 사용하여 3개의 연립일차방정식을 풀기 위한 2차원 배열 선언

        input_form(equation);                            //3개의 연립일차방정식을 입력하는 함수 호출

        printf("three systems of equations :\n");        //입력한 3개의 연립일차방정식 출력
        printf("(%.2lf)x+(%.2lf)y+(%.2lf)z= (%.2lf)\n", equation[0][0], equation[0][1], equation[0][2], equation[0][3]);
        printf("(%.2lf)x+(%.2lf)y+(%.2lf)z= (%.2lf)\n", equation[1][0], equation[1][1], equation[1][2], equation[1][3]);
        printf("(%.2lf)x+(%.2lf)y+(%.2lf)z= (%.2lf)\n", equation[2][0], equation[2][1], equation[2][2], equation[2][3]);
        printf("\n");

        findSolution(equation);                         //크래머 공식을 사용하여 연립방정식의 해를 구하는 함수 호출
    }
    else
    {
        printf("End system.");
    }
    return 0;
}




void input_form(double mat[row][res_column])        //함수 정의
{
    printf("Equation form : ax + by + cz = res\n"); //연립일차방정식의 형태

    for (int i = 0; i < row; i++)                   //중첩 for문을 사용하여 2차원 배열에 연립일차방정식 3개를 입력받음.
    {
        printf("Input %dst equation form : a, b, c, res\n", i + 1);
        for (int j = 0; j < res_column; j++)
        {
            scanf_s("%lf", &mat[i][j]);
        }
    }
    printf("\n");
}

double det_Matrix(double mat[row][column])          //3*3 행렬의 값을 구하는 함수 정의
{
    double ans;

    ans = mat[0][0] * (mat[1][1] * mat[2][2] - mat[2][1] * mat[1][2])
        - mat[0][1] * (mat[1][0] * mat[2][2] - mat[1][2] * mat[2][0])
        + mat[0][2] * (mat[1][0] * mat[2][1] - mat[1][1] * mat[2][0]);

    return ans;
}

void findSolution(double mat[row][res_column])      //크래머 공식 함수 정의
{
    double d[row][column] = {                       //앞에서 입력받은 3개의 연립일차방정식의 a, b, c를 행렬로 표현

        { mat[0][0], mat[0][1], mat[0][2] },
        { mat[1][0], mat[1][1], mat[1][2] },
        { mat[2][0], mat[2][1], mat[2][2] },

    };
       
    printf("Matrix d :\n");                         //d 행렬 출력
    for (int i = 0; i < row; i++)                   
    {    
        for (int j = 0; j < column; j++)
        {
            printf("%.2lf\t", d[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    double d1[row][column] = {                      //d 행렬 1열에 결과값을 넣은 d1 행렬로 표현

        { mat[0][3], mat[0][1], mat[0][2] },
        { mat[1][3], mat[1][1], mat[1][2] },
        { mat[2][3], mat[2][1], mat[2][2] },

    };

    printf("Matrix d1 :\n");                        //d1 행렬 출력
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            printf("%.2lf\t", d1[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    double d2[row][column] = {                      //d 행렬 2열에 결과값을 넣은 d2 행렬로 표현

        { mat[0][0], mat[0][3], mat[0][2] },
        { mat[1][0], mat[1][3], mat[1][2] },
        { mat[2][0], mat[2][3], mat[2][2] },

    };

    printf("Matrix d2 :\n");                        //d2 행렬 출력
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            printf("%.2lf\t", d2[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    double d3[row][column] = {                      //d 행렬 3열에 결과값을 넣은 d3 행렬로 표현

        { mat[0][0], mat[0][1], mat[0][3] },
        { mat[1][0], mat[1][1], mat[1][3] },
        { mat[2][0], mat[2][1], mat[2][3] },

    };

    printf("Matrix d3 :\n");                        //d3 행렬 출력
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            printf("%.2lf\t", d3[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    double D = det_Matrix(d);                       //d, d1, d2, d3 행렬의 값 계산
    double D1 = det_Matrix(d1);
    double D2 = det_Matrix(d2);
    double D3 = det_Matrix(d3);

    printf("Matrix value\n");
    printf("d : %.2lf \td1 : %.2lf \td2 : %.2lf \td3 : %.2lf \n\n", D, D1, D2, D3);     //계산한 각 값들을 출력
  
    if (D != 0)                                     //d 값이 0이 아닐 때
    {
        double x = D1 / D;                          //x, y, z 해 계산
        double y = D2 / D;
        double z = D3 / D; 

        printf("x = d1 / d\ny = d2 / d\nz = d3 / d\n\n");
        printf("result\nx : %.2lf\ty : %.2lf\tz : %.2lf\n\n", x, y, z);     //x, y, z 해 출력
    }

    else                                           //d 값이 0일 때
    {
        if (D1 == 0 && D2 == 0 && D3 == 0)          // d1, d2, d3 행렬의 값들이 모두 0일 때

            printf("result : Infinite solutions\n");//무한히 많은 해를 가짐

        else if (D1 != 0 || D2 != 0 || D3 != 0)     // d1, d2, d3 행렬의 값들이 하나라도 0이 아니라면

            printf("result : No solutions\n");      //방정식이 일치하지 않아 해가 없다.
    }
}