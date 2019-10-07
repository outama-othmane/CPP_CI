#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	double a, b, c, delta;

	cout << "Entrer a, b et c de votre equation (ax²+bx+c) : " << endl;

	cout << "a  = " ;
	cin >> a;

	cout << "b  = " ;
	cin >> b;

	cout << "c  = " ;
	cin >> c;

	if (a == 0 && b == 0)
	{
		if (c == 0)
		{
			cout << "L\'equation admet une infinite de solutions.\n";
			return 0;
		}
		cout << "L\'equation n\'admet aucune solution.\n";
		return 0;
	}

	if (a == 0)
	{
		cout << "L\'equation admet une solution : \n";
		cout << "x = " << -c/b;
		return 0;
	}

	delta = (b*b) - (4 * a * c);

	if (delta > 0)
	{
		cout << "L\'equation admit 2 solutions : \n";
		cout << "x1 = " << (-b + sqrt(delta)) / (2 * a) << endl;
		cout << "x2 = " << (-b - sqrt(delta)) / (2 * a) << endl;
	}

	else if (delta == 0)
	{
		cout << "L\'equation admit un solution : \n";
		cout << "x = " << (-b) / (2 * a) << endl;
	}
	else
		cout << "L\'equation n\'admit pas de solution dans R : \n";

	return 0;
}
