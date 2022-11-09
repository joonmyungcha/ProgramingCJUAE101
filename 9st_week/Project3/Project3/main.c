#include<stdio.h>
#include<string.h>

#define Max_str_Len 80									//�迭�� �ִ� ũ�� ����

#pragma warning(disable:4996)							// C4996 ������ ����

void input_words(char* str1, char* str2, char* str3);	//�� ���� �Է� �޴� �Լ�
void swap(char* str1, char* str2, char* str3);			//�� ���� ���� ������� �ٲ��ִ� �Լ�

int main(void)
{
	char str1[Max_str_Len];								//�Է¹��� �� ���� �迭 ����
	char str2[Max_str_Len];
	char str3[Max_str_Len];

	printf("Input three words : ");	
	input_words(str1, str2, str3);						//���� ������ �Է¹޴´�.
	swap(str1, str2, str3);								//�Է� ���� �� ���ڸ� ���� ������� �ٲ��ִ� �Լ� ȣ��
	printf("%s, %s, %s", str1, str2, str3);				//������ �ٲ��� �� ���ڸ� ����Ѵ�.

	return 0;
}



void input_words(char* str1, char* str2, char* str3)
{
	scanf("%s%s%s", str1, str2, str3);
}


void swap(char* str1, char* str2, char* str3)		//�Լ� ����, �Է¹��� �� ������ ������ �������� ���� ������ ������ �ٲ��ش�.
{
	char temp[Max_str_Len];							//������ �迭 ���� ����

	if (strcmp(str1, str2) > 0)						//str1�� ���� �������� str2���� ���߿� ����
	{
		strcpy(temp, str1);							//str2�� str1�� ����
		strcpy(str1, str2);
		strcpy(str2, temp);
	}
	if (strcmp(str1, str3) > 0)						//str1�� str3���� ���߿� ����
	{
		strcpy(temp, str1);							//str3�� str1�� ����
		strcpy(str1, str3);
		strcpy(str3, temp);
	}
	if (strcmp(str2, str3) > 0)						//str2�� str3���� ���߿� ����
	{
		strcpy(temp, str2);							//str3�� str2�� ����
		strcpy(str2, str3);
		strcpy(str3, temp);
	}
}