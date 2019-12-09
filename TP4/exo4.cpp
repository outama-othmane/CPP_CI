#include <iostream>

using namespace std;

class Vecteur3D
{
	float abs, ord, cote;
	public:
	Vecteur3D (float abs,float ord,float cote)	
	{
		this->abs 	= abs;
		this->ord 	= ord;
		this->cote 	= cote;
	}
	
	friend ostream& operator <<(ostream&, Vecteur3D&);
	
	friend istream& operator >>(istream&, Vecteur3D&);
};

ostream& operator <<(ostream& a, Vecteur3D& vect)
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

istream& operator >>(istream& input, Vecteur3D& vect)
{
	cout << "Entrer abs: ";
	input >> vect.abs;
	cout << "Entrer ord: ";
	input >> vect.ord;
	cout << "Entrer cote: ";
	input >> vect.cote;
	return input;
}

int main ()
{
	Vecteur3D A(1, 5, 7);
	cout << A;
	
	cin >> A;
	cout << A;
	return 0;
}
