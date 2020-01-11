#ifndef POJAZD_HPP
#define POJAZD_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Wypozyczenie.hpp"

using namespace std;

class Pojazd {
private:
	string rejestracja;
	string marka;
	string model;
	unsigned int pojemnoscSilnika;
	unsigned int pojemnoscBagaznika;
	unsigned int liczbaDrzwi;
	float moc;
	char klasa;
	long unsigned int przebieg;
	std::vector <Wypozyczenie> wypozyczenie;
public:
	string getRejestracja();
	string getMarka();
	string getModel();
	int getPojemnoscSilnika();
	int getPojemnoscBagaznika();
	int getLiczbaDrzwi();
	float getMoc();
	char getKlasa();
	long unsigned int getPrzebieg();
	void setRejestracja(string r);
	void setMarka(string m);
	void setModel(string m);
	void setPojemnoscSilnika(int p);
	void setLiczbaDrzwi(int l);
	void setMoc(float m);
	void setKlasa(char k);
	void setPrzebieg(int p);
	void wyswietlDane();
	void setPojemnoscBagaznika(int p);
};
#endif