#include<stdio.h>
#pragma warning(disable:4996)

#define name_num 5              //파일에서 읽을 객체이름 갯수
#define Max_num 100             //읽은 데이터를 콘솔창에 출력하는 문자열 크지 지정

void print_data(char* fp1, char* fp2, char* ch1, char* ch2);    //파일에서 읽은 정보를 콘솔창에 출력하는 함수

int main(void)
{
	FILE* fp1, * fp2;       //두개의 파일 포인터 선언
    char ch1[Max_num], ch2[Max_num];    //읽은 데이터를 콘솔창에 출력하는 문자열 배열 선언

	fp1 = fopen("C:\\Users\\준명\\Documents\\GitHub\\ProgramingCJUAE101\\10st_week\\yolo_bbox_data.txt", "r");
	fp2 = fopen("C:\\Users\\준명\\Documents\\GitHub\\ProgramingCJUAE101\\10st_week\\yolo_label_data.txt", "r");						
	// 파일 2개 읽기 전용으로 개방
	if ((fp1 == NULL)&&(fp2 == NULL)) 
	{
		printf("ERROR.");
		return 1;
	}
	printf("Open File.\n");
    printf("\n");
    print_data(fp1, fp2, ch1, ch2); //파일에서 읽은 정보 콘솔창에 출력하는 함수 호출

	fclose(fp1);    //파일 2개 닫기
	fclose(fp2);

	return 0;
}


void print_data(char* fp1, char* fp2, char* ch1, char* ch2) //함수 정의
{
    int x = 0;//5개의 객체 이름 반복하기 위한 반복변수 선언
    while (1)
    {
        {
            fgets(ch1, Max_num, fp2);   //파일 1에서 문자를 읽은 후
            printf("%s", ch1);          //출력
            fgets(ch2, Max_num, fp1);   //파일 2
            printf("%s", ch2);          //출력 후 계속 반복
        }
        x++;                              //반복 변수 1씩 증가
        if (x == name_num)                //반복 변수가 5가 되면
        {
            break;                        //반복문 탈출
        }

    }
}
