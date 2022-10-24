#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	typedef struct vector
	{
		int* data;
		int size;
	} vector;

	vector* v = (vector*) malloc(sizeof(vector));
	v->data = (int*) malloc(sizeof(int));
	v->size = 0;

	for (size_t i = 1; i < argc; i++)
	{
		v->size += 1;
		v->data = (int*) realloc(v->data, sizeof(int) * v->size);
		v->data[v->size - 1] = atoi(argv[i]);
		printf("New data: %d\n", v->data[v->size - 1]);
	}
	
	free(v->data);
	free(v);
	return 0;
}
