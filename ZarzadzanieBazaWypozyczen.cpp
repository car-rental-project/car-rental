#include "ZarzadzanieBazaWypozyczen.hpp"
#include "Data.hpp"

#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <fstream>
using namespace std;


void ZarzadzanieBazaWypozyczen::przegladajBazeWypozyczen() {
	/*Schemat zapisu
	Rejestracja
	imie
	nazwisko
	data poczatkowa
	data koncowa
	kwota
	*/
	std::string wyp = ".\\BazaDanych\\Wypozyczenia\\Rejestracje\\";
	std::string dir = ".\\BazaDanych\\Wypozyczenia"
		std::fstream file;
	std::fstream wypozycznie;

	stdLstring str;
	std::string w_wyp;
	wypozycznie.open(wyp, std::ios::in);
	int fileSize = dir.size();
	if (wypozycznie.good()) {
		while (!wypozycznie.eof()) {
			getline(wypozycznie, w_wyp);
			getline(file, str);
			std::cout << "Dane: " << endl;
			std::cout << "rejestracja: " << w_wyp << end;
			getline(file, str);
			std::cout << "Imie: " << w_wyp << end;
			getline(file, str);
			std::cout << "Nazwisko: " << w_wyp << end;
			getline(file, str);
			std::cout << "Data poczatkowa: " << w_wyp << end;
			getline(file, str);
			std::cout << "Data koncowa:  " << w_wyp << end;
			getline(file, str);
			std::cout << "Kwota: " << w_wyp << end;
		}
	}
	wypozycznie.close();
}
void ZarzadzanieBazaWypozyczen::dodajWypozyczenie() {
	std::string wyp = ".\\BazaDanych\\Wypozyczenia\\Rejestracje\\";
	std::string dir = ".\\BazaDanych\\Wypozyczenia";

	string carsDirectory = ".\\BazaDanych\\Pojazdy\\";
	string globalRej;
	fstream f;
	std::string rejestracja;
	std::string imie;
	std::string	nazwisko;
	std::string	dataPoczatkowa;
	std::string	dataKoncowa;

	std::fstream file;
	std::fstream rejestracje;

	rejestracja.open(wyp, std::ios::app | std::ios:in | std : ios : out);
	if (rejestracja.good()) {
		file.open(dir, std::ios::app | std::ios::out | std::ios::ate);
		if (file.good()) {

			cout << "Podaj rejestracje: ";
			cin >> rejestracja;
			globalRej = rejestracja;
			cout << endl;
			cout << "Podaj Imie nabywcy: ";
			cin >> imie;
			cout << endl;
			cout << "Podaj nazwisko nabywcy: ";
			cout << nazwisko;
			cout << endl;
			cout << "Podaj date poczatkowa: format [dd mm rrrr] ";
			cin >> dataPoczatkowa;
			cout << endl;
			cout << "Podaj date koncowa: format [dd mm rrrr] ";
			cin >> dataKoncowa;
			cout << endl;

			file << rejestracja;
			file << imie;
			file << nazwisko;
			file << dataPoczatkowa;
			file << dataKoncowa;
		}
		file.close();
	}
	//dopisanie wypozyczenia do pojazdu
	string directory = ".\\BazaDanych\\Pojazdy\\";
	string nazwaPliku = directory.insert(directory.size(), rejestracja);
	fstream pojazdyFile;
	pojazdyFile.open(nazwaPliku, std::ios::out | std::ios::app)
		if (pojazdyFile.good()) {
			pojazdyFile << dataPoczatkowa;
			pojazdyFile << dataKoncowa;
		}
	pojazdyFile.close();
	//dopisywanie do pliku Autka aktualnego wypozyczenia
	//tworzy sie wowczas w pliku autka
	// historua wypozyczen
	string fullPath = carsDirectory.append(globalRej);
	f.open(fullpath, ios::out | ios::app);
	if (f.good()) {
		f << "---Wypozyczenie--- \n";
		f << dataPoczatkowa << "\n";
		f << dataKoncowa << "\n";
		f << imie << "\n";
		f << nazwisko << "\n";
	}
	f.close();

}
void ZarzadzanieBazaWypozyczen::usunWypozyczenie() {

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