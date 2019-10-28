// J'utilise "this->" pour les variable de la class seulement (!)
// C'est le même chose quand on utilise les noms des variables directe sans "this->".
// ex: this->x <=> x
// ex: this->r <=> r
// ex: this->c <=> c
// ...
// Bon courage :)


#include <iostream>
#include <cmath>

using namespace std;

class Point
{
	double x, y;
	public:
		Point(double x = 0, double y = 0)
		{
			this->x = x;
			this->y = y;
		}
		double getX()
		{
			return this->x;
		}
		double getY()
		{
			return this->y;
		}
		
		void setX(double a)
		{
			this->x = a;
		}
	
		void setY(double a)
		{
			this->y = a;
		}
		
		bool egalite(Point point)
		{
			return (this->x == point.x && this->y == point.y);
		}
};

class Cercle
{
	Point c;
	double r;
	
	public:
		Cercle(double r, Point p):c(p)
		{
			this->r = r;
			
			//this->c = p; // ça marche car les attributs sont simple.
		}
		
		Cercle(double r, double x, double y):c(x,y)
		{
			this->r = r;
			
//			this->c.setX(x);
//			this->c.setY(y);
		}
		
		void affiche()
		{
			cout << "Rayon = " << this->r << endl;
			cout << "Centre = (" << c.getX() << ", " << c.getY() << ")" << endl;
		}
		
		double getRayon()
		{
			return this->r;
		}
		
		void setRayon(double r)
		{
			this->r = r;
		}
		
		Point getCentre()
		{
			return this->c;
		}
		
		void translationCentre(double a)
		{
			this->c.setX(this->c.getX() + a);
			this->c.setY(this->c.getX() + a);
		}
		
		double surface()
		{
			return pow(this->r, 2) * M_PI; 
		}
		
		double perimetre()
		{
			return 2 * this->r * M_PI; 
		}
		
		bool egalite(Cercle cercle)
		{
			return (this->c.egalite(cercle.getCentre()) && this->r == cercle.r);
		}
		
		bool appartient(Point p)
		{
			if(p.getX() > (this->c.getX() + this->r) || p.getX() < (this->c.getX() - this->r))
				return false;
				
			if(p.getY() > (this->c.getY() + this->r) || p.getY() < (this->c.getY() - this->r))
				return false;
			
			return true;
			
			/*
				// Method de prof.
				double d;
				d = pow(p.getCentre().getX(), 2) + pow(p.getCentre().getY(), 2);
				if(d == r*r)
					return true;
				return false;
			*/
		}
};

int main()
{
	Cercle cercle(1, 0, 0);
	cercle.affiche();
	
	cout << "S = " << cercle.surface() << endl;
	cout << "P = " << cercle.perimetre() << endl;
	
	cercle.setRayon(cercle.getRayon() * 2);
	
	cout << "S = " << cercle.surface() << endl;
	cout << "P = " << cercle.perimetre() << endl;
	
	cercle.translationCentre(-1 * cercle.getCentre().getX());
	
	Point A1(1,1);
	
	if(cercle.appartient(A1))
	{
		cout << "le point A1(" << A1.getX() << ", " << A1.getY() << ") appartient a l'interieur du cercle." << endl; 
	}
	
	Point A2(3,3);
	if(!cercle.appartient(A2))
	{
		cout << "le point A2(" << A2.getX() << ", " << A2.getY() << ") appartient a l'exterieur du cercle." << endl; 
	}
	
	Cercle autreCercle(2, 0, 0);
	
	if(cercle.egalite(autreCercle))
	{
		cout << "les deux cercles sont egaux." << endl;
	}
	
	return 0;
}
