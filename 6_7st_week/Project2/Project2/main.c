#include <stdio.h>
#include <stdlib.h>     //rand 함수 사용하기 위함
#include <time.h>       //시간에 따른
#include <math.h>       //pow, sqrt 함수 사용하기 위함

#define Length 10       //배열의 크기 지정
#define Max_Num 10      //무작위 출력 정수의 최대값 지정
#define End_sys 1

void GenRandSeed();     //시간에 따라 무작위 정수가 바뀌기 위한 함수 
void Input_Rand_Num(int* num, int SIZE);    //무작위 정수를 배열에 생성하기 위한 함수
double average(int* num, int SIZE);         //배열의 각 인덱스 값들의 평균을 구하기 위한 함수
double variance(int* num, int SIZE, double avg);    //분산 구하는 함수
double std_deviation(int* num, int SIZE, double var);   //표준편차 구하는 함수

int main(void)
{
    int ary[Length];   //일정 크기의 배열 선언
    double avg = 0, var = 0, std = 0;   //실수형의 평균, 분산, 표준편차 초기화
    int input_run = 0;			//입력상황  예외처리
    printf("Input 1 to run. If you put another character, this system will end.\n");
    scanf_s("%d", &input_run);
    if (input_run == End_sys)
    {
        printf("length of array : %d\n", Length);    
        printf("Create an array of %d random integers.\n", Length);
        
        GenRandSeed();      //시간에 따라 바뀌는 무작위 정수 함수 호춡
        Input_Rand_Num(ary, Length);    //무작위 정수를 배열에 생성하는 함수 호출
       
        avg = average(ary, Length);     //배열의 평균 구하는 함수 호출 
        var = variance(ary, Length, avg);      //배열의 분산 구하는 함수 호출
        std = std_deviation(ary, Length, var);  //배열의 표준편차 구하는 함수 호출

        printf("average : %.3lf, variance : %.3lf, std_deviation : %.3lf", avg, var, std);  //소수점 3자리까지 결과값 출력
    }
    else
    {
        printf("End system.");
    }

    return 0;
}

void GenRandSeed()      //함수 정의, 무작위 정수가 시간에 따라 바뀌게 해줌. 이 함수 없을 시 계속 같은 정수가 출력됨
{
    srand((unsigned int)(time(NULL)));      
}



void Input_Rand_Num(int* num, int SIZE)     //배열의 각 인덱스에 무작위 정수를 생성하는 함수 
{
    for (int i = 0; i < SIZE; i++)                      //0~9 배열에 반복문으로 넣어줌
    {
        num[i] = ((unsigned int)rand() % Max_Num);      //unsigned : 양수값을 받기 위함, Max_Num은 생성할 수 있는 정수의 최대 크기
        printf("%dth number in the array : %d\n", i + 1, num[i]);   //i는 0으로 초기화 하였고, 1번째 숫자부터 나오므로 i+1
    }

}


double average(int* num, int SIZE)      //평균 구하는 함수 정의
{
    double res = 0;
    
    for (int i = 0; i < SIZE; i++)
    {
        res += num[i];  //배열의 모든 인덱스 값을 더한 값
    }

    res /= SIZE;    //배열의 크기로 나눔

    return res;     //res로 반환
}


double variance(int* num, int SIZE, double avg)     //분산 구하는 함수 정의
{
    double res = 0;

    for (int i = 0; i < SIZE; i++)
    {
        res += pow(num[i] - avg, 2);    // 분산 계산하는 함수 pow 사용 ,pow(2,3)은 2^3을 의미함.
    }

    res /= SIZE;

    return res;
}


double std_deviation(int* num, int SIZE, double var)
{
    double res = 0;

    res = sqrt(var);                // 표준편차 계산하는 함수 sqrt 사용, 분산의 1/2제곱, sqrt는 루트를 의미

    return res;
}