#include <stdio.h>

int rec_func(int n);						//rec_func �Լ� ����	

int main(void)
{
	int res;								

	res = rec_func(10);						//res �ʱ��, rec_func �Լ� 10�� ȣ����
	printf("%d\n", res);					//res�� ���

	return 0;
}

int rec_func(int n)							//rec_func �Լ� ���� ����, ȣ�� Ƚ���� �Ű������� ������.
{
	if (n == 1)return 1;					
	else return (n +  rec_func(n - 1));		//ȣ�� ȸ���� 10�� �� 9�� ��ȣ�� �ϰ� 10�� ����. 10+9(��ȣ��)+8(��ȣ��)+...+2(��ȣ��)+1(��ȣ��)
}											//ȣ���� 1�� �� ��ȣ���� 0�� �����Ƿ� ����� 1