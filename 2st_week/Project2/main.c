#include <stdio.h>
int main(void)
{
	char ch;													//���ڿ��� char������ ���� ����
	
	printf("���� �Է� : ");										//���� �Է� �Է�â ���
	scanf_s("%c", &ch);											//%c�� ���� �Է� �� &�� ch���� ����
	printf("%c������ �ƽ�Ű �ڵ� ���� %d�Դϴ�.", ch, ch);		//%c�� ���� �����̰� �ƽ�Ű �ڵ�� �����̹Ƿ� %d, �� ���� ch ch�� ����

	return 0;
}