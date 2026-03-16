// Pour desactiver les warnings de securite de Visual Studio (ctime)
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
#include "Employe.h"
#include "Article.h"
#include "Panier.h"
#include "Utils.h"
using namespace std;


int main()
{
    const int LARGEUR_ENTETE = 20;
    srand(static_cast<unsigned int>(time(0)));

    vector<Employe> employes;
    employes.push_back(Employe("001", "Andrew"));
    employes.push_back(Employe("002", "Nabil"));
    employes.push_back(Employe("003", "Marc"));
    employes.push_back(Employe("004", "Jean-Gabriel"));
    employes.push_back(Employe("005", "Caroline"));
    employes.push_back(Employe("001", "Andrew"));

    const vector<Employe> catalogueEmployes = employes;

    vector<Article> catalogue;
    catalogue.push_back(Article("A1", "Crayons", 3.99));
    catalogue.push_back(Article("A2", "Cahier Canada", 1.59));
    catalogue.push_back(Article("B1", "Table pliante", 66.99));
    catalogue.push_back(Article("B2", "Fauteuil en cuir", 199.99));
    catalogue.push_back(Article("B3", "Bureau d'etudiant", 118.99));
    catalogue.push_back(Article("L1", "Laptop ASUS", 600.89));
    catalogue.push_back(Article("L2", "Laptop HP", 700.89));
    catalogue.push_back(Article("L3", "Laptop Acer", 250.99));
    const vector<Article> catalogueArticles = catalogue;

    Panier panier;

    string nomEmploye = login(catalogueEmployes);

    auto it = find_if(employes.begin(), employes.end(),
        [&nomEmploye] (const Employe& e) {
            return (e.getNom() == nomEmploye);
    });

    cout << it->getNom() << endl;

    const Employe caissier(it->getNumero(), nomEmploye);


    int choix;
    do
    {
        choix = afficherMenuPrincipal(LARGEUR_ENTETE);

        switch (choix)
        {
        case AJOUTER:
            afficherEntete("AJOUT ARTICLE", LARGEUR_ENTETE);
            panier.ajouter(catalogueArticles);
            break;
        case RETIRER:
            afficherEntete("RETIRER ARTICLE", LARGEUR_ENTETE);
            panier.retirer();
            break;
        case AFFICHER:
            afficherEntete("VOTRE PANIER", LARGEUR_ENTETE);
            panier.afficher();
            break;
        case PAYER:
            afficherEntete("FACTURE", LARGEUR_ENTETE);
            panier.payer(caissier);
            cout << string(LARGEUR_ENTETE, '-') << endl;
            break;
        default:
            // Ne devrait théoriquement jamais être atteint grâce à la validation effectuée dans afficherMenuPrincipal, 
            // mais c'est une bonne pratique de le prévoir
            cout << "Choix invalide..." << endl;
            break;
        }
    } while (choix != PAYER);

    return 0;
}


