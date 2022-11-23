#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#pragma warning(disable:4996)

#define Max_Path 256
#define Next_char 1
#define last_ary 4

char* getExt(char* filename);	//파일의 확장자를 추출하는 함수

int main(void)
{
	char path[Max_Path];		//파일 경로를 입력할 문자열 배열 선언
	char* ptr = path;			//파일 경로 변수를 포인터에 저장
	char* ptrF[Max_Path] = { NULL, };	//포인터 배열 선언
	char name_new[] = { NULL, };		// 새로운 파일명을 입력받을 배열 선언

	printf("Enter your file's adress : ");
	scanf_s("%s", path, Max_Path);		//파일 경로를 입력함

	ptr = getExt(path);					//확장자 추출 함수 호출

	printf("The [%s] file's extension is [%s].\n", path, ptr);	//확장자 출력

	printf("\n");


	char* ptrsplit = strtok(path, "\\");	//\\가 있는 곳을 앞 뒤로 나누어주어 ptrsplit 포인터 변수에 넣어줌
	int counter = 0;						//배열의 위치를 알기 위한 변수 선언 및 0으로 초기화

	while (ptrsplit != NULL)				//\\마다 나누어준 포인터변수가 널값이 아닐동안 반복
	{
		ptrF[counter] = ptrsplit;			//\\로 나눈 포인터들을 배열의 각 인덱스에 넣어줌
		counter++;							//배열 인덱스 하나씩 증가
		ptrsplit = strtok(NULL, "\\");
	}

	printf("File name : %s\n", ptrF[last_ary]);	//배열의 5번째 요소가 파일명으로 출력
	printf("\n");

	printf("Input new File name : %s", name_new);	//새로운 파일명 입력
	scanf_s("%s", name_new, Max_Path);

	ptrF[last_ary] = name_new;						//기존의 5번째 배열의 파일명을 새로운 입력받은 배열로 대입

	printf("Change File name : %s\n", name_new);

	return 0;
}


char* getExt(char* filename)					//함수 정의
{
	static char buf[Max_Path] = "";				//정적 변수 선언
	bool ret = false;
	char* ptr = NULL;

	ptr = strrchr(filename, '.');				//문자열에서 마지막에 위치한 '.' 검색

	if (ptr == NULL)							//찾지 못한다면 NULL 반환
		return NULL;

	strcpy(buf, ptr + Next_char);						//'.' 다음 문자를 buf에 복사

	return buf;									//buf 반환
}
