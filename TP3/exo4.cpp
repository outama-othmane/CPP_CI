#include <iostream>

using namespace std;

class Set_int
{
	int* tab;
	int tmax;
	int card;
	
	public: 
	Set_int(int n=20);
	~Set_int();
	Set_int(const Set_int&);
	int cardinal()
	{
		return card;
	}
	Set_int& operator <<(int);
	friend bool operator%(int , Set_int&);
	Set_int& operator=(const Set_int&);
	void affiche();
};

Set_int::Set_int(int n)
{
	card = 0;
	tmax = n;
	tab = new int[tmax];
}

Set_int::Set_int(const Set_int& A)
{
	card = A.card;
	tmax = A.tmax;
	tab = new int[tmax];
	
	for(int i=0; i<card; i++)
	{
		tab[i] = A.tab[i];
	}
}

Set_int& Set_int::operator=(const Set_int& e)
{
	if (this != &e)
	{
		tmax = e.tmax;
		card = e.card;
		
		delete tab;
		
		tab = new int[tmax];
		for(int i=0; i<card; i++)
		{
			tab[i] = e.tab[i];
		}
	}
	return *this;	
}

bool operator%(int n, Set_int &A)
{
	for(int i=0; i<A.card; i++)
	{
		if (A.tab[i] == n)
			return true;
	}
	
	return false;
}

Set_int& Set_int::operator <<(int n)
{
	if(card == tmax)
	{
		cout << "Ensemble Plein \n";
		return *this;
	}
	
	if(n%*this)
	{
		cout << "Element deja existe \n";
		return *this;
	}
	
	tab[card++] = n;
	
	return *this;
}

void Set_int::affiche()
{
	for(int i=0; i<card; i++)
		cout << "Element " << i << " = " << tab[i] << endl;
}
