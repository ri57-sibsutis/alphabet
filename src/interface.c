#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>

int interact (char *string){
	setlocale(LC_ALL, "Rus");
	int j = 0, size = 0;
    char tmp[260];
    char namein[260];
    printf("\t\t����� ���������� � ��������� �������.\n");
	printf("������� �������� ����� ��� ����� ������:");
    do{
		if (j > 260)
			return j;
		scanf("%c", &tmp[j]);
		j++;
	} while (tmp[j - 1]!='\n');
	tmp[j-1] = '\0';
	OemToChar(tmp, namein);
	FILE *fp = fopen (namein, "r");
	if(fp == NULL){
		printf("������: ���� �����������.");
		return -1;
		}
	fscanf (fp, "%c", &string[0]);
	if ((string[0] == '\n') || (string[0] == ' ')){
		printf("������: ������ �����������");
		return -1;
		}
	j = 1;
    do{
		if (j > 260)
			return j;
		fscanf (fp, "%c", &string[j]);
		if (string[j] == ' ')
			size++;
		j++;
	} while (string[j - 1] != '\n');
	string[j-1] = '\0';
	
	printf("�������� ������:%s", string);
	fclose(fp);	
	return size;
}

void out (char *ptr[], int size){
	int j = 0;
	setlocale(LC_ALL, "Rus");
	printf("\n���������� ����:%d", size);
	printf("\n����� ��������������� ���� �� ������:");
	for (j = 0; j < size; j++)
		printf("\n%s", ptr[j]);
}