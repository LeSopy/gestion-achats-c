#pragma once
#include<string>
#include<vector>
#include "Article.h"
#include "Employe.h"
using namespace std;

enum MenuOption
{
    PAYER = 0,
    AJOUTER = 1,
    RETIRER = 2,
    AFFICHER = 3
};

string login(const vector<Employe> employes);
int afficherMenuPrincipal(const int& largeurEntete);
void calculerRabais(double sousTotal, double* ptrRabais);
string lireSaisie(const string& invite);
bool estUnNombre(const string& chaine);
void afficherDateHeureCourante();
void afficherEntete(const string& titre, const int& largeurEntete);
void afficherBarre(const int& largeurEntete);

