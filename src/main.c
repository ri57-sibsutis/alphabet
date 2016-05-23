#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main()
{	
    int b = 0, a = 0;
    char string[260];
    char fstring[260];
    if ((a = in()) == -1)
    	return -1;
	if ((b = interact(string, a) + 1) == 0)
		return 0;
	char *ptr[b];
	crop(string, fstring);
	stok(fstring, ptr);
	sort(ptr, b);
	out(ptr, b, a);
	getchar();
	getchar();
    return 0;
}