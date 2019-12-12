#include <string>
#include <iostream>
#include <fstream>

using namespace std;

void ecrire(char* fileName)
{
	ofstream flot(fileName, ios::out);
	
	if (!flot.is_open())
	{
		string error = "Erreur lors d'ouverture le fichier";
		error = error + fileName;
		throw (error);	
	}
	
	flot << "Bonjour" << endl;
	flot << "Voici un programme illustrant l'écriture dans un fichier" << endl;
	
	flot.close();
}

void lire (char* fileName)
{
	ifstream flot(fileName, ios::in);
	
	if (!flot.is_open())
	{
		string error = "Erreur lors d'ouverture le fichier";
		error = error + fileName;
		throw (error);	
	}
	
	string ligne;
	
	while (!flot.eof())
	{
		getline(flot, ligne);
		cout << ligne << endl;
	}
	
	flot.close();
}

int main ()
{
	char* fileName = "test.txt";
	
	try {
		
		ecrire(fileName);
		lire(fileName);
		
	} catch (string e) {
		
		cout << e  << endl;
		
	}
	
}
