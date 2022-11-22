#include<stdio.h>

#pragma warning(disable:4996) // C4996 ������ ����

#define Max_num 50          //���ڿ� ũ�� ����

int main(void)
{
    FILE* fp;               //���� ������ ����
    int i;                  //����, �Ǽ�, ����, ���ڿ� �Է¹��� ���� ����
    double db;
    char ch;
    char str[Max_num];

    fp = fopen("C:\\Users\\�ظ�\\Documents\\GitHub\\ProgramingCJUAE101\\10st_week\\test.txt", "w");   
    //test.txt ������ ���� �������� ����

    if (fp == NULL)     //fp�� NULL�� ��ȯ�Ǹ� ���� ����
    {
        printf("Fail to open 'text.txt'\n");    //�̶� ���� ���� ���� ���� ���
        return 1;
    }

    printf("Open 'text.txt'.\n\n");       

    printf("[Input data in file 'text.txt']\n");

    printf("Input Integer : ");     //����, �Ǽ�, ����, ���ڿ��� �Է¹޴´�.
    scanf("%d", &i);
    fprintf(fp, "Integer : %d\n", i);   //fp ���� �����Ϳ� ����Ѵ�.

    printf("Input Real number : ");
    scanf("%lf", &db);
    fprintf(fp, "Real number : %.5lf\n", db);

    getchar();                      //getchar �Լ��� ���͸� �Է¹޾� \n�� �����. ���پ� ����ϰ� ���� ������ Ŀ�� �̵�
    printf("Input Word : ");
    ch = getchar();
    fprintf(fp, "Word : %c\n", ch);

    printf("Input Words : ");
    scanf("%s", str);
    fprintf(fp, "Words : %s\n", str);

    fclose(fp);     //���� �ݱ�

    printf("\n[Read file 'test.txt']\n");

    fp = fopen("C:\\Users\\�ظ�\\Documents\\GitHub\\ProgramingCJUAE101\\10st_week\\test.txt", "r");
    //������ test.txt ������ ���� �������� ����
    char read[100];     //���� ������ ����ϱ� ���� ���ڿ� ����

    if (fp != NULL) 
    {
        while (!feof(fp))   //������ ��� �о����� Ȯ��
        {
            fgets(read, 100, fp);   //fp ������ �����͸� read ���ڿ��� �޾ƿ�
            printf(read);           //read ���
        }
        fclose(fp); //���� �ݱ�
    }

    return 0;
}