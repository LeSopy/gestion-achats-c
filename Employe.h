#pragma once
#include<string>
#include<vector>
using namespace std;

class Employe
{
private:
	string numero;
	string nom;
public:
	//Constructeur
	Employe();
	Employe(string numero, string nom);

	// Destructeur
	~Employe();

	//Accesseurs
	string getNom() const;
	string getNumero() const;

	string authentification() const;
	bool operator==(string numero) const;
	//friend istream& operator>>(istream& flux, string& numero);
};

