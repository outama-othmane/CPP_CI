#include <iostream>
#include <cstring>

using namespace std;

class point
{ 
protected:
	float x, y;
public :
	point(float abs, float ord)
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
	
	point(const point& p)
	{
		x = p.x;
		y = p.y;
	}
	
	point& operator=(const point& p)
	{	
		x = p.x;
		y = p.y;
		return *this;
	}
};

class PointCol : public point
{
private:
	char* couleur;

public: 
	PointCol (float a, float b, char* col = "Blue"): point(a, b)
	{
		couleur = new char[strlen(col) + 1];
		strcpy(couleur, col);
	}
	
	PointCol(const PointCol& p): point(p)
	{
		couleur = new char[strlen(p.couleur) + 1];
		strcpy(couleur, p.couleur);
	}
	
	PointCol& operator=(const PointCol& p)
	{	
		if (this == &p)
		{
			return *this;
		}
		
		operator=(p);
		
		delete couleur;
		couleur = new char[strlen(p.couleur) + 1];
		strcpy(couleur, p.couleur);
		
		return *this;
	}
};
