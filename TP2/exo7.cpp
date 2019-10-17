// O_o

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
};

PileEntier::PileEntier(int taille)
{
	this->last = 0; 
	this->taille = taille;
	this->tab = new int[this->taille];
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
	if (this->pleine() == 1)
	{
		int* tab = new int[this->taille];
		for (int i = 0; i < this->taille; ++i)
		{
			tab[i] = this->tab[i];
		}

		this->tab = new int[++this->taille];
		delete tab;
		for (int i = 0; i < this->taille-1; ++i)
		{
			this->tab[i] = tab[i];
		}
	}
	
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