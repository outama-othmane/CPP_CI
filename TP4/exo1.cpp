#include <iostream>
#include <cmath>
using namespace std;

class point
{ 
// c'est la question numéro 2.
protected:
	float x, y;
public :
	void initialise (float abs=0.0, float ord=0.0)
	{ 
		x = abs;
		y = ord ;
	}
	void affiche ()
	{ 
		cout << "Point de coordonnées : " << x << " " << y << "\n";
	}
	float abs () 
	{ 
		return x; 
	}
	float ord ()
	{
		return y;
	}
};

class pointb : public point 
{
public:	
	// Question numéro 1	
	float rho ()
	{
		// ça ne marche pas car x et y sont inaccessibles (sont private)		
		//return sqrt(x*x + y*y);
		
		// Donc 
		return sqrt(abs()*abs() + ord()*ord()); 		
	}
	
	// Question numéro 2 modifier private en protected dans la class point
	// c-à-d
	// protected: float x, y;
	
	// Question numéro 3:
	pointb (float a,float b)
	{
		initialise(a, b);
	}
	
	
	/*
		Question numéro 4:
		Aprés avoir modifier private en protected dans la class point. 
		Les fonctions members sont :
		-----------------------------------------------------------------
		pointb B;
		B.rho();
		B.abs();
		B.ord();
		B.initialise();
		B.affiche();
		-----------------------------------------------------------------
	*/
};
