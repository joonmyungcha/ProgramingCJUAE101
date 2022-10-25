#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define m 4
#define n 3
void input(int* num1, int* num2);

int main(void)
{	
	int A[4][3] = { 0 };
	int B[3][4] = { 0 };
	input




}

void input(int* num1, int* num2)
{ 
	
	srand((unsigned)time(NULL));
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			num1[i][j] = rand() % 10;
		}
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			num2[i][j] = rand() % 10;
		}
}