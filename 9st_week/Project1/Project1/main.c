#include <stdio.h>
#include <string.h>

#pragma warning(disable:4996)		//C4996 ������ ����

#define Max_str_Len 80				//�迭�� �ִ� ũ�� ����

int main(void)
{
	char str[Max_str_Len];		//�迭 ����
	strcpy(str, "wine");		//"wine" �� �迭 str�� ����
	strcat(str, "apple");		//"apple"�� wine �ڿ� �ٿ�����
	strncpy(str, "pear", 1);	//"pear"���� ù��° ���� �ϳ��� str���� �ٲ���
	str[10] = '\0';				//���� �迭�� �������� �� ���� ����
	printf("%s, %d\n", str, (int)(strlen(str)));	//�迭 str ��� �� str �迭�� ���̸� ��������ȯ �Ͽ� %d ������ ���

	return 0;
}