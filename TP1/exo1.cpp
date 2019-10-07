#include <iostream>
#include <cmath>

using namespace std;

double norme(double*, int);

double produitScalaire(double*, double*, int);

int main()
{
    int n;

    cout << "Entrer le dimension svp : \n";
    cin >> n;

    double* vector_1;
    double* vector_2;

    vector_1 = new double[n];
    vector_2 = new double[n];

    cout << "Remplir la premier vecteur: " << endl;
    for(int i=0; i<n; ++i)
    {
        cout << "vecteur_1[" << i << "] = ";
        cin >> *(vector_1+i);
    }

    cout << "La norme de premier vecteur est " << norme(vector_1, n) << endl;

    cout << "Remplir la 2 vecteur: " << endl;
    for(int i=0; i<n; ++i){
        cout << "vecteur_2[" << i << "] = ";
        cin >> *(vector_2+i);
    }

    cout << "\nLa norme de la 2 vecteur est " << norme(vector_2, n) << endl;

    cout << "Le produit scalaire de les deux vecteurs est " << produitScalaire(vector_1, vector_2, n) << endl;

    delete vector_1;
    delete vector_2;

    return 0;
}

double norme(double* vect, int n)
{
    double somme = 0;
    for(int i=0; i<n; i++)
    {
        somme += pow(vect[i], 2);
    }
    return sqrt(somme);
}

double produitScalaire(double* vect1, double* vect2, int n)
{
    double somme = 0;
    for(int i=0; i<n; i++)
    {
        somme += vect1[i] * vect2[i];
    }
    return somme;
}
