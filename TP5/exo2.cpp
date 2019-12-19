#include <iostream>
#include <stdexcept>

using namespace std;

class Pile
{
	// Copy class Pile from the precedent exercices.
	// And update the functions with the new version.
	public:
		int depiler ()
		{
			if (!(*this).vide())
				return tab[sommet--];
			
			else 
				throw(1);
			
		}
};

int main()
{
	try {
		Pile P(10);
		P.depiler():
	}
	catch (int i)
	{
		if (i == 1)
			cerr << "La pile est vide impossible de depile." << endl;
	}
	catch (bad_alloc &e)
	{
		cerr << e.what() << endl;
	}
	
	return 0;
}
