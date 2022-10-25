#include<stdio.h>
#include <stdlib.h>
#include <time.h>

#define Length 10       //1차원 정수배열 크기 지정
#define End_sys 1

void GenRandSeed();      //시간에 따라 무작위 정수가 바뀌기 위한 함수 
void input(int* num, int size); //배열에 무작위 정수를 넣기 위한 함수
void print_ary(int* num, int size); //배열 출력 함수
void print_ary_Ascending(int* num, int size);   //오름차순으로 배열의 인덱스 값들 정렬하는 함수
void print_ary_decending(int* num, int size);   //내림차순으로 배열의 인덱스 값들 정렬하는 함수

int main(void)
{
    int input_run = 0;			//입력 예외 상황 처리
    printf("Input 1 to run. If you put another character, this system will end.\n");
    scanf_s("%d", &input_run);
    if (input_run == End_sys)
    {
        int ary[Length];    //무작위 정수 생성할 1차원 정수배열 선언
        int temp = 0;       //오름, 내림차순 정렬 시 사용할 변수 선언 및 초기화
        GenRandSeed();

        input(ary, Length); //배열에 무작위 정수 생성하는 함수 호출
        print_ary(ary, Length); //배열 출력 함수 호출, 오름, 내림차순 정렬 전 배열의 각 인덱스 값 출력
        printf("\n");

        print_ary_Ascending(ary, Length);   //오름차순 함수 호출
        printf("Sort in ascending order.\n");
        for (int i = 0; i < Length; i++)    //반복문을 사용하여 오름차순으로 정렬한 각 인덱스값 출력
        {
            printf("Number of the %dth array : %d\n", i + 1, ary[i]);
        }
        printf("\n");

        print_ary_decending(ary, Length);   //내림차순 함수 호출
        printf("Sort in decending order.\n");
        for (int i = 0; i < Length; i++)    //반복문을 사용하여 오름차순으로 정렬한 각 인덱스값 출력
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

void GenRandSeed()  // //함수 정의, 무작위 정수가 시간에 따라 바뀌게 해줌. 이 함수 없을 시 계속 같은 정수가 출력됨
{
    srand((unsigned int)(time(NULL)));
}

void input(int* num, int size)      //함수 정의, 10 크기의 배열의 각 인덱스에 무작위 정수 생성
{
    for (int i = 0; i < size; i++)
    {
        num[i] = ((unsigned int) rand() % 10);
    }
}

void print_ary(int* num, int size)  //무작위 정수 생성한 배열의 각 인덱스 값 출력
{
    printf("Length of Array : %d\n", size);
    printf("Creates an array with %d random integers.\n", size);

    for (int i = 0; i < size; i++)
    {
        printf("Number of the %dth array : %d\n", i + 1, num[i]);
    }
}

void print_ary_Ascending(int* num, int size)    //오름차순 함수 정의
{
    int temp = 0;   //임시 변수 초기화
    for (int i = 0; i < (Length - 1); i++)  //ary 0~8, 0~7 배열 두개를 반복하며 값 비교
    {
        for (int j = i + 1; j < (Length - 1); j++) // 두 배열을 오름차순으로 처리할 때, 배열의 크기는 10이므로 처리 횟수는 9번임. (Length - 1)
        {
            if (num[i] > num[j])    //ary[1]이 ary[2]보다 클 때
            {
                temp = num[j];      //ary[1]위치에 ary[2]대입
                num[j] = num[i];    //반복하여 ary[8]까지 오름차순으로 정렬
                num[i] = temp;
            }
        }
    }
    if (num[8] > num[9])        //i는 ary[9]까지 갈 수 있지만, j는 i+1이므로 ary[10]까지 갈 수 없어 8,9을 따로 한번 더 비교
    {
        temp = num[9];          //작은 값을 앞의 배열 인덱스에 대입
        num[9] = num[8];
        num[8] = temp;
        for (int i = 0; i < (Length - 1); i++) //ary 8,9를 포함하여 0~9까지 재정렬 함.
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

void print_ary_decending(int* num, int size)    //내림차순 함수 정의
{

    int temp = 0;
    for (int i = 0; i < (Length - 1); i++)      
    {
        for (int j = i + 1; j < (Length - 1); j++)
        {
            if (num[i] < num[j])            //오름차순과 부호만 반대, ary[2]가 ary[1]보다 클 때,
            {
                temp = num[j];              //ary[1]위치에 ary[2]대입함. 반복하여 ary[8]까지 내림차순으로 정렬
                num[j] = num[i];            
                num[i] = temp;
            }
        }
    }
    if (num[8] < num[9])                    //오름차순과 동일
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
