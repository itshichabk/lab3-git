#pragma once
#include <string>
#include <fstream>
#include "point.h"

void ouvrirFichier(std::ifstream &flux, std::string nomFichier);
int lireFichier(std::ifstream &flux, Point tabPoint[]);
void afficherForme(Point tabPoint[], int lignes);