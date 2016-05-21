#include <stdio.h>
#include <stdlib.h>

int schr(char str[], char ch) {
	int i;
	int idx = -1;
	for (i = 0; (str[i] != '\0') && (str[i] != ch); i++);
		if (str[i] == ch)
		idx = i;
	return idx;
}

int stok(char str[], char *ptr[]) {
	char *suf = str;
	ptr[0] = str;
	int i, j = 1;
	char delim = ' ';
	while ((i = schr(suf, delim)) >= 0) {
		suf[i] = '\0';
		suf = suf + i + 1;
		ptr[j] = suf;
		j++;
	}
	return j;
}