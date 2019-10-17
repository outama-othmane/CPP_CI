PileEntier::empile(int p)
{
	PileEntier T(*this);

	delete tab;

	tab = new int[taille+1];

	for (int i = 0; i < taille; ++i)
		tab[i] = T.tab[i];

	tab[taille] = p;

	taille++;
	sommet++;
}