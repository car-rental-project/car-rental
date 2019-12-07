#include <iostream>
#include <cstdio>
#include "Pojazd.hpp"
using namespace std;


void Pojazd::wyswietlDane() {
		return "\nMarka : " + marka +
			"\nModel : " + model +
			"\nrejestracja : " + rejestracja +
			"\nKlasa : " + klasa +
			"\nPrzebieg : " + przebieg +
			"\nMoc : " + moc +
			"\nPojemnosc Silnika : " + pojemnoscSilnika +
			"\nLiczba drzwi : " + liczbaDrzwi +
			"\nPojemnosc Bagaznika : " + pojemnoscBagaznika;
}