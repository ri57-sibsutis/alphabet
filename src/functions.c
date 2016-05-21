#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int schr(char str[], char ch) {
	int i;
	int idx = -1;
	for (i=0; (str[i] != '\0') && (str[i] != ch); i++);
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

int crop(char string[], char *fstring) {
	int j = 0, i = 0;
	while (string[j] != '\0') {
		if ((string[j] >= 'A' && string[j] <= '?') || (string[j] >= 'a' && string[j] <= 'i') || (string[j] >= '?' && string[j] <= 'y') || string[j] == ' ') {
			fstring[i] = string[j];
			i++;
		}
		j++;
	}
	fstring[i] = '\0';
	return 1;
}

int sort(char *ptr[], int size) {
	char *mstmp;
	char *mstmp2;
	char *chtmp;
	char *chtmp2;
	int i = 0, j = 0;
	for (i = 0; i < (size -1); ++i) {//eiee?anoai io?iuo i?ioiaia ii ianneao aey iaoi?aaiey
		for(j = 0; j < (size - 1); ++j) {
			mstmp = ptr[j];
			mstmp2 = ptr[j + 1];
			if (mstmp2[0] < mstmp[0]) {
			//	if((mstmp[0] >= 'A' && mstmp[0] <= '?') && !(mstmp2[0] >= 'A' && mstmp2[0] <= '?')){
				//	}
				chtmp2 = ptr[j + 1];
				chtmp = ptr[j];
				ptr[j + 1] = chtmp;
				ptr[j] = chtmp2;
			}
		}
	}
	return 1;
}
