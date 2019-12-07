#include <iostream>
#include "Wypozyczenie.hpp"
using namespace std;


bool Wypozyczenie::wypozyczAuto(Pojazd* pojazd,Uzytkownik* u, Data dataP, Data dataK) {
	Wypozyczenie * wypozyczenie = new Wypozyczenie();
	wypozyczenie->setAktualne(false);
	wypozyczenie->setDataKoncowa(dataK);
	wypozyczenie->setDataPoczatkowa(dataP);
	wypozyczenie->setPojazd(pojazd);
	wypozyczenie->setUzytkownik(uzytkownik);
	return true;
}

void Wypozyczenie::zwroc() {
	//zrobic
}
void Wypozyczenie::wyswietlWarunki() {
	//TODO
}

Pojazd* Wypozyczenie::getPojazd() {
	return pojazd;
}
Uzytkownik* Wypozyczenie::getUzytkownik() {
	return uzytkownik;
}
bool Wypozyczenie::getAktualne() {
	return aktualne;
}
void Wypozyczenie::setAktualne(bool b) {
	aktualne = b;
}
Data Wypozyczenie::getDataKoncowa() {
	return dataKoncowa;
}
Data Wypozyczenie::getDataPoczatkowa() {
	return dataPoczatkowa;
}
void Wypozyczenie::setDataKoncowa(Data data) {
	dataKoncowa = data;
}
void Wypozyczenie::setDataPoczatkowa(Data data) {
	dataPoczatkowa = data;
}
void Wypozyczenie::setPojazd(Pojazd *pojazd) {
	pojazd = pojazd;
}
void Wypozyczenie::setUzytkownik(Uzytkownik* u) {
	uzytkownik = u;
}