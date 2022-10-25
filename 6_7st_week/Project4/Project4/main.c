#include<stdio.h>
#include <stdlib.h>
#include <time.h>

#define Length 10       //1���� �����迭 ũ�� ����
#define End_sys 1

void GenRandSeed();      //�ð��� ���� ������ ������ �ٲ�� ���� �Լ� 
void input(int* num, int size); //�迭�� ������ ������ �ֱ� ���� �Լ�
void print_ary(int* num, int size); //�迭 ��� �Լ�
void print_ary_Ascending(int* num, int size);   //������������ �迭�� �ε��� ���� �����ϴ� �Լ�
void print_ary_decending(int* num, int size);   //������������ �迭�� �ε��� ���� �����ϴ� �Լ�

int main(void)
{
    int input_run = 0;			//�Է� ���� ��Ȳ ó��
    printf("Input 1 to run. If you put another character, this system will end.\n");
    scanf_s("%d", &input_run);
    if (input_run == End_sys)
    {
        int ary[Length];    //������ ���� ������ 1���� �����迭 ����
        int temp = 0;       //����, �������� ���� �� ����� ���� ���� �� �ʱ�ȭ
        GenRandSeed();

        input(ary, Length); //�迭�� ������ ���� �����ϴ� �Լ� ȣ��
        print_ary(ary, Length); //�迭 ��� �Լ� ȣ��, ����, �������� ���� �� �迭�� �� �ε��� �� ���
        printf("\n");

        print_ary_Ascending(ary, Length);   //�������� �Լ� ȣ��
        printf("Sort in ascending order.\n");
        for (int i = 0; i < Length; i++)    //�ݺ����� ����Ͽ� ������������ ������ �� �ε����� ���
        {
            printf("Number of the %dth array : %d\n", i + 1, ary[i]);
        }
        printf("\n");

        print_ary_decending(ary, Length);   //�������� �Լ� ȣ��
        printf("Sort in decending order.\n");
        for (int i = 0; i < Length; i++)    //�ݺ����� ����Ͽ� ������������ ������ �� �ε����� ���
        {
            printf("Number of the %dth array : %d\n", i + 1, ary[i]);
        }

    }
    else
    {
        printf("End system.");
    }
    return 0;
}

void GenRandSeed()  // //�Լ� ����, ������ ������ �ð��� ���� �ٲ�� ����. �� �Լ� ���� �� ��� ���� ������ ��µ�
{
    srand((unsigned int)(time(NULL)));
}

void input(int* num, int size)      //�Լ� ����, 10 ũ���� �迭�� �� �ε����� ������ ���� ����
{
    for (int i = 0; i < size; i++)
    {
        num[i] = ((unsigned int) rand() % 10);
    }
}

void print_ary(int* num, int size)  //������ ���� ������ �迭�� �� �ε��� �� ���
{
    printf("Length of Array : %d\n", size);
    printf("Creates an array with %d random integers.\n", size);

    for (int i = 0; i < size; i++)
    {
        printf("Number of the %dth array : %d\n", i + 1, num[i]);
    }
}

void print_ary_Ascending(int* num, int size)    //�������� �Լ� ����
{
    int temp = 0;   //�ӽ� ���� �ʱ�ȭ
    for (int i = 0; i < (Length - 1); i++)  //ary 0~8, 0~7 �迭 �ΰ��� �ݺ��ϸ� �� ��
    {
        for (int j = i + 1; j < (Length - 1); j++) // �� �迭�� ������������ ó���� ��, �迭�� ũ��� 10�̹Ƿ� ó�� Ƚ���� 9����. (Length - 1)
        {
            if (num[i] > num[j])    //ary[1]�� ary[2]���� Ŭ ��
            {
                temp = num[j];      //ary[1]��ġ�� ary[2]����
                num[j] = num[i];    //�ݺ��Ͽ� ary[8]���� ������������ ����
                num[i] = temp;
            }
        }
    }
    if (num[8] > num[9])        //i�� ary[9]���� �� �� ������, j�� i+1�̹Ƿ� ary[10]���� �� �� ���� 8,9�� ���� �ѹ� �� ��
    {
        temp = num[9];          //���� ���� ���� �迭 �ε����� ����
        num[9] = num[8];
        num[8] = temp;
        for (int i = 0; i < (Length - 1); i++) //ary 8,9�� �����Ͽ� 0~9���� ������ ��.
        {

            for (int j = i + 1; j < (Length - 1); j++) 
            {

                if (num[i] > num[j]) 
                {
                    temp = num[j];
                    num[j] = num[i];
                    num[i] = temp;
                }

            }

        }
    }
}

void print_ary_decending(int* num, int size)    //�������� �Լ� ����
{

    int temp = 0;
    for (int i = 0; i < (Length - 1); i++)      
    {
        for (int j = i + 1; j < (Length - 1); j++)
        {
            if (num[i] < num[j])            //���������� ��ȣ�� �ݴ�, ary[2]�� ary[1]���� Ŭ ��,
            {
                temp = num[j];              //ary[1]��ġ�� ary[2]������. �ݺ��Ͽ� ary[8]���� ������������ ����
                num[j] = num[i];            
                num[i] = temp;
            }
        }
    }
    if (num[8] < num[9])                    //���������� ����
    {
        temp = num[9];
        num[9] = num[8];
        num[8] = temp;
        for (int i = 0; i < (Length - 1); i++) 
        {

            for (int j = i + 1; j < (Length - 1); j++) 
            {

                if (num[i] < num[j]) 
                {
                    temp = num[j];
                    num[j] = num[i];
                    num[i] = temp;
                }

            }

        }
    }
}
