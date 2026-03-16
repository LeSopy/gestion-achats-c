#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include<vector>
#include <iomanip>   // std::fixed, std::setprecision, std::setw, std::setfill
#include <algorithm> // std::find
#include <cstdlib>   // rand(), srand()
#include <ctime>     // time(), localtime()
#include <limits>    // std::numeric_limits
#include <cctype>    // std::isdigit
#include <format>
#include "Article.h"
#include "Utils.h"
#include "Employe.h"
#include "Panier.h"

using namespace std;

Panier::Panier() {
	this->contenu = {};
}

Panier::~Panier() {}

// on va comparer le code avec un vecteur darticle (le catalogue des article)
void Panier::ajouter(const vector<Article>& articles) {
	
	//afficherEntete("AJOUT ARTICLE", LARGEUR_ENTETE);

	// ostream surchargee
	cout<<articles;

	while (true)
	{
		string code = lireSaisie("Votre choix: ");		
		for (const Article& articleInd : articles) {
			if (articleInd == code) {
				(this->contenu).push_back(articleInd);
				cout << "Article '" << code << "' ajoute au panier." << endl;
				return;
			}
		}
		cout << "Code invalide. Veuillez reessayer." << endl;
	}
}

ostream& operator<<(ostream& flux, Panier& panier) {
	if ((panier.contenu).empty())
	{
		cout << "Le panier est vide." << endl;
		return flux;
	}
	else {
		for (const Article& article : panier.contenu) {
			flux << article.getCode() << ": " << article.getNom() << format(" - {:.2f} $", article.getPrix()) << endl;
		}
	}
	return flux;
}

// on va comparer le code avec un vecteur darticle (le catalogue des article)
void Panier::retirer() {
	//afficherEntete("RETIRER ARTICLE", LARGEUR_ENTETE);

	if ((this->contenu).empty())
	{
		cout << "Le panier est vide." << endl;
		return;
	}

	// Affichons le contenu du panier grace a la surcharge de <<
	cout << this->contenu;

	while (true)
	{
		string code = lireSaisie("Code a retirer: ");

		auto it = find((this->contenu).begin(), (this->contenu).end(), code);

		if(it != (this->contenu).end())
		{
			(this->contenu).erase(it);
			cout << "Article '" << code << "' retire du panier." << endl;
			return;
		}
		else
		{
			cout << "Code introuvable dans votre panier. Veuillez reessayer." << endl;
		}
	}


	
}

void Panier::afficher() const {
	//afficherEntete("VOTRE PANIER", LARGEUR_ENTETE);

	if ((this->contenu).empty())
	{
		cout << "Le panier est vide." << endl;
		return;
	}

	// Affichons le contenu du panier grace a la surcharge de <<
	cout << this->contenu;
}

void Panier::payer(const Employe& caissier) {
	//afficherEntete("FACTURE", LARGEUR_ENTETE);

	if ((this->contenu).empty())
	{
		cout << "Aucun achat effectue. Merci de votre visite !" << endl;
		return;
	}

	// Calcul dynamique de la largeur maximale pour le nom des articles
	size_t largeurNomMax = 0;
	
	for (const Article& article : this->contenu) {
		if ((article.getNom()).length() > largeurNomMax)
		{
			largeurNomMax = (article.getNom()).length();
		}
	}
	// Ajout d'une marge (padding) de 2 espaces pour aérer l'affichage
	largeurNomMax += 2;

	double sousTotal = 0;

	// Affichage avec le setw dynamique et le code de l'article
	for (const Article& article : this->contenu) {
		cout << "- "
			<< left << setw(4) << article.getCode()
			<< left << setw(largeurNomMax) << article.getNom()
			<< right << setw(6) << format("{:.2f}", article.getPrix()) << endl;

		sousTotal += article.getPrix();
	}

	double rabais = 0;
	calculerRabais(sousTotal, &rabais);

	double taxable = sousTotal - rabais;
	double tps = taxable * TPS_RATE;
	double tvq = taxable * TVQ_RATE;
	double total = taxable + tps + tvq;

	cout << endl << "------------------------------" << endl;
	cout << " Sous-total brut: " << setw(8) << format("{:.2f}", sousTotal) << endl;

	if (rabais > 0) {
		cout << " Rabais mystere: -" << setw(8) << format("{:.2f}", rabais) << endl;
	}

	cout << " Sous-total net:  " << setw(8) <<format("{:.2f}", taxable) << endl;
	cout << " TPS (5%):        " << setw(8) << format("{:.2f}", tps) << endl;
	cout << " TVQ (9.975%):    " << setw(8) << format("{:.2f}", tvq) << endl;
	cout << " TOTAL:           " << setw(8) << format("{:.2f}", total) << endl;

	afficherBarre(30);
	cout << " Vous avez ete servi(e) par : " << caissier.getNom() << endl;
	afficherDateHeureCourante();
	afficherBarre(30);
	cout << endl << "Merci de votre visite" << endl;

	(this->contenu).clear();
}


