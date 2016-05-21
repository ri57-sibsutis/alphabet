#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()//ввод названия производится на английском только
{
	setlocale(LC_ALL, "Rus");
	int j = 0, size = 1, a = 0;
	char string[260];
	char fstring[260];
	char name[260] = "file.txt";
	char name2[260];
	printf("Добро пожаловать в программу Алфавит.\n");
//	printf("Введите название файла для ввода строки:");
//	scanf("%s", &name);
	FILE *fp = fopen(name, "r");
	if(fp == NULL)
		printf("\nОшибка: файл некорректен\n");
	for (j = 0; j < 260; j++) {
		fscanf(fp, "%c", &string[j]);
		if (string[j] == '\n')
			string[j] = '\0';
	}
	fclose(fp);
	printf("%s", string);
	for (j = 0; string[j] != '\0'; j++) {
		if (string[j] == ' ')
			size++;
	}
	char *ptr[size];
	for (j = 0; string[j] != '\0'; j++)//в порядке возрастания значения буквы в интовом коде
		if ((string[j] >= 'А' && string[j] <= 'Я') || (string[j] >= 'а' && string[j] <= 'п') || (string[j] >= 'р' && string[j] <= 'я')) {
			a++;
		}
	printf("\n%d", a);
	crop(string, fstring);
	stok(fstring, ptr);
    return 0;
}
