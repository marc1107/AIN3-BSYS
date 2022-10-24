#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
	int* intptr = (int*) malloc(sizeof(int));
	intptr = NULL;
	printf("intptr: %d\n", *intptr);
	free(intptr);
	return 0;
}