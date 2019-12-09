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
		
		friend ostream& operator <<(ostream&, PileEntier&);
		
		friend istream& operator >>(istream&, PileEntier&);
};

ostream& operator <<(ostream& output, PileEntier& pile)
{
	for(int i=0; i < pile.last; ++i)
	{
		output << "tab[" << i << "] = " << pile.tab[i] << endl; 
	}
	return output;
}

istream& operator >>(istream& input, PileEntier& pile)
{
	int a;
	int n;
	
	cout << "Entrer combien des valeurs vous voulez saisir.\n";
	input >> n;
	
	for (int i=1; i <= n; i++)
	{
		cout << "tab[" << pile.last << "] = ";
		input >> a;
		
		pile.empile(a);
	}	
	
	return input;
}

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
	
	cout << H;
	
	cin >> H;
	
	cout << H;
}
