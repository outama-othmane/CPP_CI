#include <iostream>

using namespace std;

template <typename T> class Vecteur3D;
template <typename T> ostream& operator <<(ostream& a, Vecteur3D<T>& vect)
{
	a << "(";
	a << vect.abs;
	a << ", ";
	a << vect.ord;
	a << ", ";
	a << vect.cote;
	a << ")\n";
	return a;
}

template <typename T> class Vecteur3D
{
	T abs, ord, cote;
	public:
	Vecteur3D (T abs,T ord,T cote)	
	{
		this->abs 	= abs;
		this->ord 	= ord;
		this->cote 	= cote;
	}
	
	void affiche()
	{
		cout << abs << endl;
		cout << ord << endl;
		cout << cote << endl;
	}
	
	friend ostream& operator <<<T>(ostream&, Vecteur3D<T>&);
};

int main ()
{
	Vecteur3D <int> V(1, 2, 3);
	cout << V;
}


