#include <iostream>

using namespace std;

class PileEntier
{
	int taille, last;
	int* tab;

	public:
		PileEntier(int);
		PileEntier();
		PileEntier(const PileEntier &pile);
		~PileEntier();
		void empile(int p);
		int depile();
		int pleine();
		int vide();
		
		PileEntier& operator = (PileEntier& pile)
		{
			if(&pile != this)
			{
				this->taille = pile.taille;
				this->last = pile.last;
				
				delete this->tab;
				this->tab = new int [this->taille];
				
				for (int i=0; i <= this->last; ++i) 
				{
					this->tab[i] = pile.tab[i];
				}
			}
			return *this;
		}
};

PileEntier::PileEntier(int taille)
{
	this->last = 0; // Pas d'elements dans la tableau.
	this->taille = taille; // La taille du tableau
	this->tab = new int[this->taille]; // Alloue dynamiquement un emplacement de taille (int taille)
}

PileEntier::PileEntier()
{
	this->last = 0;
	this->taille = 20;
	this->tab = new int[this->taille];
}

PileEntier::PileEntier(const PileEntier &pile)
{
	this->taille = pile.taille;
	this->tab = new int[this->taille];

	for (int i = 0; i < this->taille; ++i)
	{
		this->tab[i] = pile.tab[i];
	}
}

PileEntier::~PileEntier()
{
	delete tab;
}

void PileEntier::empile(int p)
{
	// Verifier si le pile est pleine alors en increment la taille du tableau.
	if (this->pleine() == 1)
	{

		// Créer un local tableau qui va storer les valeur de global tableau. 
		int* tab = new int[this->taille];
		for (int i = 0; i < this->taille; ++i)
		{
			tab[i] = this->tab[i];
		}

		// Remplir le tableau global autrefois.
		delete this->tab; // Important
		
		this->tab = new int[++this->taille];
		for (int i = 0; i < this->taille-1; ++i)
		{
			this->tab[i] = tab[i];
		}
	}

	// Ajouter au tableau
	this->tab[this->last++] = p;
}

int PileEntier::depile()
{
	return this->tab[--this->last];
}

int PileEntier::pleine()
{
	return (this->last == this->taille) ? 1 : 0;
}

int PileEntier::vide()
{
	return (this->last == 0) ? 1 : 0;
}

int main()
{
	PileEntier H(5);

	H.empile(1);
	H.empile(2);
	H.empile(3);
	
	PileEntier D;
	D = H;
	
	cout << D.depile() << endl;
}
