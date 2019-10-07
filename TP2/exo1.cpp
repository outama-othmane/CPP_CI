#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int n;

	cout << "Entrez taille du tableau : " ;
	cin >> n;

	int tab[n];

	for (int i = 0; i < n; ++i)
	{
		cout << "tab[" << i << "] = ";
		cin >> tab[i];
	}

	// Trie le tableau
	for (int i = 0; i < n; ++i)
	{
		for (int j = i+1; j < n; ++j)
		{
			if (tab[i] > tab[j])
			{
				int ref = tab[i];
				tab[i] = tab[j];
				tab[j] = ref;
			}
		}
	}
	
	// Affichage	
	cout << "---------------------\n";
	cout << "Apres l'ordre : ";
	cout << "---------------------\n" << endl;
	
	for (int i = 0; i < n; ++i)
	{
		cout << "tab[" << i << "] = " << tab[i] << endl;
	}

	return 0;
}
