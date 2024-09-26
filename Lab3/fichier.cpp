#include <iostream>
#include <Windows.h>
#include "fichier.h"

using namespace std;

void ouvrirFichier(std::ifstream &flux, std::string nomFichier)
{
	flux.open(nomFichier);

	if (!flux)
	{
		cout << "Le fichier n'a pas pu etre ouvert." << endl;
	}
	
	// Si fichier vide
	if (flux.peek() == std::ifstream::traits_type::eof())
	{
		cout << "Le fichier est vide." << endl;
	}

}

int lireFichier(std::ifstream& flux, Point tabPoint[])
{
	int i = 0;

	while (!flux.eof() && i < 200)
	{
		tabPoint[i].read(flux);
		i++;
	}

	return i;
}

void afficherForme(Point tabPoint[], int lignes)
{
	for (int i = 0; i < lignes; i++)
	{
		tabPoint[i].draw(cout);
	}

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}
