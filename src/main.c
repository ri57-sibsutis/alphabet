#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>

int main()//aaia iacaaiey i?iecaiaeony ia aiaeeeneii oieuei
{	
   setlocale(LC_ALL, "Rus");
    int j = 0, size = 1, a = 0;
    char string[260];
    char fstring[260];
    char tmp[260];
    char namein[260];
    printf("Aia?i ii?aeiaaou a i?ia?aiio Aeoaaeo.\n");
	printf("Aaaaeoa iacaaiea oaeea aey aaiaa no?iee:");
	scanf("%s", &tmp);
	OemToChar(tmp, namein);
	FILE *fp = fopen (namein, "r");
	if(fp == NULL)
		printf("\nIoeaea: oaee iaei??aeoai\n");
	for (j=0; j<260; j++){
		fscanf (fp, "%c", &string[j]);
		if (string[j]=='\n')
			string[j] = '\0';
	}
	fclose(fp);	
	printf("%s", string);
	for (j = 0; string[j] != '\0'; j++){
		if (string[j] == ' ')
			size++;
	}
	char *ptr[size];
	printf("\n?enei neia:%d\n", size);
	crop(string, fstring);
	stok(fstring, ptr);
	sort(ptr, size);
	printf("Iiaay no?iea:");
	for (j = 0; j < size; j++)
		printf(" %s", ptr[j]);
    return 0;
}
