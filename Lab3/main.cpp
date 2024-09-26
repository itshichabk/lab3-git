#include <iostream>
#include <time.h>
#include <Windows.h>
#include "Rectangle.h"
#include "fichier.h"

using namespace std;

int main()
{
	// LAB 3
	// ifstream flux;
	//string nomFichier;
	//Point tabPoint[200];
	//do {
	//	cout << "Entrer un nom de fichier : ";
	//	cin >> nomFichier;
	//	ouvrirFichier(flux, nomFichier);
	//	int lignes = lireFichier(flux, tabPoint);
	//	afficherForme(tabPoint, lignes);

	//	flux.close();
	//	system("pause>0");
	//	system("cls");
	//} while (1);
	//Rectangle r1(0, 0, 6, 9);
	//r1.draw(cout);

	//cout << endl << endl << "Surface: " << r1.surface() << endl;
	//cout << "Perimetre: " << r1.perimetre() << endl;
	//cout << r1 << endl << endl;
	//system("pause");

	cout << "Hello world!";

	r::Rectangle rect(10, 2, 5, 4);
	int nbRectangle;
	int color;
	
	srand(time(NULL));

	do
	{
		system("cls");
		nbRectangle = rand() % 10 + 1;
		color = rand() % 15 + 1;

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
		
		cout << "Voici une ligne de " << nbRectangle <<
			" a la position (" << rect.getPosition().getX() << "," << rect.getPosition().getY() << ")" << endl;
		afficherLigne(rect, nbRectangle);
		system("pause>0");
		system("cls");

		cout << "Voici un triangle de " << nbRectangle <<
			" a la position (" << rect.getPosition().getX() << "," << rect.getPosition().getY() << ")" << endl;
		afficherTriangle(rect, nbRectangle);
		system("pause>0");
		system("cls");

		cout << "Voici une grille de " << nbRectangle << " x " << nbRectangle <<
			" a la position (" << rect.getPosition().getX() << "," << rect.getPosition().getY() << ")" << endl;
		afficherGrille(rect, nbRectangle);
		system("pause>0");
		system("cls");

	} while (1);

	return 0;
}