#include <stdio.h>

int rec_func(int n);						//rec_func 함수 선언	

int main(void)
{
	int res;								

	res = rec_func(10);						//res 초기와, rec_func 함수 10번 호출함
	printf("%d\n", res);					//res를 출력

	return 0;
}

int rec_func(int n)							//rec_func 함수 정의 시작, 호출 횟수를 매개변수에 저장함.
{
	if (n == 1)return 1;					
	else return (n +  rec_func(n - 1));		//호출 회수가 10일 때 9로 재호출 하고 10과 더함. 10+9(재호출)+8(재호출)+...+2(재호출)+1(재호출)
}											//호출이 1일 땐 재호출인 0이 없으므로 결과값 1