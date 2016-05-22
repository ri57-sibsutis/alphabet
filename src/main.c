#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main()
{	
    int size = 0, a = 0;
    char string[260];
    char fstring[260];
       printf("Choose your interface language:\nType 1 for English.\nType 2 for Russian.\n");
    scanf("%d", &a);
    if ((a != 1) && (a != 2)){
    	printf("Wrong language input.");
    	return -1;
    }
	size = interact(string, a) + 1;
	if (size == 0)
		return 0;
	char *ptr[size];
	crop(string, fstring);
	stok(fstring, ptr);
	sort(ptr, size);
	out(ptr, size, a);
	getchar();
	getchar();
    return 0;
}