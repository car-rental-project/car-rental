#include <iostream>
#include <fstream>
#include "Wypozyczenie.hpp"

using namespace std;

bool removeLine(std::string fileDirectory, std::string fileName, std::string toDelete) {
	std::fstream tmp;
	std::fstream file;

	std::string tmpDirectory;
	//std::string fileTmpDirectory;
	std::string tmpString;

	tmpDirectory = fileDirectory;
	tmpDirectory.insert(tmpDirectory.size(), "tmp");

	//fileTmpDirectory = fileDirectory;
	fileDirectory.insert(fileDirectory.size(), fileName);

	tmp.open(tmpDirectory, std::ios::out);
	file.open(fileDirectory, std::ios::in);
	if (tmp.good() && file.good()) {
		while (file.eof() == 0) {
			getline(file, tmpString);
			if (file.eof() == 0) {
				if (tmpString != toDelete) {
					tmp << tmpString << std::endl;
				}
			}
			else {
				if (tmpString != toDelete) {
					tmp << tmpString;
				}
			}
		}
		file.close();
		tmp.close();
		remove(fileDirectory.c_str());
		rename(tmpDirectory.c_str(), fileDirectory.c_str());
		return true;
	}
	else return false;
}

bool Wypozyczenie::wypozyczAuto(std::string login, Data datak, Data dataP,std::string id) {
	//wypozyczenie powinno zapisac sie do pliku uzytkownika
	std::fstream plik;
	std::string directory = ".\\BazaDanych\\Klienci\\";
	directory.insert(directory.size(), login);

	plik.open(directory,std::ios::app | std::ios::out);
	if (plik.good()) {
		plik << dataP.getDataStr() << std::endl;
		plik << datak.getDataStr() << std::endl;
		plik << "true" << std::endl;
		plik << id << std::endl;
		plik.close();
		return true;

	}
	else {
		std::cout << "Blad. Sprobuj ponownie pozniej" << std::endl;
		return false;
	}
}

void Wypozyczenie::zwroc(std::string id,std::string login) {
	//zrobic
	//do pliku uzytkownika
	std::fstream plik;
	std::string tmp1,tmp2;
	std::string aktualne;
	std::string rejestracja;
	std::string directory = ".\\BazaDanych\\Klienci\\";
	std::string directoryOld = ".\\BazaDanych\\Klienci\\";
	int when = 5 ;
	bool stop = false;
	directory.insert(directory.size(), login);

	plik.open(directory, std::ios::out );
	if (plik.good()) {
		for (int i = 0; i < 5; ++i) {
			getline(plik, tmp1);
		}
		while (stop != true) {
			getline(plik, tmp1);
			getline(plik, tmp2);
			getline(plik, aktualne);
			getline(plik, rejestracja);
			
			if (rejestracja == id) {
				stop = true;
			}
		}
		plik.close();
		removeLine(directoryOld, login, tmp1);
		removeLine(directoryOld, login, tmp2);
		removeLine(directoryOld, login, aktualne);
		removeLine(directoryOld, login, rejestracja);
	
		plik.open(directory, std::ios::out | std::ios::app);
		if (plik.good()) {
			plik << tmp1 << std::endl;
			plik << tmp2 << std::endl;
			plik << aktualne << std::endl;
			plik << rejestracja << std::endl;
		}
	}
	else {
		std::cout << "Blad. Sprobuj ponownie pozniej" << std::endl;
		
	}

}
void Wypozyczenie::wyswietlWarunki() {
	//TODO
}

Pojazd* Wypozyczenie::getPojazd() {
	return pojazd;
}
/*Uzytkownik* Wypozyczenie::getUzytkownik() {
	return uzytkownik;
}*/
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
/*void Wypozyczenie::setUzytkownik(Uzytkownik* u) {
	uzytkownik = u;
}*/