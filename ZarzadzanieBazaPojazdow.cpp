#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include "ZarzadzanieBazaPojazdow.hpp"
#include "Pojazd.hpp"
#include "Data.hpp"

using namespace std;

const string plikZRejestracjami;

bool removeLine(std::string fileDirectory, std::string fileName, std::string toDelete) {
	std::fstream tmp;
	std::fstream file;

	std::string tmpDirectory;
	std::string tmpString;

	tmpDirectory = fileDirectory;
	tmpDirectory.insert(tmpDirectory.size(), "tmp");
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

void ZarzadzanieBazaPojazdow::dodajPojazd() {
	string rejestracja;
	fstream plik;
	fstream wszystkiePojazdy;
	string directory = ".\\BazaDanych\\Pojazdy\\";

	string marka;
	string model;
	string klasa;
	string moc;
	string pojemnoscB;
	string przebieg;
	string pojemnoscS;
	string drzwi;


	std::cout << "podaj rejestracje " << std::endl;
	std::cin >> rejestracja;
	string nazwaPliku = directory.append(rejestracja);
	std::cout << "podaj marke" << std::endl;
	std::cin >> marka;
	std::cout << "podaj model" << std::endl;
	std::cin >> model;
	std::cout << "podaj klase" << std::endl;
	std::cin >> klasa;
	std::cout << "podaj moc" << std::endl;
	std::cin >> moc;
	std::cout << "podaj pojemnosc bagaznika" << std::endl;
	std::cin >> pojemnoscB;
	std::cout << "podaj przebieg" << std::endl;
	std::cin >> przebieg;
	std::cout << "podaj pojemnosc silnika" << std::endl;
	std::cin >> pojemnoscS;
	std::cout << "podaj ilosc drzwi" << std::endl;
	std::cin >> drzwi;
	plik.open(nazwaPliku, ios::out | ios::app);
	if (plik.good() == true) {
		plik << marka << "\n"
			<< model << "\n"
			<< klasa << "\n"
			<< moc << "\n"
			<< pojemnoscB << "\n"
			<< przebieg << "\n"
			<< pojemnoscS << "\n"
			<< drzwi << "\n";
	}
	else {
		cout << "Wystapil blad." << endl;
	}

	plik.close();
	wszystkiePojazdy.open(plikZRejestracjami, ios::out | ios::app);
	if (wszystkiePojazdy.good()) {
		wszystkiePojazdy << rejestracja << "\n";
	}
	wszystkiePojazdy.close();
}

void ZarzadzanieBazaPojazdow::wypiszDanyPojazd(Pojazd * pojazd) {
	string linia;
	fstream plik;
	string directory = ".\\BazaDanych\\Pojazdy\\";
	string rejestracja = pojazd->getRejestracja();
	string nazwaPliku = directory.append(rejestracja);

	plik.open(nazwaPliku, ios::out | ios::app);
	if (plik.good() == true)
	{
		plik << pojazd->getRejestracja() << "\n"
			<< pojazd->getMarka() << "\n"
			<< pojazd->getModel() << "\n"
			<< pojazd->getKlasa() << "\n"
			<< pojazd->getMoc() << "\n"
			<< pojazd->getPojemnoscBagaznika() << "\n"
			<< pojazd->getPrzebieg() << "\n"
			<< pojazd->getPojemnoscSilnika() << "\n"
			<< pojazd->getLiczbaDrzwi();
		plik.close();
	}
	cout << "Pojazd o rejestracji [" << pojazd->getRejestracja() << "]" << " dodano" << endl;
	system("PAUSE");
}
void ZarzadzanieBazaPojazdow::usunPojazd() {
	string rejestracja;
	string directory = ".\\BazaDanych\\Pojazdy\\";
	cout << "\nPodaj rejestracje pojazdu do usuniecia: ";
	cin >> rejestracja;

	string nazwaPliku = directory.append(rejestracja);

	if (!exists(nazwaPliku)) {
		std::cout << "Taki Pojazd nie istnieje" << std::endl;
	}
	else {
		remove(nazwaPliku.c_str());
		cout << "Pojazd usunieto." << endl;
	}
}
/*Schemat zapisu
			f >> marka;
				f >> model;
				f >> klasa;
				f >> moc;
				f >> pojemnoscB;
				f >> przebieg;
				f >> pojemnoscS;
				f >> drzwi;
*/
void ZarzadzanieBazaPojazdow::edytujBazePojazdow() {
	string marka;
	string model;
	string klasa;
	string moc;
	string pojemnoscB;
	string przebieg;
	string pojemnoscS;
	string drzwi;

	string markaX;
	string modelX;
	string klasaX;
	string mocX;
	string pojemnoscBX;
	string przebiegX;
	string pojemnoscSX;
	string drzwiX;

	bool ok = true;

	fstream f;
	string rej;
	string directory = ".\\BazaDanych\\Pojazdy\\";
	string nazwaPliku = directory.insert(directory.size(), rej);
	cout << "Podaj rejstracje pojazdu do edycji: ";
	cin >> rej;

	f.open(nazwaPliku, std::ios::out | std::ios::in);
	if (f.good()) {
		std::cout << "Jesli nie chcesz zmienic danej wpisz \"x\" " << endl;
		f >> marka;
		cout << "Marka: " << marka << endl;
		std::cin >> markaX;
		if (markaX != "x") {
			f << markaX << endl;
		}
		else {
			f << marka << endl;
		}
		f >> model;
		cout << "Model: " << model << endl;
		std::cin >> modelX;
		if (modelX != "x") {
			f << modelX << endl;
		}
		else {
			f << model << endl;
		}
		f >> klasa;
		cout << "Klasa: " << klasa << endl;
		std::cin >> klasaX;
		if (klasaX != "x") {
			f << klasaX << endl;
		}
		else {
			f << klasa << endl;
		}
		f >> moc;
		cout << "Moc: " << moc << endl;
		std::cin >> mocX;
		if (mocX != "x") {
			f << mocX << endl;
		}
		else {
			f << moc << endl;
		}
		f >> pojemnoscB;
		cout << "Pojemnosc bagaznika: " << pojemnoscB << endl;
		std::cin >> pojemnoscBX;
		if (pojemnoscBX != "x") {
			f << pojemnoscBX << endl;
		}
		else {
			f << pojemnoscB << endl;
		}
		f >> pojemnoscS;
		cout << "Pojemnosc silnika: " << pojemnoscS << endl;
		std::cin >> pojemnoscSX;
		if (pojemnoscSX != "x") {
			f << pojemnoscSX << endl;
		}
		else {
			f << pojemnoscS << endl;
		}
		f >> przebieg;
		cout << "Przebieg: " << przebieg << endl;
		std::cin >> przebiegX;
		if (przebiegX != "x") {
			f << przebiegX << endl;
		}
		else {
			f << przebieg << endl;
		}
		f >> drzwi;
		cout << "Liczba drzwi: " << drzwi << endl;
		std::cin >> drzwiX;
		if (drzwiX != "x") {
			f << drzwiX << endl;
		}
		else {
			f << drzwi << endl;
		}
	else {
		std::cout << "Zamiana obecnie niemozliwa" << std::endl;
	}
		else std::cout << "Blad otwarcia pliku" << std::endl;
		f.close();
	}
}
Pojazd* ZarzadzanieBazaPojazdow::znajdzPojazd(string rejestracja) {
	string ln;
	fstream dataFile;
	string directory = ".\\BazaDanych\\Pojazdy\\";
	string nazwaPliku = directory.append(rejestracja);
	Pojazd* pojazd = new Pojazd();
	dataFile.open(nazwaPliku, ios::in);
	if (dataFile.good()) {
		while (!dataFile.eof()) {

			string rejestracja;
			string marka;
			string model;
			string pojemnoscSilnika;
			string pojemnoscBagaznika;
			string liczbaDrzwi;
			string moc;
			string klasa;
			string przebieg;

			getline(dataFile, ln);
			getline(dataFile, rejestracja, ' ');
			pojazd->setRejestracja(rejestracja);

			getline(dataFile, ln);
			getline(dataFile, marka, ' ');
			pojazd->setMarka(marka);

			getline(dataFile, ln);
			getline(dataFile, model, ' ');
			pojazd->setMarka(model);

			getline(dataFile, ln);
			getline(dataFile, pojemnoscSilnika, ' ');
			pojazd->setPojemnoscSilnika(std::atoi(pojemnoscSilnika.c_str()));


			getline(dataFile, ln);
			getline(dataFile, pojemnoscBagaznika, ' ');
			pojazd->setPojemnoscBagaznika(std::atoi(pojemnoscBagaznika.c_str()));

			getline(dataFile, ln);
			getline(dataFile, liczbaDrzwi, ' ');
			pojazd->setLiczbaDrzwi(std::atoi(liczbaDrzwi.c_str()));

			getline(dataFile, ln);
			getline(dataFile, moc, ' ');
			pojazd->setLiczbaDrzwi(std::atoi(moc.c_str()));

			getline(dataFile, ln);
			getline(dataFile, klasa, ' ');
			pojazd->setLiczbaDrzwi(klasa[0]);

			getline(dataFile, ln);
			getline(dataFile, przebieg, ' ');
			pojazd->setPrzebieg(std::atoi(przebieg.c_str()));
		}
		dataFile.close();
	}
	return pojazd;
}

void ZarzadzanieBazaPojazdow::przegladajBazePojazdow() {
	list<string> vectorRejestracji;
	fstream plik;
	string tempRej;
	plik.open(plikZRejestracjami, ios::in);
	if (plik.good()) {
		while (!plik.eof()) {
			plik >> tempRej;

			vectorRejestracji.push_back(tempRej);
		}
	}

	string directory = ".\\BazaDanych\\Pojazdy\\";
	std::string wyp = ".\\BazaDanych\\Wypozyczenia\\Rejestracje\\";
	string nazwaPliku;
	string nazwaWypozyczenia;
	string daneWypozyczenia;
	string rejestracja;
	string marka;
	string model;
	string klasa;
	string moc;
	string pojemnoscB;
	string przebieg;
	string pojemnoscS;
	string drzwi;

	fstream f;
	fstream wypozStream;

	for (std::list<std::string>::const_iterator i = vectorRejestracji.begin(); i != vectorRejestracji.end(); ++i) {

		nazwaPliku = directory.append(*i);
		nazwaWypozyczenia = wyp.append(*i);
		f.open(nazwaPliku, ios::in);
		if (f.good()) {
			while (!f.eof()) {
				rejestracja = *i;
				f >> marka;
				f >> model;
				f >> klasa;
				f >> moc;
				f >> pojemnoscB;
				f >> przebieg;
				f >> pojemnoscS;
				f >> drzwi;
				cout << "\n-------------------\n";
				cout << "Pojazd o rejestracji: " << rejestracja << endl;
				cout << "Marka: " << marka << endl;
				cout << "Model: " << model << endl;
				cout << "Klasa: " << klasa << endl;
				cout << "Moc: " << moc << endl;
				cout << "Pojemnosc bagaznika: " << pojemnoscB << endl;
				cout << "Pojemnosc silnika: " << pojemnoscS << endl;
				cout << "Przebieg: " << przebieg << endl;
				cout << "Liczba drzwi: " << drzwi << endl;
				f.close();
			}
		}
		cout << "Historia wypozyczen: " << endl;
		wypozStream.open(nazwaWypozyczenia, ios::in);
		if (wypozStream.good()) {
			while (!wypozStream.eof()) {
				wypozStream >> daneWypozyczenia;
				cout << daneWypozyczenia << " \n";
			}
		}
		wypozStream.close();
	}

	cout << "------------";
}
void ZarzadzanieBazaPojazdow::przegladajBazePojazdow(Data P, Data K) {
	
	int d1, m1, r1, d2, m2, r2;

	list<string> vectorRejestracji;
	fstream plik;
	string tempRej;
	plik.open(plikZRejestracjami, ios::in);
	if (plik.good()) {
		while (!plik.eof()) {
			plik >> tempRej;

			vectorRejestracji.push_back(tempRej);
		}
	}

	string directory = ".\\BazaDanych\\Pojazdy\\";
	std::string wyp = ".\\BazaDanych\\Wypozyczenia\\Rejestracje\\";
	string nazwaPliku;
	string nazwaWypozyczenia;
	string daneWypozyczenia;
	string rejestracja;
	string marka;
	string model;
	string klasa;
	string moc;
	string pojemnoscB;
	string przebieg;
	string pojemnoscS;
	string drzwi;

	fstream f;
	fstream wypozStream;

	for (std::list<std::string>::const_iterator i = vectorRejestracji.begin(); i != vectorRejestracji.end(); ++i) {

		nazwaPliku = directory.append(*i);
		nazwaWypozyczenia = wyp.append(*i);
		f.open(nazwaPliku, ios::in);
		if (f.good()) {
			while (!f.eof()) {
				rejestracja = *i;
				f >> marka;
				f >> model;
				f >> klasa;
				f >> moc;
				f >> pojemnoscB;
				f >> przebieg;
				f >> pojemnoscS;
				f >> drzwi;
				while (f.eof()) {
					//format daty [dd mm rrrr]
					//bool porownanieZakresu(Data p1, Data k1, Data p2, Data k2) {
					//zwraca true jesli przedzialy czasowe ze soba nie koliduja
					//p1 k1 - z pliku, p2 k2 - z argumentow
					f >> d1 >> m1 >> r1;
					f >> d2 >> m2 >> r2;
					Data p1(d1, m1, r1);
					Data p2(d2, m2, r2);
					bool czyKoliduje = porownanieZakresu(p1, p2, P, K);
					if (czyKoliduje == true) {
						cout << "\n-------------------\n";
						cout << "Pojazd o rejestracji: " << rejestracja << endl;
						cout << "Marka: " << marka << endl;
						cout << "Model: " << model << endl;
						cout << "Klasa: " << klasa << endl;
						cout << "Moc: " << moc << endl;
						cout << "Pojemnosc bagaznika: " << pojemnoscB << endl;
						cout << "Pojemnosc silnika: " << pojemnoscS << endl;
						cout << "Przebieg: " << przebieg << endl;
						cout << "Liczba drzwi: " << drzwi << endl;
					}
				}
			}
		}
		f.close();

		cout << "Historia wypozyczen: " << endl;
		wypozStream.open(nazwaWypozyczenia, ios::in);
		if (wypozStream.good()) {
			while (!wypozStream.eof()) {
				wypozStream >> daneWypozyczenia;
				cout << daneWypozyczenia << " \n";
			}
		}
		wypozStream.close();
	}

	cout << "------------";
}