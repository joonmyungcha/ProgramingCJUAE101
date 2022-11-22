#include<stdio.h>

#pragma warning(disable:4996) // C4996 에러를 무시

#define Max_num 50          //문자열 크기 지정

int main(void)
{
    FILE* fp;               //파일 포인터 선언
    int i;                  //정수, 실수, 문자, 문자열 입력받을 변수 선언
    double db;
    char ch;
    char str[Max_num];

    fp = fopen("C:\\Users\\준명\\Documents\\GitHub\\ProgramingCJUAE101\\10st_week\\test.txt", "w");   
    //test.txt 파일을 쓰기 전용으로 개방

    if (fp == NULL)     //fp가 NULL로 반환되면 개방 실패
    {
        printf("Fail to open 'text.txt'\n");    //이때 파일 개방 실패 문자 출력
        return 1;
    }

    printf("Open 'text.txt'.\n\n");       

    printf("[Input data in file 'text.txt']\n");

    printf("Input Integer : ");     //정수, 실수, 문자, 문자열을 입력받는다.
    scanf("%d", &i);
    fprintf(fp, "Integer : %d\n", i);   //fp 파일 포인터에 출력한다.

    printf("Input Real number : ");
    scanf("%lf", &db);
    fprintf(fp, "Real number : %.5lf\n", db);

    getchar();                      //getchar 함수는 엔터를 입력받아 \n로 출력함. 한줄씩 출력하고 다음 행으로 커서 이동
    printf("Input Word : ");
    ch = getchar();
    fprintf(fp, "Word : %c\n", ch);

    printf("Input Words : ");
    scanf("%s", str);
    fprintf(fp, "Words : %s\n", str);

    fclose(fp);     //파일 닫기

    printf("\n[Read file 'test.txt']\n");

    fp = fopen("C:\\Users\\준명\\Documents\\GitHub\\ProgramingCJUAE101\\10st_week\\test.txt", "r");
    //생성한 test.txt 파일을 쓰기 전용으로 개방
    char read[100];     //읽은 데이터 출력하기 위한 문자열 선언

    if (fp != NULL) 
    {
        while (!feof(fp))   //파일을 모두 읽었는지 확인
        {
            fgets(read, 100, fp);   //fp 파일의 데이터를 read 문자열로 받아옴
            printf(read);           //read 출력
        }
        fclose(fp); //파일 닫기
    }

    return 0;
}