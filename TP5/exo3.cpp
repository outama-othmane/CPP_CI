#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main ()
{
	vector<string> mon_vecteur;
	mon_vecteur.push_back("Bonjour");
	mon_vecteur.push_back("comment");
	mon_vecteur.push_back("allez");
	mon_vecteur.push_back("vous");
	mon_vecteur.push_back("?");
	
	// La taille du vecteur
	cout << "Size du mon vecteur = " << mon_vecteur.size() << endl;
	
	//	La taille allouée
	cout << "capacity du mon vecteur = " << mon_vecteur.capacity()	<< endl;
	
	// La taille max qu'on peut allouer pour ce vecteur.
	cout << "Max size du mon vecteur = " << mon_vecteur.max_size() << endl;
	
	// Avec les indices comme les tableaux.
	cout << "\n\n";
	for (int i=0; i< mon_vecteur.size(); i++)
	{
		cout << mon_vecteur[i] << endl;
	}
	
	// Avec les iterateurs.
	cout << "\n\n";
	vector<string>::iterator it;
	for (it = mon_vecteur.begin(); it != mon_vecteur.end(); it++)
	{
		cout << *it << endl;
	}
	
	//	Echange entre le contenu de la case d'indice 1 et le contenu de la case d'indice 3.
	swap(mon_vecteur[3], mon_vecteur[1]);
	
	// Insérez la valeur "a tous"
	mon_vecteur.insert(mon_vecteur.begin() + 1, "a tous");
	cout << "\n\n";
	for (it = mon_vecteur.begin(); it != mon_vecteur.end(); it++)
	{
		cout << *it << endl;
	}
	
	//
	mon_vecteur.pop_back();
	mon_vecteur.push_back("???");
	cout << "\n\n";
	for (it = mon_vecteur.begin(); it != mon_vecteur.end(); it++)
	{
		cout << *it << endl;
	}
	
	return 0;
}
