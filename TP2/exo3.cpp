#include <iostream>
#define carre(x) x*x

using namespace std;

inline int carreCpp(int a)
{
	return a*a;
}

int main(int argc, char const *argv[])
{
	int a = 2;

	cout << carre(a) << endl;// Resultat correct.
	
	// Importent !!!	
	// il va remplacer carre(a+2) avec a+2*a+2 = 8 :)	
	cout << carre(a+2) << endl;// Resultat incorrect :( 

	// Question 3
	cout << carreCpp(a) << endl;// Resultat correct.

	cout << carreCpp(a+2);// Resultat correct.

	return 0;
}
