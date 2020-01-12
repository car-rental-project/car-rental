#include "NaliczanieOplat.hpp"
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

void NaliczanieOplat::naliczOplate(string loginKlienta, int kwota) {
	std::string directory = ".\\BazaDanych\\Klienci\\Oplaty\\";
	string fullPath = directory.append(loginKlienta);
	fstream f;
	f.open(fullPath, ios::out | ios::app);
	if (f.good()) {
		f << kwota;
	}
	f.close();
	cout << "Dodano oplate wysokosci " << kwota << " uzytkownikowi " << loginKlienta;

}
void NaliczanieOplat::zaplac(string login) {
	std::string directory = ".\\BazaDanych\\Klienci\\Oplaty\\";
	string fileToRemove = wyp.append(login);

	if (remove(fileToRemove) == 0) {
		cout << "Zaplacono. Dziêkujemy za skorzystanie z uslugi. ";
	}
	else {
		cout << "Cos poszlo nie tak. Upewnij sie, ze na pewno sa jakies oplaty." << endl;
	}
}
