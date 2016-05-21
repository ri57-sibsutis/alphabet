#include <stdio.h>
#include <stdlib.h>

int schr(char string[]) {
	int i;
	int idx = -1;
	for (i=0; string[i] != '\0' && !((string[i] >= 'A' && string[i] <= '?') || (string[i] >= 'a' && string[i] <= 'i') || (string[i] >= '?' && string[i] <= 'y')); i++);
		if ((string[i] >= 'A' && string[i] <= '?') || (string[i] >= 'a' && string[i] <= 'i') || (string[i] >= '?' && string[i] <= 'y'))
			idx = i;
	return idx;
}

int stok(char str[], char *ptr[]) {
	char *suf = str;
	ptr[0] = str;
	int i, j = 1;
	while ((i = schr(suf)) >= 0) {
		suf[i] = '\0';
		suf = suf + i + 1;
		ptr[j] = suf;
		j++;
	}
	return j;
}