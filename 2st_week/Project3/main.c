//	2_week project3
#include <stdio.h>
int main(void)
{
	int kor = 3, eng = 5, mat = 4;						//kor, eng, mat ������ ���� �� ���� �ʱ�ȭ
	int credits;										//credits ������ ���� ����
	int res;											//res ������ ���� ����
	double kscore = 3.8, escore = 4.4, mscore = 3.9;	//���� �� ���� �Ǽ��� ���� �� ���� �ʱ�ȭ
	double grade;										//grade �Ǽ��� ����

	credits = kor + eng + mat;							//���� ������ 10���� �̻�
	grade = (kscore + escore + mscore) / 3.0;			//���� ���
	res = (credits >= 10) && (grade > 4.0);				//�� ���� ��� ���� �� 1, �ƴ� �� 0
	printf("%d\n", res);								//���� ���� res ���

	return 0;											//���α׷� ����
}