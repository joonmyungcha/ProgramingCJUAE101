#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define Length 10
#define Max_Num 10

void Input_Rand_Num(int* num, int SIZE);
double average(int* num, int SIZE);
double variance(int* num, int SIZE, double avg);
double standard_deviation(int* num, int SIZE, double var);

int main(void)
{
    int num_list[Length];
    double avg = 0, var = 0, std = 0;

    printf("배열의 크기를 입력하세요 : 10 \n");
   

    printf("%d 길이만큼 무작위 정수로 배열을 생성합니다.\n", Length);
    srand((unsigned)time(NULL));
    Input_Rand_Num(num_list, Length);

    avg = average(num_list, Length);
    var = variance(num_list, Length, avg);
    std = standard_deviation(num_list, Length, var);

    printf("평균 : %.5lf, 분산 : %.5lf, 표준편차 : %.5lf", avg, var, std);

    return 0;
}

void Input_Rand_Num(int* num, int SIZE)
{
    for (int i = 0; i < SIZE; i++)
    {
        num[i] = rand() % Max_Num;
        printf("%d번째 배열 : %d\n", i, num[i]);
    }

}


double average(int* num, int SIZE)
{
    double res = 0;
    
    for (int i = 0; i < SIZE; i++)
    {
        res += num[i];
    }

    res /= SIZE;

    return res;
}


double variance(int* num, int SIZE, double avg)
{
    double res = 0;

    for (int i = 0; i < SIZE; i++)
    {
        res += pow(num[i] - avg, 2);
    }

    res /= SIZE;

    return res;
}


double standard_deviation(int* num, int SIZE, double var)
{
    double res = 0;

    res = sqrt(var);

    return res;
}
