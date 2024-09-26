#include <iostream>
#include <Windows.h>
#include "fichier.h"

using namespace std;

void ouvrirFichier(std::ifstream &flux, std::string nomFichier)
{
	flux.open(nomFichier);

	// Si fichier n'a pas pu être ouvert
	if (!flux)
	{
		cout << "Le fichier n'a pas pu etre ouvert." << endl;
		//system("pause");
		//exit(1);
	}
	
	// Si fichier vide
	if (flux.peek() == std::ifstream::traits_type::eof())
	{
		cout << "Le fichier est vide." << endl;
		//system("pause");
		//exit(2);
	}

	// Sinon
}

int lireFichier(std::ifstream& flux, Point tabPoint[])
{
	int i = 0;

	//for (int j = 0; j < 200; j++)
	//{
	//	tabPoint[i].setX(0);
	//	tabPoint[i].setY(0);
	//	tabPoint[i].setColor(7);
	//}

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
