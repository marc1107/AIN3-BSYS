#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int dataSize = 100;
	int* data = (int*) malloc(sizeof(int) * dataSize);
	data[5] = 20;
	free(&data[5]);
	printf("Data[5]: %d\n", data[5]);
	return 0;
}
