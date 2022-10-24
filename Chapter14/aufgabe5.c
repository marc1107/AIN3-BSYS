#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int dataSize = 100;
	int* data = (int*) malloc(sizeof(int) * dataSize);
	data[100] = 0;
	return 0;
}
