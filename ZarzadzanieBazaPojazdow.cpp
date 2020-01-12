#include <iostream>
#include <cstdio>
#include <vector>
#include "ZarzadzanieBazaPojazdow.hpp"
#include "Pojazd.hpp"
#include "Data.hpp"

using namespace std;

const string plikZRejestracjami;

void ZarzadzanieBazaPojazdow::dodajPojazd() {
	std::string rejestracja;
	fstream plik;
	fstream wszystkiePojazdy :
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
void ZarzadzanieBazaPojazdow::usunPojazd(string rejestracja) {
	string directory = ".\\BazaDanych\\Pojazdy\\";
	string nazwaPliku = directory.append(rejestracja);
	remove(nazwaPliku.c_str());
	cout << "Pojazd usunieto" << endl;
}
void ZarzadzanieBazaPojazdow::edytujBazePojazdow(string rejestracja, int opcja) {
	Pojazd *pojazd = this->znajdzPojazd(rejestracja);
	if (opcja == 0) {
		string nr;
		cout << "\nPodaj nowy numer rejestracji : ";
		cin >> nr;
		pojazd->setRejestracja(nr);
	}
	if (opcja == 1) {
		int p;
		cout << "\nPodaj nowa pojemnosc silnika : ";
		cin >> p;
		pojazd->setPojemnoscSilnika(p);
	}
	if (opcja == 2) {
		int p;
		cout << "\nPodaj nowy przebieg : ";
		cin >> p;
		pojazd->setPrzebieg(p);
	}
	this->usunPojazd(rejestracja);
	this->dodajPojazd(pojazd);

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