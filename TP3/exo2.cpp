// "this" est un pointeur
// pour prendre la valeur de "this" on utilise "*this".

#include <iostream>

using namespace std;

#include <iostream>

using namespace std;

class Vecteur3D
{

	double x;
	double y;
	double z;

	public:
		void affiche(); 
		void affiche(const char* chaine); 
		Vecteur3D()
		{
			x = 0;
			y = 0;
			z = 0;
		}
		Vecteur3D(double a, double b, double c)
		{
			x = a;
			y = b;
			z = c;
		}
		double abscisse();
		double ordonnee();
		double cote();
		void fixer_abscisse(double);
		void fixer_ordonnee(double);
		void fixer_cote(double);
		bool coincide(Vecteur3D);
		double produit_scalaire(Vecteur3D);
		Vecteur3D somme(Vecteur3D v);
		
		Vecteur3D operator +(Vecteur3D v)
		{
			Vecteur3D newV;
			newV.x = (this->x + v.x);
			newV.y = (this->y + v.y);
			newV.z = (this->z + v.z);
			
			return newV;
		}
		
		Vecteur3D operator +(double r)
		{
			Vecteur3D newV(this->x + r, this->y+r, this->z + r);
			
			return newV;
		} 
		
		double operator *(Vecteur3D v)
		{	
			return this->x*v.x + this->y*v.y + this->z*v.z;
		}
		
		bool operator ==(Vecteur3D v)
		{
			return v.x == this->x && v.y == this->y && v.z == this->z;
		}
		
		double operator [](int a)
		{
			switch(a)
			{
				case 1: return this->x;
				case 2: return this->y;
				case 3: return this->z;
				default: {
					// Sortir du programme avec un error (1);
					// d'après le prof
					exit(1);
				};
			}
		}
		
		Vecteur3D operator ++()
		{
			this->x++;
			this->y++;
			this->z++;
			
			return *this;
		}
		
		Vecteur3D operator ++(int)
		{
			Vecteur3D ref = *this;
			
			this->x++;
			this->y++;
			this->z++;
			
			return ref;
		}
};

void Vecteur3D::affiche()
{
	cout << "(" << x << "," << y << "," << z << ")" << endl; 
}

void Vecteur3D::affiche(const char* chaine)
{
	cout << chaine << endl;
	affiche();
}

double Vecteur3D::abscisse()
{
	return x;
}

double Vecteur3D::ordonnee()
{
	return y;
}

double Vecteur3D::cote()
{
	return z;
}

void Vecteur3D::fixer_abscisse(double nx)
{
	x = nx;
}

void Vecteur3D::fixer_ordonnee(double ny)
{
	y = ny;
}

void Vecteur3D::fixer_cote(double nz)
{
	z = nz;
}

bool Vecteur3D::coincide(Vecteur3D v)
{
	return (v.x == x && v.y == y && v.z == z);
}

double Vecteur3D::produit_scalaire(Vecteur3D v)
{
	return x*v.x + y*v.y + z*v.z;
}

Vecteur3D Vecteur3D::somme(Vecteur3D v)
{
	Vecteur3D A(x+v.x, y+v.y, z+v.z);
	return A; 

	/*
		//Ou bien
		Vecteur3D S;
		S.x = x+v.x;
		S.y = y+v.y;
		S.z = z+v.z;
		return S;
	*/
}

int main()
{
	Vecteur3D A(4, 5, 6);
	Vecteur3D B(6, 5, 4);
	cout << "----------------------------------------------" << endl;
	
	// Tester la somme
	Vecteur3D C = A + B;
	C.affiche();
	cout << "----------------------------------------------" << endl;
	
	// Tester la somme avec un reel
	Vecteur3D D = A + 5;
	D.affiche();
	cout << "----------------------------------------------" << endl;
	
	// Tester produit scalaire
	double r = D * C;
	cout << r << endl;
	cout << "----------------------------------------------" << endl;
	
	// Tester l'egalité
	B = A;
	if (A == B)
	{
		cout << "A et B sont egaux." << endl;
	} else {
		cout << "A et B ne sont pas egaux." << endl;
	}
	cout << "----------------------------------------------" << endl;
	
	// Acceder a les coordonnes de vecteur.
	cout << "A[1] = " << A[1] << endl;
	cout << "A[2] = " << A[2] << endl;
	cout << "A[3] = " << A[3] << endl;
	cout << "----------------------------------------------" << endl;
	
	// Tester pre-inc
	cout << "A = ";
	(++A).affiche();
	cout << "----------------------------------------------" << endl;
	
	// Tester post-inc
	cout << "A = ";
	(A++).affiche();
	cout << "A = ";
	A.affiche();
	cout << "----------------------------------------------" << endl;
}
