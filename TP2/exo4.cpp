#include <iostream>

using namespace std;

void fct(int, int = 15); // prototype

int main()
{
	int n = 10, p = 20;
	fct(n,p); // appel normal
	fct(n); // appel avec un seul argument
	system("Pause");
	return 0;
}

void fct( int a, int b)
{
	cout << "Argument 1 : " << a << " ";
	cout << "Argument 2 : " << b << endl;
}
