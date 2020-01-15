#include "OddaniePojazdu.hpp"
#include "ZarzadzanieBazaWypozyczen.hpp"
#include "Data.hpp"

#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <fstream>
using namespace std;



void OddaniePojazdu::oddajPojazd() {

	string dateStartDay, dateStartMonth, dateStartYear, dateEndDay, dateEndMonth, dateEndYear;
	string fileName;
	cout << "Rejestracja zwracanego samochodu: ";
	cin >> fileName;
	cout << "\nProsze podaæ daty wypo¿yczenia i zwrotu Pojazdu" << endl;
	cout << "Data wypozyczenia: format [dd mm rrrr] : ";
	cin >> dateStartDay >> dateStartMonth >> dateStartYear;
	cout << "Data oddania pojazdu : ";
	cin >> dateEndDay >> dateEndMonth >> dateStartYear;

	Data k1(dateStartDay, dateStartMonth, dateStartYear);
	Data k2(dateEndDay, dateEndMonth, dateEndYear);

	std::string wyp = ".\\BazaDanych\\Wypozyczenia\\Rejestracje\\";
	string carsDirectory = ".\\BazaDanych\\Pojazdy\\";
	string path = wyp.append(fileName);
	string pojazdy = carsDirectory.append(filename);
	fstream f;
	int d1, m1, r1, d2, m2, r2;
	f.open(pojazdy, ios::out | ios::app);

	if (f.good()) {
		string ln;

		for (int i = 0; i < 8; i++) {
			getline(f, ln);
		}
		while (!f.eof()) {
			f >> d1 >> m1 >> r1;
			Data p1(d1, m1, r1);
			bool isEqual = czyDatyTeSame(p1, k1);

			if (isEqual == true) { f << ""; }
			f >> d2 >> m2 >> r2;
			Data p2(d2, m2, r2);
			bool isEqual2 = czyDatyTeSame(p2, k2);
			if (isEqual2 == true) { f << ""; }
		}
	}
	f.close();

	if (remove(path) == 0) {
		cout << "Usuniêto wypozyczenie";
	}
	else {
		cout << "Cos poszlo nie tak. Upewnij sie, ze pojazd nie zostal juz zwrocony" << endl;
	}




}