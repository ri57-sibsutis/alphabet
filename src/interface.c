#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>

int interact (char string[]){
	setlocale(LC_ALL, "Rus");
	int j = 0, size = 0;
    char tmp[260];
    char namein[260];
    printf("����� ���������� � ��������� �������.\n");
	printf("������� �������� ����� ��� ����� ������:");
    scanf("%s", &tmp);
	OemToChar(tmp, namein);
	FILE *fp = fopen (namein, "r");
	if(fp == NULL){
		printf("������: ���� �����������.");
		return -2;
		}
	for (j=0; j < 260; j++){
		fscanf (fp, "%c", &string[j]);
		if (string[j] == ' ')
			size++;
		if (string[j] == '\n')
			string[j] = '\0';
	}
		printf("�������� ������:%s", string);
	fclose(fp);	
	return size;
}

void out (char *ptr[], int size){
	int j = 0;
	setlocale(LC_ALL, "Rus");
	printf("\n���������� ����:%d", size);
	printf("\n����� ���� �� ������:");
	for (j = 0; j < size; j++)
		printf("\n%s", ptr[j]);
}