#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define m 2     //ÇàÀÇ °³¼ö ÁöÁ¤
#define n 3     //¿­ÀÇ °³¼ö ÁöÁ¤
#define Max_Num 10      //¹«ÀÛÀ§ Á¤¼öÀÇ ÃÖ´ë°ª ÁöÁ¤
#define End_sys 1

void GenRandSeed();     //½Ã°£¿¡ µû¶ó ¹«ÀÛÀ§ Á¤¼ö°¡ ¹Ù²î±â À§ÇÑ ÇÔ¼ö 
void matrix_mul(int A[][n], int B[][m]);        //Çà·Ä °ö¼ÀÀ» À§ÇÑ ÇÔ¼ö
void input_A(int A[][n], int row, int column);  //2Â÷¿ø ¹è¿­¿¡ ¹«ÀÛÀ§ Á¤¼ö »ı¼ºÇÏ´Â ÇÔ¼ö
void input_B(int B[][m], int row, int column); 

int main(void)
{
    int input_run = 0;			//ÀÔ·Â»óÈ² ¿¡¿ÜÃ³¸®
    printf("Input 1 to run. If you put another character, this system will end.\n");
    scanf_s("%d", &input_run);

    if (input_run == End_sys)
    {
        printf("rows and columns of the first matrix : %d*%d\n", m, n); //Çà·ÄÀÇ Çà°ú ¿­ ¼ö Ãâ·Â
        printf("rows and columns of the Second matrix : %d*%d\n", n, m);

        int Matrix_A[m][n] = { 0 }; //¹«ÀÛÀ§ Á¤¼ö ÀÔ·Â¹ŞÀ» 2Â÷¿ø ¹è¿­ ¼±¾ğ ¹× ÃÊ±âÈ­
        int Matrix_B[n][m] = { 0 };

        GenRandSeed();      //½Ã°£¿¡ µû¶ó ¹Ù²î´Â ¹«ÀÛÀ§ Á¤¼ö ÇÔ¼ö È£­‚

        input_A(Matrix_A, m, n);    //¹è¿­¿¡ ¹«ÀÛÀ§ Á¤¼ö »ı¼ºÇÏ´Â ÇÔ¼ö È£Ãâ
        input_B(Matrix_B, n, m);

        printf("First Matrix : \n");  //2Â÷¿ø ¹è¿­ A Çà°ú ¿­ ¹İº¹ÇÏ¸ç Ãâ·Â
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                printf("%d\t", Matrix_A[i][j]);
            }
            printf("\n");
        }
        printf("\n");

        printf("Second Matrix : \n");  //2Â÷¿ø ¹è¿­ B Çà°ú ¿­ ¹İº¹ÇÏ¸ç Ãâ·Â
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                printf("%d\t", Matrix_B[i][j]);
            }
            printf("\n");
        }
        printf("\n");

        matrix_mul(Matrix_A, Matrix_B); //¹è¿­ A¿Í B °öÇÏ´Â ÇÔ¼ö È£Ãâ
    }
    else
    {
        printf("End system.");
    }

    return 0;
}


void GenRandSeed()  //ÇÔ¼ö Á¤ÀÇ
{
    srand((unsigned int)(time(NULL)));
}

void input_A(int A[][n], int row, int column)   //2Â÷¿ø ¹è¿­ A¿¡ ¹«ÀÛÀ§ Á¤¼ö »ı¼ºÇÏ´Â ÇÔ¼ö Á¤ÀÇ
{
    for (int i = 0; i < row; i++)   //¹İº¹¹®À» »ç¿ëÇÏ¿© ÇàÀ» ¹İº¹
    {
        for (int j = 0; j < column; j++)    //ÇÏ³ªÀÇ Çà ¾È¿¡¼­ ¿­ ¹İº¹
        {
            A[i][j] = ((unsigned int)rand() % Max_Num); //°¢ ÁÂÇ¥°ª¿¡ ¹«ÀÛÀ§ Á¤¼ö »ı¼º
        }
    }
}

void input_B(int B[][m], int row, int column)   //¹è¿­ B¿¡ ¹«ÀÛÀ§ Á¤¼ö »ı¼º
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            B[i][j] = ((unsigned int)rand() % Max_Num);
        }
    }
}

void matrix_mul(int A[][n], int B[][m]) //µÎ 2Â÷¿ø ¹è¿­ Çà·ÄÀÇ °ö¼À ¿¬»ê ¹× Ãâ·Â Á¤ÀÇ
{
    int S[m][m];    //°á°ú°ªÀÎ 2*2 Çà·Ä ¼±¾ğ

    for (int i = 0; i < m; i++) 
    {
        for (int j = 0; j < m; j++)
        {
            S[i][j] = 0;        

            for (int k = 0; k < n; k++)
            {
                S[i][j] += A[i][k] * B[k][j];   //°¢ Çà°ú ¿­À» ¹İº¹ÇÏ¿© °öÇÑ ÈÄ ´õÇÑ °ªÀ» ¹è¿­ S¿¡ ´ëÀÔ
            }
        }
    }

    printf("Multiplication of first matrix and second matrix : \n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d\t", S[i][j]);    //3*3 ¹è¿­ Çà°ú ¿­ ¹İº¹ÇÏ¸ç ¹è¿­ Ãâ·Â
        }
        printf("\n");
    }
}