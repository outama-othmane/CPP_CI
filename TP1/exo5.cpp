#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int tab[] = {0, 1, 2, 0, 4, 0, 7};
	const int N = sizeof(tab) / sizeof(int);
	int* ptr = tab;

	while(ptr != &tab[N])
	{
		if ( ! *ptr )	cout << ptr - tab << endl;
		ptr++;
	}

	return 0;
}
