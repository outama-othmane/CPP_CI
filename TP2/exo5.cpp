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

		// Q2- Fonction inline
		Vecteur3D()
		{
			cout << "Constrecteur sans arguments." << endl;
			x = 0;
			y = 0;
			z = 0;
		}

		// Q2- Fonction inline
		Vecteur3D(double a, double b, double c)
		{
			cout << "Constrecteur avec arguments." << endl;
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
	// IMPORTANT
	return (v.x == x && v.y == y && v.z == z);
}

int main(int argc, char const *argv[])
{
	// Constrecteur sans arguments.
	Vecteur3D A;
	// Constrecteur avec arguments.
	Vecteur3D B(1, 2, 3);
	
	A.affiche();
	B.affiche("Bonjour");
	
	A.fixer_abscisse(3);
	A.fixer_ordonnee(4);
	A.affiche();

	cout << A.ordonnee() << endl;

	if (B.coincide(A))
		cout << "Ils sont egaux.";
	else 
		cout << "Different!"; 

	return 0;
}
