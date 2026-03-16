#pragma once
#include<string>
#include<vector>
#include"Article.h";
#include"Employe.h";
using namespace std;

class Panier
{
private:
	const double TPS_RATE = 0.05;       // TPS 5%
	const double TVQ_RATE = 0.09975;    // TVQ 9.975% 
	vector<Article> contenu;

public:
	Panier();
	~Panier();

	void ajouter(const vector<Article>& article);
	void retirer();
	void afficher() const;

	//friend bool operator==(const Article& article, string code);
	friend ostream& operator<<(ostream& flux, Panier& panier);

	void payer(const Employe& caissier);

	//void getCode() const;
	//void getNom() const;
	//void getPrix() const;
};

