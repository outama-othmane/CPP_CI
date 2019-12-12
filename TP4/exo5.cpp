#include <iostream>

using namespace std;

/*
 * La class Vecteur3D<T>
 * ------------------------------------
 * Définir une vecteur par son abs, ord et cote
 * ------------------------------------ 
 */
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
	
	T operator*(Vecteur3D<T>);
	Vecteur3D<T> operator+(Vecteur3D<T>);
	
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

/*
 * Definir l'opérateur *
 *
 * @param Vecteur3D<T> v
 * @return <T>
 */
template<typename T> T Vecteur3D<T>::operator*(Vecteur3D<T> v)
{
	return (abs*v.abs + ord*v.ord + cote*v.cote);
}

/*
 * Definir l'opérateur +
 *
 * @param Vecteur3D<T> v
 * @return Vecteur3D<T>
 */
template<typename T> Vecteur3D<T> Vecteur3D<T>::operator+(Vecteur3D<T> v)
{
	Vecteur3D<T> n(abs+v.abs, ord+v.ord, cote+v.cote);
	return n;
}

/*
 * La fonction main
 * 
 * @return <int>
 */
int main ()
{
	Vecteur3D <int> V(1, 2, 3);
	cout << V << endl;
	
	Vecteur3D <int> U(4,5, 6);
	cout << U << endl;
	
	Vecteur3D <int> W(1, 2, 3);
	W = V+U;
	cout << W << endl;
	
	return 0;
}


