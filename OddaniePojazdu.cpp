#include "OddaniePojazdu.hpp"
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

void OddaniePojazdu::oddajPojazd(string rejestracja) {
	std::string wypPath = ".\\BazaDanych\\Wypozyczenia\\Rejestracje\\";
	string path = wypPath.append(rejestracja);

	if (remove(path) == 0) {
		cout << "Pojazd zosta³ oddany pomyslnie\n\nHistoria wypozyczenia zostala zapisania w informacjach o pojezdzie";
	}
	else {
		cout << "Cos poszlo nie tak. Upewnij sie, ze pojazd nie zostal juz zwrocony" << endl;
	}


}