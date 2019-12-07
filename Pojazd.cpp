#include <iostream>
#include "Pojazd.hpp"
using namespace std;

void Pojazd::wyswietlDane() {
	 cout<<"\nMarka : "<<this->getMarka()<<
		"\nModel : "<<this->getModel()<<
		"\nrejestracja : "<<this->getRejestracja()<<
		"\nKlasa : "<<this->getKlasa()<<
		"\nPrzebieg : "<<this->getPrzebieg()<<
		"\nMoc : "<<this->getMoc()<<
		"\nPojemnosc Silnika : "<<this->getPojemnoscSilnika()<<
		"\nLiczba drzwi : "<<this->getLiczbaDrzwi()<<
		"\nPojemnosc Bagaznika : "<<this->getPojemnoscBagaznika();
}

string Pojazd::getRejestracja() {
	return rejestracja;
}
string Pojazd::getMarka() {
	return marka;
}
string Pojazd::getModel() {
	return model;
}
int Pojazd::getPojemnoscBagaznika() {
	return pojemnoscBagaznika;
}

int Pojazd::getPojemnoscSilnika() {
	return pojemnoscSilnika;
}
int Pojazd::getLiczbaDrzwi() {
	return liczbaDrzwi;
}
float Pojazd::getMoc() {
	return moc;
}
char Pojazd::getKlasa() {
	return klasa;
}
long unsigned int Pojazd::getPrzebieg() {
	return przebieg;
}
void Pojazd::setRejestracja(string r) {
	rejestracja = r;
}
void Pojazd::setMarka(string m) {
	marka = m;
}
void Pojazd::setModel(string m) {
	model = m;
}
void Pojazd::setPojemnoscSilnika(int m) {
	pojemnoscSilnika = m;
}
void Pojazd::setLiczbaDrzwi(int l) {
	liczbaDrzwi = l;
}
void Pojazd::setMoc(float m) {
	moc = m;
}
void Pojazd::setKlasa(char l) {
	klasa = l;
}
void Pojazd::setPrzebieg(int p) {
	przebieg = p;
}
void Pojazd::setPojemnoscBagaznika(int p) {
	pojemnoscBagaznika = p;
}