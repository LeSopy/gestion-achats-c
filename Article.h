#pragma once
#include<string>
#include<vector>
using namespace std;

class Article
{
private:
	//const int nombreArticle = 10;
	string code;
	double prix;
	string nom;

public:
	Article(string code, string nom, double prix);
	~Article();

	// Accesseurs
	string getCode() const;
	double getPrix() const;
	string getNom() const;

	// Surcharge operateur==
	bool operator==(string code) const;

	// je declare cette fonction friend ici pour pouvoir acces a ses attributs prives 
	// dans Panier.cpp
	//friend bool operator==(const Article& article, string code);

	//surcharge operateur<<
	friend ostream& operator<<(ostream& flux, const vector<Article>& articles);

	bool compareCode(string code) const;
};

