#include <stdio.h>
int main(void)
{
	double weight, height, bmi;						//������, Ű, bmi �Ǽ��� ���� ����

	printf("������(kg)�� Ű(cm) �Է� : ");			//�����Կ� Ű �Է� �޼��� ���
	scanf_s("%lf%lf", &weight, &height);			//%lf�� �Ǽ��� �����Կ� Ű �Է�, ���� �տ� &�� ����

	height = height / 100;							//Ű m���� ȯ��
	bmi = weight / (height * height);				//bmi ����

	((bmi >= 20.0) && (bmi < 25.0))					//20�̻� 25�̸��� �� ���� ���� ������
		? printf("ǥ���Դϴ�.\n")					//? �� ������ ��� ���� ��, ǥ���Դϴ� ���
		: printf("ü�߰����� �ʿ��մϴ�.\n");		//: �� ���� ��� �� �ϳ��� ������ �� ü�߰����� �ʿ��մϴ� ���

	return 0;
}