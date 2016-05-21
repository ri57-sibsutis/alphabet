#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()//aaia iacaaiey i?iecaiaeony ia aiaeeeneii oieuei
{
	setlocale(LC_ALL, "Rus");
	int j = 0, size = 0, a = 0;
	char string[260];
	char name[260] = "file.txt";
	char name2[260];
	printf("Aia?i ii?aeiaaou a i?ia?aiio Aeoaaeo.\n");
//	printf("Aaaaeoa iacaaiea oaeea aey aaiaa no?iee:");
//	scanf("%s", &name);
	FILE *fp = fopen(name, "r");
	if(fp == NULL)
		printf("\nIoeaea: oaee iaei??aeoai\n");
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
	for (j = 0; string[j] != '\0'; j++)//a ii?yaea aic?anoaiey cia?aiey aoeau a eioiaii eiaa
		if ((string[j] >= 'A' && string[j] <= '?') || (string[j] >= 'a' && string[j] <= 'i') || (string[j] >= '?' && string[j] <= 'y')) {
			a++;
		}
	printf("\n%d", a);
	stok(string, ptr);
	printf("\n%s\t%s", ptr[0], ptr[1]);
	return 0;
}