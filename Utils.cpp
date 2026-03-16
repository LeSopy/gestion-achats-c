#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>   // std::fixed, std::setprecision, std::setw, std::setfill
#include <algorithm> // std::find
#include <cstdlib>   // rand(), srand()
#include <ctime>     // time(), localtime()
#include <limits>    // std::numeric_limits
#include <cctype>    // std::isdigit
#include <format>    
#include "Utils.h"
#include "Employe.h"



string lireSaisie(const string& invite)
{
    string saisie;
    cout << invite;
    cin >> saisie;

    // Gestion des erreurs de saisie: si l'utilisateur entre un type de donnée incorrect, on réinitialise le flux et on ignore les caractères restants
    if (cin.fail())
    {
        cin.clear();
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    return saisie;
}

bool estUnNombre(const string& chaine)
{
    // Si la chaîne est vide, ce n'est pas un nombre
    if (chaine.empty())
    {
        return false;
    }

    // On vérifie chaque caractère
    for (char c : chaine)
    {
        if (!isdigit(c))
        {
            return false; // Dès qu'on trouve une lettre ou un symbole, on quitte et on renvoie faux
        }
    }

    return true; // Si on a fini la boucle sans quitter, c'est que tout est un chiffre
}

int afficherMenuPrincipal(const int& largeurEntete)
{
    afficherEntete("MENU PRINCIPAL", largeurEntete);

    // Affichage dynamique couplé à l'énumération
    cout << AJOUTER << ". Ajouter un article" << endl;
    cout << RETIRER << ". Supprimer un article" << endl;
    cout << AFFICHER << ". Afficher le panier" << endl;
    cout << PAYER << ". Payer" << endl;

    while (true)
    {
        string choixStr = lireSaisie("Votre choix: ");

        if (estUnNombre(choixStr))
        {
            int choixInt = stoi(choixStr);

            // Validation finale avec un switch (fall-through)
            switch (choixInt)
            {
            case PAYER:
            case AJOUTER:
            case RETIRER:
            case AFFICHER:
                return choixInt; // Option valide trouvée, on retourne l'entier
            default:
                break; // Option invalide, on sort du switch pour afficher l'erreur
            }
        }
        cout << "Entree invalide. Veuillez entrer un nombre valide du menu." << endl;
    }
}

// --- Fonctions d'Affichage ---

void afficherDateHeureCourante()
{
    time_t tempsBrut = time(0);
    tm* date = localtime(&tempsBrut);

    if (date) {
        cout << " Date : "
            << (1900 + date->tm_year) << "-"
            << setfill('0') << setw(2) << (1 + date->tm_mon) << "-"
            << setfill('0') << setw(2) << date->tm_mday << endl;

        cout << " Heure: "
            << setfill('0') << setw(2) << date->tm_hour << ":"
            << setfill('0') << setw(2) << date->tm_min << ":"
            << setfill('0') << setw(2) << date->tm_sec << endl;

        cout << setfill(' '); // Reset du setfill
    }
}

void afficherEntete(const string& titre, const int& largeurEntete)
{
    cout << endl << string(largeurEntete, '*') << endl;
    cout << " " << titre << " " << endl;
    cout << string(largeurEntete, '*') << endl;
}

void afficherBarre(const int& largeurEntete)
{
    cout << string(largeurEntete, '*') << endl;
}

string login(const vector<Employe> employes)
{
    while (true)
    {
        string code = lireSaisie("Veuillez vous identifier: ");
        for (const Employe& emp : employes) {
            if (emp == code) {
                cout << endl << "Bonjour, " << emp.getNom() << endl;
                return emp.getNom();
            }
        }
        cout << "ERREUR: Numero d'employe invalide." << endl;
    }
}

void calculerRabais(double sousTotal, double* ptrRabais)
{
    // 50% de chance d'avoir un rabais de 25%
    if (rand() % 2 == 0) {
        *ptrRabais = sousTotal * 0.25;
    }
    else {
        *ptrRabais = 0.0;
    }
}
