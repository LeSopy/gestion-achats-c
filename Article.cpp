#include <iostream>
#include <string>
#include<vector>
#include<format>
#include "Article.h"

using namespace std;

Article::Article(string code, string nom, double prix) {
	this->code = code;
	this->nom = nom;
	this->prix = prix;
}

Article::~Article() {
}

bool Article::operator==(string code) const {
	return (this->code == code);
}

ostream& operator<<(ostream& flux, const vector<Article>& articles) {
	for (const Article& article : articles) {
		flux << article.getCode() << ": " << article.getNom() << format(" - {:.2f} $", article.getPrix()) << endl;
	}
	return flux;
}

bool Article::compareCode(string code) const {
	while (true) {
		if ((*this) == code) {
			return true;
		}
		cout << "Veuillez entrer un code valide !! \n";
		cout << "Entrer votre code : ";
		cin >> code;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
}

string Article::getCode() const {
	return this->code;
}

string Article::getNom() const {
	return this->nom;
}

double Article::getPrix() const {
	return this->prix;
}
