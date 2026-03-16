#include <iostream>
#include <string>
#include<vector>

#include "Employe.h"
using namespace std;

Employe::Employe(string numero, string nom) {
	this->nom = nom;
	this->numero = numero;
}

Employe::Employe() {
	this->numero = "000";
	this->nom = "Inconnu";
}

Employe::~Employe() {

}

bool Employe::operator==(string numero) const {
	return (this->numero == numero);
}

//string Employe::authentification() const {
//	cout << "Entrer votre code : ";
//	cin >> numero;
//	cin.clear();
//	cin.ignore(numeric_limits<streamsize>::max(), '\n');
//
//	while (true) {
//		if ((*this) == numero) {
//			return this->nom;
//		}
//		cout << "Veuillez entrer un code valide !! \n";
//		cout << "Entrer votre code : ";
//		cin >> numero;
//		cin.clear();
//		cin.ignore(numeric_limits<streamsize>::max(), '\n');
//	}
//}

string Employe::getNom() const {
	return this->nom;
}

string Employe::getNumero() const {
	return this->numero;
}
