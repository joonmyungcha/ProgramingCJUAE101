#include <stdio.h>
#include <stdlib.h>     //rand �Լ� ����ϱ� ����
#include <time.h>       //�ð��� ����
#include <math.h>       //pow, sqrt �Լ� ����ϱ� ����

#define Length 10       //�迭�� ũ�� ����
#define Max_Num 10      //������ ��� ������ �ִ밪 ����
#define End_sys 1

void GenRandSeed();     //�ð��� ���� ������ ������ �ٲ�� ���� �Լ� 
void Input_Rand_Num(int* num, int SIZE);    //������ ������ �迭�� �����ϱ� ���� �Լ�
double average(int* num, int SIZE);         //�迭�� �� �ε��� ������ ����� ���ϱ� ���� �Լ�
double variance(int* num, int SIZE, double avg);    //�л� ���ϴ� �Լ�
double std_deviation(int* num, int SIZE, double var);   //ǥ������ ���ϴ� �Լ�

int main(void)
{
    int ary[Length];   //���� ũ���� �迭 ����
    double avg = 0, var = 0, std = 0;   //�Ǽ����� ���, �л�, ǥ������ �ʱ�ȭ
    int input_run = 0;			//�Է»�Ȳ  ����ó��
    printf("Input 1 to run. If you put another character, this system will end.\n");
    scanf_s("%d", &input_run);
    if (input_run == End_sys)
    {
        printf("length of array : %d\n", Length);    
        printf("Create an array of %d random integers.\n", Length);
        
        GenRandSeed();      //�ð��� ���� �ٲ�� ������ ���� �Լ� ȣ��
        Input_Rand_Num(ary, Length);    //������ ������ �迭�� �����ϴ� �Լ� ȣ��
       
        avg = average(ary, Length);     //�迭�� ��� ���ϴ� �Լ� ȣ�� 
        var = variance(ary, Length, avg);      //�迭�� �л� ���ϴ� �Լ� ȣ��
        std = std_deviation(ary, Length, var);  //�迭�� ǥ������ ���ϴ� �Լ� ȣ��

        printf("average : %.3lf, variance : %.3lf, std_deviation : %.3lf", avg, var, std);  //�Ҽ��� 3�ڸ����� ����� ���
    }
    else
    {
        printf("End system.");
    }

    return 0;
}

void GenRandSeed()      //�Լ� ����, ������ ������ �ð��� ���� �ٲ�� ����. �� �Լ� ���� �� ��� ���� ������ ��µ�
{
    srand((unsigned int)(time(NULL)));      
}



void Input_Rand_Num(int* num, int SIZE)     //�迭�� �� �ε����� ������ ������ �����ϴ� �Լ� 
{
    for (int i = 0; i < SIZE; i++)                      //0~9 �迭�� �ݺ������� �־���
    {
        num[i] = ((unsigned int)rand() % Max_Num);      //unsigned : ������� �ޱ� ����, Max_Num�� ������ �� �ִ� ������ �ִ� ũ��
        printf("%dth number in the array : %d\n", i + 1, num[i]);   //i�� 0���� �ʱ�ȭ �Ͽ���, 1��° ���ں��� �����Ƿ� i+1
    }

}


double average(int* num, int SIZE)      //��� ���ϴ� �Լ� ����
{
    double res = 0;
    
    for (int i = 0; i < SIZE; i++)
    {
        res += num[i];  //�迭�� ��� �ε��� ���� ���� ��
    }

    res /= SIZE;    //�迭�� ũ��� ����

    return res;     //res�� ��ȯ
}


double variance(int* num, int SIZE, double avg)     //�л� ���ϴ� �Լ� ����
{
    double res = 0;

    for (int i = 0; i < SIZE; i++)
    {
        res += pow(num[i] - avg, 2);    // �л� ����ϴ� �Լ� pow ��� ,pow(2,3)�� 2^3�� �ǹ���.
    }

    res /= SIZE;

    return res;
}


double std_deviation(int* num, int SIZE, double var)
{
    double res = 0;

    res = sqrt(var);                // ǥ������ ����ϴ� �Լ� sqrt ���, �л��� 1/2����, sqrt�� ��Ʈ�� �ǹ�

    return res;
}