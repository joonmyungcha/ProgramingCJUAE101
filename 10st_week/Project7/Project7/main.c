#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma warning(disable:4996) // C4996 에러를 무시

#define student_num 5           //학생의 수 지정
#define compare_num 1           //비교 회수 -1을 빼기 위한 상수 지정
#define A_grade 90
#define B_grade 80
#define C_grade 70

typedef struct
{                             //구조체 student형으로 재정의, student형 구조체 선언
    int num;                  // 학번
    char name[20];            // 이름
    int kor, eng, math;       // 3과목 점수
    int total;                // 총점
    double avg;               // 평균
    char grade;               // 학점

} Student;

void input_data(Student* pary);     //학생의 정보를 입력받는 함수
void calc_data(Student* pary);      //평균과 학점을 계산하는 함수
void sort_data(Student* pary);      //데이터를 정렬하는 함수
void print_data(Student* pary);     //데이터를 출력하는 함수

int main(void)
{
    Student ary[student_num];           // 요소가 5개인 구조체 배열 ary 선언
    input_data(ary);          // 학번, 이름, 3과목 점수 입력
    calc_data(ary);           // 총점, 평균, 학점 계산

    printf("# Before sorting...\n");
    print_data(ary);          // 정렬 전 출력 함수 호출
    sort_data(ary);           // 총점 순으로 내림차순 정렬
    printf("\n# After sorting...\n");
    print_data(ary);          // 정렬 후 출력

    return 0;
}


void input_data(Student* pary)      //함수 정의, 배열을 포인터로 연결해줌
{
    for (int i = 0; i < student_num; i++)       //5명의 정보를 5번 반복하며 입력
    {
        printf("Class Number : ");  
        scanf("%d", &pary->num);            //연산자를 사용하여 배열 요소의 num에 접근함
        printf("Name : ");
        scanf("%s", pary->name);
        printf("kor, eng, math score : ");
        scanf("%d%d%d", &pary->kor, &pary->eng, &pary->math);

        pary++;                             //첫번째 배열 모두 입력 시 다음 배열로 증가
    }
}


void calc_data(Student* pary)
{
    for (int i = 0; i < student_num; i++)
    {
        pary->total = pary->kor + pary->eng + pary->math;   //배열을 포인터로 접근하여 연산자를 하용하여 구조체 요소로 접근
        pary->avg = pary->total / 3.0;                      //평균 계산
        if (pary->avg >= A_grade)
        {
            pary->grade = 'A';
        }                                                   //학점 계산
        else if (pary->avg >= B_grade)
        {
            pary->grade = 'B';
        }
        else if (pary->avg >= C_grade)
        {
            pary->grade = 'C';
        }
        else
        {
            pary->grade = 'F';
        }
        pary++;
    }
}


void sort_data(Student* pary)               //정렬하는 함수 정의
{
    Student temp;                           //임시 구조체 변수 선언
    int top;


    for (int i = 0; i < student_num-compare_num; i++)     //비교하여 정렬하는 과정의 횟수는 요소 갯수 -1
    {
        top = i;                                           //첫번째 비교할 첫번째 배열을 top으로 지정해놓은 후
        for (int j = i + 1; j < student_num; j++)
        {
            if (pary[top].total < pary[j].total)            //첫 배열 구조체 요소의 총점을 다음 배열의 총점과 비교하여 
            {                                               
                top = j;                                    //뒤 배열이 더 크면 다시 top으로 초기화 해줌.
            }
        }
        if (top != i)                                       //j로 초기화 되서 기존의 top인 i가 아니면
        {
            temp = pary[top];                               //앞 뒤 자리 바꿔줌.
            pary[top] = pary[i];
            pary[i] = temp;
        }
    }                                                       //5번 반복해서 모두 정렬
}

void print_data(Student* pary)      //출력하는 함수 정의
{
    for (int i = 0; i < student_num; i++)   //연산자로 배열 요소의 구조체 변수에 접근하여 출력 후 증가. 5번 반복
    {
        printf("%d\t%s\t%d\t%d\t%d\t%d\t%.1lf\t%c\n", pary->num, pary->name, pary->kor, pary->eng, pary->math, pary->total, pary->avg, pary->grade);
        pary++;
    }
}