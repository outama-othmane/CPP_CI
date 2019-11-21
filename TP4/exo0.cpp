//GIT
#include <iostream>

using namespace std;

class String
{
	char* tab;
	
public:
	
	String(char*);	
	
	String(char);
	
	String(int);
	
	String(double);
	
	~String() 
	{
		delete tab;
	}
	
	int lenght();
	
	char get(int i)
	{
		return tab[i];
	}
	
	void Set(int i, char c)
	{
		tab[i] = c;
	}
	
	Void Set(char*);
	
	void append(char*);
				
};

String::String(char* chaine)
{
	tab = new char[strlen(chaine)+1];
	strcpy(tab, chaine);
}

String::String(char c)
{
	tab = new char[2];
	strcpy(tab, c);
}

String::String(double f)
{
	sprintf(t, "%f", f);
}

String::String(int n)
{
	sprintf(t, "%d", n);
}


