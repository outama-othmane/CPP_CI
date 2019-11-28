#include <iostream>
#include <cmath>
using namespace std;

class point
{ 
// c'est la question num�ro 2.
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
		cout << "Point de coordonn�es : " << x << " " << y << "\n";
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
	// Question num�ro 1	
	float rho ()
	{
		// �a ne marche pas car x et y sont inaccessibles (sont private)		
		//return sqrt(x*x + y*y);
		
		// Donc 
		return sqrt(abs()*abs() + ord()*ord()); 		
	}
	
	// Question num�ro 2 modifier private en protected dans la class point
	// c-�-d
	// protected: float x, y;
	
	// Question num�ro 3:
	pointb (float a,float b)
	{
		initialise(a, b);
	}
	
	
	/*
		Question num�ro 4:
		Apr�s avoir modifier private en protected dans la class point. 
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
