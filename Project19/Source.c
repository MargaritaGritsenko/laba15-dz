#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#define N 20
#define M 12
int massive(int ptr_array[][M]);
int print_massive(double ptr_array[][M], const char * familii[N], const char* month[M]);
main()
{
	setlocale(LC_ALL, "EN");
	setlocale(LC_ALL, "RU");
	int array[N][M], menu=10;
	const char * familii[N] = {"1)Ivanov", "2)Petrov", "3)Sidorov", "4)Igorev", "5)Smirnov", "6)Popov ", "7)Morozov", "8)Andreev", "9)Volkov", "10)Stepin", "11)Alehin", "12)Lebedev", "13)Makarov", "14)Nikitin", "15)Kozlova", "16)Zotova", "17)Popova","18)Zuzina", "19)Bokova", "20)Mishins"};
	const char * month[M] = {"January ", "February", " March", "   April", "    May  ", "  June ", "   July ", "  August", " September", " October", " November", " December"};
	srand(time(NULL));
	massive(array);
	while (menu != 0)
	{
		printf("1-показать таблицу\n2-вывести годовую зарплату человека по номеру в списке\n0-выход\n");
		scanf("%d", &menu);
		switch (menu)
		{
		case 1:
			print_massive(array, familii, month);
			break;
		case 2:
			zarplata(array);
			break;
		}
	}
}
int massive(int ptr_array[][M])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			(*(*(ptr_array + i) + j)) =10000+rand();
		}
	}
}
int print_massive(int ptr_array[][M], const char * familii[N], const char * month[M])
{
	printf("\t\t");
	for (int k = 0; k < M; k++) {
		char* ptr = month[k];
		while (*ptr)
		{
			printf("%c", *ptr);
			ptr++;
		}
	}
	printf("\n");
	printf("____");
	for (int k = 0; k < M; k++)
	{
		printf("_________");
	}
	for (int i = 0; i < N; i++)
	{
		printf("\n");
		char* ptr = familii[i];
		while (*ptr)
		{
			printf("%c", *ptr);
			ptr++;
		}
		printf("\t|");
		for (int j = 0; j < M; j++)
		{
			printf(" %d", *(*(ptr_array + i) + j));
			printf("\t");
		}
	}
	printf("\n");
}
int zarplata(int ptr_array[][M])
{
	int ind, sum=0;
	printf("Введите номер человека из списка:");
	scanf("%d", &ind);
	for (int j = 0; j < M; j++)
	{
		sum += *(*(ptr_array + ind) + j);
	}
	printf("%d\n", sum);
}