#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma warning(disable:4996) // C4996 ������ ����

#define student_num 5           //�л��� �� ����
#define compare_num 1           //�� ȸ�� -1�� ���� ���� ��� ����
#define A_grade 90
#define B_grade 80
#define C_grade 70

typedef struct
{                             //����ü student������ ������, student�� ����ü ����
    int num;                  // �й�
    char name[20];            // �̸�
    int kor, eng, math;       // 3���� ����
    int total;                // ����
    double avg;               // ���
    char grade;               // ����

} Student;

void input_data(Student* pary);     //�л��� ������ �Է¹޴� �Լ�
void calc_data(Student* pary);      //��հ� ������ ����ϴ� �Լ�
void sort_data(Student* pary);      //�����͸� �����ϴ� �Լ�
void print_data(Student* pary);     //�����͸� ����ϴ� �Լ�

int main(void)
{
    Student ary[student_num];           // ��Ұ� 5���� ����ü �迭 ary ����
    input_data(ary);          // �й�, �̸�, 3���� ���� �Է�
    calc_data(ary);           // ����, ���, ���� ���

    printf("# Before sorting...\n");
    print_data(ary);          // ���� �� ��� �Լ� ȣ��
    sort_data(ary);           // ���� ������ �������� ����
    printf("\n# After sorting...\n");
    print_data(ary);          // ���� �� ���

    return 0;
}


void input_data(Student* pary)      //�Լ� ����, �迭�� �����ͷ� ��������
{
    for (int i = 0; i < student_num; i++)       //5���� ������ 5�� �ݺ��ϸ� �Է�
    {
        printf("Class Number : ");  
        scanf("%d", &pary->num);            //�����ڸ� ����Ͽ� �迭 ����� num�� ������
        printf("Name : ");
        scanf("%s", pary->name);
        printf("kor, eng, math score : ");
        scanf("%d%d%d", &pary->kor, &pary->eng, &pary->math);

        pary++;                             //ù��° �迭 ��� �Է� �� ���� �迭�� ����
    }
}


void calc_data(Student* pary)
{
    for (int i = 0; i < student_num; i++)
    {
        pary->total = pary->kor + pary->eng + pary->math;   //�迭�� �����ͷ� �����Ͽ� �����ڸ� �Ͽ��Ͽ� ����ü ��ҷ� ����
        pary->avg = pary->total / 3.0;                      //��� ���
        if (pary->avg >= A_grade)
        {
            pary->grade = 'A';
        }                                                   //���� ���
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


void sort_data(Student* pary)               //�����ϴ� �Լ� ����
{
    Student temp;                           //�ӽ� ����ü ���� ����
    int top;


    for (int i = 0; i < student_num-compare_num; i++)     //���Ͽ� �����ϴ� ������ Ƚ���� ��� ���� -1
    {
        top = i;                                           //ù��° ���� ù��° �迭�� top���� �����س��� ��
        for (int j = i + 1; j < student_num; j++)
        {
            if (pary[top].total < pary[j].total)            //ù �迭 ����ü ����� ������ ���� �迭�� ������ ���Ͽ� 
            {                                               
                top = j;                                    //�� �迭�� �� ũ�� �ٽ� top���� �ʱ�ȭ ����.
            }
        }
        if (top != i)                                       //j�� �ʱ�ȭ �Ǽ� ������ top�� i�� �ƴϸ�
        {
            temp = pary[top];                               //�� �� �ڸ� �ٲ���.
            pary[top] = pary[i];
            pary[i] = temp;
        }
    }                                                       //5�� �ݺ��ؼ� ��� ����
}

void print_data(Student* pary)      //����ϴ� �Լ� ����
{
    for (int i = 0; i < student_num; i++)   //�����ڷ� �迭 ����� ����ü ������ �����Ͽ� ��� �� ����. 5�� �ݺ�
    {
        printf("%d\t%s\t%d\t%d\t%d\t%d\t%.1lf\t%c\n", pary->num, pary->name, pary->kor, pary->eng, pary->math, pary->total, pary->avg, pary->grade);
        pary++;
    }
}