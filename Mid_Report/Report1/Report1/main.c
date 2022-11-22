#include <stdio.h>
#define row 3                   //������������ 2���� �迭 ��ķ� ǥ���ϱ� ���� ��� �� ����, �������� 3���� ���� ���������� ����
#define column 3                
#define res_column 4            //������ ������� ������ ���� �� ����
#define End_sys 1               //1 �Է� �� �ý��� �����ϱ� ���� ��� ����
 
void input_form(double mat[row][res_column]);       //3���� ���������������� �Է��ϴ� �Լ�
double det_Matrix(double mat[row][column]);         //����� �� ����ϴ� �Լ�
void findSolution(double mat[row][res_column]);     //ũ���� ������ ����Ͽ� ������������ �ظ� ���ϴ� �Լ�

int main(void)
{
    int input_run = 0;
    printf("Input 1 to run. If you put another character, this system will end.\n");		//�Է»�Ȳ ����ó��
    scanf_s("%d", &input_run);

    if (input_run == End_sys)
    {
        printf("\nCramer's Rule\n\n");

        double equation[row][res_column];                //ũ���� ������ ����Ͽ� 3���� ���������������� Ǯ�� ���� 2���� �迭 ����

        input_form(equation);                            //3���� ���������������� �Է��ϴ� �Լ� ȣ��

        printf("three systems of equations :\n");        //�Է��� 3���� �������������� ���
        printf("(%.2lf)x+(%.2lf)y+(%.2lf)z= (%.2lf)\n", equation[0][0], equation[0][1], equation[0][2], equation[0][3]);
        printf("(%.2lf)x+(%.2lf)y+(%.2lf)z= (%.2lf)\n", equation[1][0], equation[1][1], equation[1][2], equation[1][3]);
        printf("(%.2lf)x+(%.2lf)y+(%.2lf)z= (%.2lf)\n", equation[2][0], equation[2][1], equation[2][2], equation[2][3]);
        printf("\n");

        findSolution(equation);                         //ũ���� ������ ����Ͽ� ������������ �ظ� ���ϴ� �Լ� ȣ��
    }
    else
    {
        printf("End system.");
    }
    return 0;
}




void input_form(double mat[row][res_column])        //�Լ� ����
{
    printf("Equation form : ax + by + cz = res\n"); //���������������� ����

    for (int i = 0; i < row; i++)                   //��ø for���� ����Ͽ� 2���� �迭�� �������������� 3���� �Է¹���.
    {
        printf("Input %dst equation form : a, b, c, res\n", i + 1);
        for (int j = 0; j < res_column; j++)
        {
            scanf_s("%lf", &mat[i][j]);
        }
    }
    printf("\n");
}

double det_Matrix(double mat[row][column])          //3*3 ����� ���� ���ϴ� �Լ� ����
{
    double ans;

    ans = mat[0][0] * (mat[1][1] * mat[2][2] - mat[2][1] * mat[1][2])
        - mat[0][1] * (mat[1][0] * mat[2][2] - mat[1][2] * mat[2][0])
        + mat[0][2] * (mat[1][0] * mat[2][1] - mat[1][1] * mat[2][0]);

    return ans;
}

void findSolution(double mat[row][res_column])      //ũ���� ���� �Լ� ����
{
    double d[row][column] = {                       //�տ��� �Է¹��� 3���� ���������������� a, b, c�� ��ķ� ǥ��

        { mat[0][0], mat[0][1], mat[0][2] },
        { mat[1][0], mat[1][1], mat[1][2] },
        { mat[2][0], mat[2][1], mat[2][2] },

    };
       
    printf("Matrix d :\n");                         //d ��� ���
    for (int i = 0; i < row; i++)                   
    {    
        for (int j = 0; j < column; j++)
        {
            printf("%.2lf\t", d[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    double d1[row][column] = {                      //d ��� 1���� ������� ���� d1 ��ķ� ǥ��

        { mat[0][3], mat[0][1], mat[0][2] },
        { mat[1][3], mat[1][1], mat[1][2] },
        { mat[2][3], mat[2][1], mat[2][2] },

    };

    printf("Matrix d1 :\n");                        //d1 ��� ���
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            printf("%.2lf\t", d1[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    double d2[row][column] = {                      //d ��� 2���� ������� ���� d2 ��ķ� ǥ��

        { mat[0][0], mat[0][3], mat[0][2] },
        { mat[1][0], mat[1][3], mat[1][2] },
        { mat[2][0], mat[2][3], mat[2][2] },

    };

    printf("Matrix d2 :\n");                        //d2 ��� ���
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            printf("%.2lf\t", d2[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    double d3[row][column] = {                      //d ��� 3���� ������� ���� d3 ��ķ� ǥ��

        { mat[0][0], mat[0][1], mat[0][3] },
        { mat[1][0], mat[1][1], mat[1][3] },
        { mat[2][0], mat[2][1], mat[2][3] },

    };

    printf("Matrix d3 :\n");                        //d3 ��� ���
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            printf("%.2lf\t", d3[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    double D = det_Matrix(d);                       //d, d1, d2, d3 ����� �� ���
    double D1 = det_Matrix(d1);
    double D2 = det_Matrix(d2);
    double D3 = det_Matrix(d3);

    printf("Matrix value\n");
    printf("d : %.2lf \td1 : %.2lf \td2 : %.2lf \td3 : %.2lf \n\n", D, D1, D2, D3);     //����� �� ������ ���
  
    if (D != 0)                                     //d ���� 0�� �ƴ� ��
    {
        double x = D1 / D;                          //x, y, z �� ���
        double y = D2 / D;
        double z = D3 / D; 

        printf("x = d1 / d\ny = d2 / d\nz = d3 / d\n\n");
        printf("result\nx : %.2lf\ty : %.2lf\tz : %.2lf\n\n", x, y, z);     //x, y, z �� ���
    }

    else                                           //d ���� 0�� ��
    {
        if (D1 == 0 && D2 == 0 && D3 == 0)          // d1, d2, d3 ����� ������ ��� 0�� ��

            printf("result : Infinite solutions\n");//������ ���� �ظ� ����

        else if (D1 != 0 || D2 != 0 || D3 != 0)     // d1, d2, d3 ����� ������ �ϳ��� 0�� �ƴ϶��

            printf("result : No solutions\n");      //�������� ��ġ���� �ʾ� �ذ� ����.
    }
}