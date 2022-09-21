//	2_week project3
#include <stdio.h>
int main(void)
{
	int kor = 3, eng = 5, mat = 4;						//kor, eng, mat 정수형 선언 후 학점 초기화
	int credits;										//credits 정수형 변수 선언
	int res;											//res 정수형 변수 선언
	double kscore = 3.8, escore = 4.4, mscore = 3.9;	//평점 세 변수 실수형 선언 후 평점 초기화
	double grade;										//grade 실수형 선언

	credits = kor + eng + mat;							//학점 총점이 10학점 이상
	grade = (kscore + escore + mscore) / 3.0;			//학점 평균
	res = (credits >= 10) && (grade > 4.0);				//두 조건 모두 참일 때 1, 아닐 시 0
	printf("%d\n", res);								//정수 변수 res 출력

	return 0;											//프로그램 종료
}