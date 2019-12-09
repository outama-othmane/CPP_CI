#include <iostream>

using namespace std;

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
	
	//	Si on define les fonctions friend a l'interieur de Vecteur3D le 'warning' disparu.
	//friend ostream& operator <<(ostream&, Vecteur3D<T>&);
	
	//friend istream& operator >>(istream&, Vecteur3D<T>&);
	
	friend ostream& operator <<(ostream& a, Vecteur3D<T>& vect)
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
	
	friend istream& operator >>(istream& input, Vecteur3D<T>& vect)
	{
		cout << "Entrer abs: ";
		input >> vect.abs;
		cout << "Entrer ord: ";
		input >> vect.ord;
		cout << "Entrer cote: ";
		input >> vect.cote;
		return input;
	}
};

int main ()
{
	Vecteur3D <int> V(1, 2, 3);
	cout << V;
}


