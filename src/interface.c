#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>

int interact (char string[]){
	setlocale(LC_ALL, "Rus");
	int j = 0, size = 0;
    char tmp[260];
    char namein[260];
    printf("Добро пожаловать в программу Алфавит.\n");
	printf("Введите название файла для ввода строки:");
    scanf("%s", &tmp);
	OemToChar(tmp, namein);
	FILE *fp = fopen (namein, "r");
	if(fp == NULL){
		printf("Ошибка: файл некорректен.");
		return -2;
		}
	for (j=0; j < 260; j++){
		fscanf (fp, "%c", &string[j]);
		if (string[j] == ' ')
			size++;
		if (string[j] == '\n')
			string[j] = '\0';
	}
		printf("Исходная строка:%s", string);
	fclose(fp);	
	return size;
}
