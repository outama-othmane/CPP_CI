#include <iostream>

using namespace std;

int somme(float a, float b)
{
	return a+b;
}

void permute(int* a, int* b)
{
	int ref = *a;
	*a = *b;
	*b = ref;
}
