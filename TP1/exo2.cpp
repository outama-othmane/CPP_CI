#include <iostream>

using namespace std;

int main()
{
	int N;

	cout << "Entrer N :" << endl;
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		for (int j = i; j >= 1; j--)
		{
            int c = 0;
			while (c != j){
				cout << "*";
				c++;
			}
			cout << " ";
		}
		cout << endl;
	}

	return 0;
}
