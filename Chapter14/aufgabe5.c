#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int dataSize = 100;
	int* data = (int*) malloc(sizeof(int) * dataSize);
	if (data == NULL){
		printf("Alloc fehlgeschlagen\n");
		exit(1);
	}
	data[100] = 0;
	return 0;
}
