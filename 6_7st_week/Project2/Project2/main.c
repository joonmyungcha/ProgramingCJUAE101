#include <stdio.h>
#include <stdlib.h>     //rand ÇÔ¼ö »ç¿ëÇÏ±â À§ÇÔ
#include <time.h>       //½Ã°£¿¡ µû¸¥
#include <math.h>       //pow, sqrt ÇÔ¼ö »ç¿ëÇÏ±â À§ÇÔ

#define Length 10       //¹è¿­ÀÇ Å©±â ÁöÁ¤
#define Max_Num 10      //¹«ÀÛÀ§ Ãâ·Â Á¤¼öÀÇ ÃÖ´ë°ª ÁöÁ¤
#define End_sys 1

void GenRandSeed();     //½Ã°£¿¡ µû¶ó ¹«ÀÛÀ§ Á¤¼ö°¡ ¹Ù²î±â À§ÇÑ ÇÔ¼ö 
void Input_Rand_Num(int* num, int SIZE);    //¹«ÀÛÀ§ Á¤¼ö¸¦ ¹è¿­¿¡ »ı¼ºÇÏ±â À§ÇÑ ÇÔ¼ö
double average(int* num, int SIZE);         //¹è¿­ÀÇ °¢ ÀÎµ¦½º °ªµéÀÇ Æò±ÕÀ» ±¸ÇÏ±â À§ÇÑ ÇÔ¼ö
double variance(int* num, int SIZE, double avg);    //ºĞ»ê ±¸ÇÏ´Â ÇÔ¼ö
double std_deviation(int* num, int SIZE, double var);   //Ç¥ÁØÆíÂ÷ ±¸ÇÏ´Â ÇÔ¼ö

int main(void)
{
    int ary[Length];   //ÀÏÁ¤ Å©±âÀÇ ¹è¿­ ¼±¾ğ
    double avg = 0, var = 0, std = 0;   //½Ç¼öÇüÀÇ Æò±Õ, ºĞ»ê, Ç¥ÁØÆíÂ÷ ÃÊ±âÈ­
    int input_run = 0;			//ÀÔ·Â»óÈ²  ¿¹¿ÜÃ³¸®
    printf("Input 1 to run. If you put another character, this system will end.\n");
    scanf_s("%d", &input_run);
    if (input_run == End_sys)
    {
        printf("length of array : %d\n", Length);    
        printf("Create an array of %d random integers.\n", Length);
        
        GenRandSeed();      //½Ã°£¿¡ µû¶ó ¹Ù²î´Â ¹«ÀÛÀ§ Á¤¼ö ÇÔ¼ö È£­‚
        Input_Rand_Num(ary, Length);    //¹«ÀÛÀ§ Á¤¼ö¸¦ ¹è¿­¿¡ »ı¼ºÇÏ´Â ÇÔ¼ö È£Ãâ
       
        avg = average(ary, Length);     //¹è¿­ÀÇ Æò±Õ ±¸ÇÏ´Â ÇÔ¼ö È£Ãâ 
        var = variance(ary, Length, avg);      //¹è¿­ÀÇ ºĞ»ê ±¸ÇÏ´Â ÇÔ¼ö È£Ãâ
        std = std_deviation(ary, Length, var);  //¹è¿­ÀÇ Ç¥ÁØÆíÂ÷ ±¸ÇÏ´Â ÇÔ¼ö È£Ãâ

        printf("average : %.3lf, variance : %.3lf, std_deviation : %.3lf", avg, var, std);  //¼Ò¼öÁ¡ 3ÀÚ¸®±îÁö °á°ú°ª Ãâ·Â
    }
    else
    {
        printf("End system.");
    }

    return 0;
}

void GenRandSeed()      //ÇÔ¼ö Á¤ÀÇ, ¹«ÀÛÀ§ Á¤¼ö°¡ ½Ã°£¿¡ µû¶ó ¹Ù²î°Ô ÇØÁÜ. ÀÌ ÇÔ¼ö ¾øÀ» ½Ã °è¼Ó °°Àº Á¤¼ö°¡ Ãâ·ÂµÊ
{
    srand((unsigned int)(time(NULL)));      
}



void Input_Rand_Num(int* num, int SIZE)     //¹è¿­ÀÇ °¢ ÀÎµ¦½º¿¡ ¹«ÀÛÀ§ Á¤¼ö¸¦ »ı¼ºÇÏ´Â ÇÔ¼ö 
{
    for (int i = 0; i < SIZE; i++)                      //0~9 ¹è¿­¿¡ ¹İº¹¹®À¸·Î ³Ö¾îÁÜ
    {
        num[i] = ((unsigned int)rand() % Max_Num);      //unsigned : ¾ç¼ö°ªÀ» ¹Ş±â À§ÇÔ, Max_NumÀº »ı¼ºÇÒ ¼ö ÀÖ´Â Á¤¼öÀÇ ÃÖ´ë Å©±â
        printf("%dth number in the array : %d\n", i + 1, num[i]);   //i´Â 0À¸·Î ÃÊ±âÈ­ ÇÏ¿´°í, 1¹øÂ° ¼ıÀÚºÎÅÍ ³ª¿À¹Ç·Î i+1
    }

}


double average(int* num, int SIZE)      //Æò±Õ ±¸ÇÏ´Â ÇÔ¼ö Á¤ÀÇ
{
    double res = 0;
    
    for (int i = 0; i < SIZE; i++)
    {
        res += num[i];  //¹è¿­ÀÇ ¸ğµç ÀÎµ¦½º °ªÀ» ´õÇÑ °ª
    }

    res /= SIZE;    //¹è¿­ÀÇ Å©±â·Î ³ª´®

    return res;     //res·Î ¹İÈ¯
}


double variance(int* num, int SIZE, double avg)     //ºĞ»ê ±¸ÇÏ´Â ÇÔ¼ö Á¤ÀÇ
{
    double res = 0;

    for (int i = 0; i < SIZE; i++)
    {
        res += pow(num[i] - avg, 2);    // ºĞ»ê °è»êÇÏ´Â ÇÔ¼ö pow »ç¿ë ,pow(2,3)Àº 2^3À» ÀÇ¹ÌÇÔ.
    }

    res /= SIZE;

    return res;
}


double std_deviation(int* num, int SIZE, double var)
{
    double res = 0;

    res = sqrt(var);                // Ç¥ÁØÆíÂ÷ °è»êÇÏ´Â ÇÔ¼ö sqrt »ç¿ë, ºĞ»êÀÇ 1/2Á¦°ö, sqrt´Â ·çÆ®¸¦ ÀÇ¹Ì

    return res;
}