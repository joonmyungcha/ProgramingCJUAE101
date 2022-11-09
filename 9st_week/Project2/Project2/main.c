#include <stdio.h>
#include <string.h>

#define Max_str_Len 80				//�迭�� �ִ� ũ�� ����
#define std_len	17					//������ 6��° ���� *�� ǥ���ϱ� ���� ��� ����

#pragma warning(disable:4996) 

void input_word(char* input);		//�ܾ� �Է¹޴� �Լ�
void put_star(char* input, char* output, char* star);	//6��° ���ں��� *�� �����ϱ� ���� �Լ�


int main(void)
{
	char input_str[Max_str_Len];			//�Է¹޴� �迭 ����ϴ� �迭, ���� �����ϱ� ���� �迭 ����
	char output_str[Max_str_Len];
	char star[Max_str_Len] = "*";
	
	printf("Input word : ");
	input_word(input_str);					//���� �Է� �Լ� ȣ��
	put_star(input_str, output_str, star);	//*�� �����ϱ� ���� �Լ� ȣ��
	printf("Input word : %s, Omitted word : %s", input_str, output_str);

	return 0;
}



void input_word(char* input)
{
	scanf("%s", input);
}

void put_star(char* input, char* output, char* star)		//�Լ� ����, ������ �迭�� �����ͷ� �ҷ���
{
	int len;		//6���̶�� ������ ���ϱ� ���� ������ ���� ���� ����
	len = (int)(strlen(input));			//len = �Է¹��� ������ ����

	if (len <= std_len)					//������ ���̰� 5���� �۰ų� ���� ��
	{
		strcpy(output, input);			//�Է¹��� ���� �迭�� ��� ���� �迭�� �����Ѵ�.
	}
	else//5���� Ŭ ��
	{
		strncpy(output, input, std_len);	//�Է� ���� �迭 �� 5��° ������ ��� ���ڷ� ������ ��
		output[std_len] = '\0';				//�ι��ڷ� ���ڸ� �������ش�.
		for (int i = 0; i < len - std_len; i++)	//�Է¹��� ������ ũ�⿡�� ���� 5���� ���ڸ� ������ ��ŭ 
		{
			strcat(output, star);		//5��°�� ��� ���� �ڿ� *�� �ݺ��Ͽ� �������ش�
		}

	}
}
