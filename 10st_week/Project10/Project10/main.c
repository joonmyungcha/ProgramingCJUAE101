#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#pragma warning(disable:4996)

#define Max_Path 256
#define Next_char 1
#define last_ary 4

char* getExt(char* filename);	//������ Ȯ���ڸ� �����ϴ� �Լ�

int main(void)
{
	char path[Max_Path];		//���� ��θ� �Է��� ���ڿ� �迭 ����
	char* ptr = path;			//���� ��� ������ �����Ϳ� ����
	char* ptrF[Max_Path] = { NULL, };	//������ �迭 ����
	char name_new[] = { NULL, };		// ���ο� ���ϸ��� �Է¹��� �迭 ����

	printf("Enter your file's adress : ");
	scanf_s("%s", path, Max_Path);		//���� ��θ� �Է���

	ptr = getExt(path);					//Ȯ���� ���� �Լ� ȣ��

	printf("The [%s] file's extension is [%s].\n", path, ptr);	//Ȯ���� ���

	printf("\n");


	char* ptrsplit = strtok(path, "\\");	//\\�� �ִ� ���� �� �ڷ� �������־� ptrsplit ������ ������ �־���
	int counter = 0;						//�迭�� ��ġ�� �˱� ���� ���� ���� �� 0���� �ʱ�ȭ

	while (ptrsplit != NULL)				//\\���� �������� �����ͺ����� �ΰ��� �ƴҵ��� �ݺ�
	{
		ptrF[counter] = ptrsplit;			//\\�� ���� �����͵��� �迭�� �� �ε����� �־���
		counter++;							//�迭 �ε��� �ϳ��� ����
		ptrsplit = strtok(NULL, "\\");
	}

	printf("File name : %s\n", ptrF[last_ary]);	//�迭�� 5��° ��Ұ� ���ϸ����� ���
	printf("\n");

	printf("Input new File name : %s", name_new);	//���ο� ���ϸ� �Է�
	scanf_s("%s", name_new, Max_Path);

	ptrF[last_ary] = name_new;						//������ 5��° �迭�� ���ϸ��� ���ο� �Է¹��� �迭�� ����

	printf("Change File name : %s\n", name_new);

	return 0;
}


char* getExt(char* filename)					//�Լ� ����
{
	static char buf[Max_Path] = "";				//���� ���� ����
	bool ret = false;
	char* ptr = NULL;

	ptr = strrchr(filename, '.');				//���ڿ����� �������� ��ġ�� '.' �˻�

	if (ptr == NULL)							//ã�� ���Ѵٸ� NULL ��ȯ
		return NULL;

	strcpy(buf, ptr + Next_char);						//'.' ���� ���ڸ� buf�� ����

	return buf;									//buf ��ȯ
}
