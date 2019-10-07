#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int N;
	
	cout << "La taille du triangle de Pascal : ";
	cin >> N;

	if (N <= 0)
		cout << "L\'ordre doit etre sup a 1." << endl;

	int tab[N][N];

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


	for (int i(0); i < N; ++i)
	{
		for (int j(0); j <= i; ++j)
		{
			cout << tab[i][j] << " ";
		}
		cout << endl;
	}



	return 0;
}
