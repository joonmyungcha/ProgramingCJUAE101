#include<stdio.h>
#pragma warning(disable:4996)

#define name_num 5              //���Ͽ��� ���� ��ü�̸� ����
#define Max_num 100             //���� �����͸� �ܼ�â�� ����ϴ� ���ڿ� ũ�� ����

void print_data(char* fp1, char* fp2, char* ch1, char* ch2);    //���Ͽ��� ���� ������ �ܼ�â�� ����ϴ� �Լ�

int main(void)
{
	FILE* fp1, * fp2;       //�ΰ��� ���� ������ ����
    char ch1[Max_num], ch2[Max_num];    //���� �����͸� �ܼ�â�� ����ϴ� ���ڿ� �迭 ����

	fp1 = fopen("C:\\Users\\�ظ�\\Documents\\GitHub\\ProgramingCJUAE101\\10st_week\\yolo_bbox_data.txt", "r");
	fp2 = fopen("C:\\Users\\�ظ�\\Documents\\GitHub\\ProgramingCJUAE101\\10st_week\\yolo_label_data.txt", "r");						
	// ���� 2�� �б� �������� ����
	if ((fp1 == NULL)&&(fp2 == NULL)) 
	{
		printf("ERROR.");
		return 1;
	}
	printf("Open File.\n");
    printf("\n");
    print_data(fp1, fp2, ch1, ch2); //���Ͽ��� ���� ���� �ܼ�â�� ����ϴ� �Լ� ȣ��

	fclose(fp1);    //���� 2�� �ݱ�
	fclose(fp2);

	return 0;
}


void print_data(char* fp1, char* fp2, char* ch1, char* ch2) //�Լ� ����
{
    int x = 0;//5���� ��ü �̸� �ݺ��ϱ� ���� �ݺ����� ����
    while (1)
    {
        {
            fgets(ch1, Max_num, fp2);   //���� 1���� ���ڸ� ���� ��
            printf("%s", ch1);          //���
            fgets(ch2, Max_num, fp1);   //���� 2
            printf("%s", ch2);          //��� �� ��� �ݺ�
        }
        x++;                              //�ݺ� ���� 1�� ����
        if (x == name_num)                //�ݺ� ������ 5�� �Ǹ�
        {
            break;                        //�ݺ��� Ż��
        }

    }
}
