#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include "interface.h"

int main()
{	
    	int j = 0, size = 0, a = 0;
    	char string[260];
    	char fstring[260];
	size = interact(string) + 1;
	if (size == 0)
		return 0;
	char *ptr[size];
	crop(string, fstring);
	stok(fstring, ptr);
	sort(ptr, size);
	out(ptr, size);
    	return 0;
}