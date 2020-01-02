#include "ZarzadzanieBazaWypozyczen.hpp"
#include <iostream>
#include <cstring>
#include <fstream>

void ZarzadzanieBazaWypozyczen::przegladajBazeWypozyczen() {
	/*Schemat zapisu
	Rejestracja
	imie
	nazwisko
	data poczatkowa
	data koncowa
	kwota
	*/
	std::string wyp = ".\\BazaDanych\\Wypozyczenia\\Rejestracje";
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
	std::string wyp = ".\\BazaDanych\\Wypozyczenia\\Rejestracje";
	std::string dir = ".\\BazaDanych\\Wypozyczenia";

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
		if(file.good()){

			cout << "Podaj rejestracje: ";
			cin >> rejestracja;
			cout << endl;
			cout << "Podaj Imie nabywcy: ";
			cin >> imie;
			cout << endl;
			cout << "Podaj nazwisko nabywcy: ";
			cout << nazwisko;
			cout << endl;
			cout << "Podaj date poczatkowa: ";
			cin >> dataPoczatkowa;
			cout << endl;
			cout << "Podaj date koncowa : ";
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
}
void ZarzadzanieBazaWypozyczen::usunWypozyczenie() {

}