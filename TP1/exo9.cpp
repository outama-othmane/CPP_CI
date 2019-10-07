#include <iostream>

using namespace std;

void NewTriangle(int** tab, int N)
{
	//	Alloue chaque petit tableau
	for (int i = 0; i < N; ++i)
	{
		tab[i] = new int[i+1];
	}
}

void InitTriangle(int **tab, int N)
{
	for (int i(0); i < N; ++i)
	{
		for (int j(0); j <= i; ++j)
		{
			if (i == j || j == 0)
			{
				tab[i][j] = 1;
				continue;
			}
			tab[i][j] = tab[i-1][j] + tab[i-1][j-1];
		}
	}
}

void ShowTriangle(int **tab, int N)
{
	for (int i(0); i < N; ++i)
	{
		for (int j(0); j <= i; ++j)
		{
			cout << tab[i][j] << " ";
		}
		cout << endl;
	}
}

void DelTriangle(int **tab, int N)
{
	for (int i = 0; i < N; ++i)
	{
		delete tab[i];
	}
	delete tab;
}

int main(int argc, char const *argv[])
{
	int N;
	
	cout << "La taille du triangle de Pascal : ";
	cin >> N;

	if (N <= 0)
		cout << "L\'ordre doit etre sup a 1." << endl;

	int **tab = new int*[N];

	NewTriangle(tab, N);

	// Init triangle de Pascal 
	InitTriangle(tab, N);

	// Show triangle de Pascal
	ShowTriangle(tab, N);

	// Delete triangle de Pascal
	DelTriangle(tab, N);
	
	return 0;
}
