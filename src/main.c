#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()//���� �������� ������������ �� ���������� ������
{
	setlocale(LC_ALL, "Rus");
	int j = 0, size = 1, a = 0;
	char string[260];
	char fstring[260];
	char name[260] = "file.txt";
	char name2[260];
	printf("����� ���������� � ��������� �������.\n");
//	printf("������� �������� ����� ��� ����� ������:");
//	scanf("%s", &name);
	FILE *fp = fopen(name, "r");
	if(fp == NULL)
		printf("\n������: ���� �����������\n");
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
	for (j = 0; string[j] != '\0'; j++)//� ������� ����������� �������� ����� � ������� ����
		if ((string[j] >= '�' && string[j] <= '�') || (string[j] >= '�' && string[j] <= '�') || (string[j] >= '�' && string[j] <= '�')) {
			a++;
		}
	printf("\n%d", a);
	crop(string, fstring);
	stok(fstring, ptr);
    return 0;
}
