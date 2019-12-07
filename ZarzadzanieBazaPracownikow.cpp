#include"ZarzadzanieBazaPracownikow.hpp"
#include<iostream>
#include<fstream>
#include<string>
#include<conio.h>

void ZarzadzanieBazaPracownikow::przegladajBazePracownikow(){
	std::string loginy = ".\\BazaDanych\\Pracownicy\\LOGINY";
	std::string directory = ".\\BazaDanych\\Pracownicy\\";
	
	int originalDirSize = directory.size();
	std::string tmpLOGINY;
	std::string tmpFile;
	std::fstream file;
	std::fstream LOGINY;
	LOGINY.open(loginy, std::ios::in);
	if (LOGINY.good()) {
		while (LOGINY.eof() == 0) {
			getline(LOGINY, tmpLOGINY);
			directory.insert(directory.size(), tmpLOGINY);
			//ponizsza linijka do testow
			std::cout << directory << std::endl;
			file.open(directory, std::ios::in);
			if (file.good()) {
				getline(file, tmpFile);
				std::cout << "login: " << tmpLOGINY << std::endl;
				std::cout << "haslo: " << tmpFile << std::endl;
				
				getline(file, tmpFile);
				std::cout << "imie: " << tmpFile << std::endl;

				getline(file, tmpFile);
				std::cout << "nazwisko: " << tmpFile << std::endl;

				getline(file, tmpFile);
				std::cout << "pesel: " << tmpFile << std::endl;

				getline(file, tmpFile);
				std::cout << "kwota do zaplaty: " << tmpFile << std::endl;
			}
			else std::cout << "przegladniecie bazy pracownikow nie mozliwe" << std::endl;
			directory.erase(originalDirSize, directory.size());
			//ponizsza linijka pod testy
			//std::cout << directory;
			file.close();
		}
	
	}
	else std::cout << "przegladniecie bazy pracownikow nie mozliwe" << std::endl;
	LOGINY.close();
}

bool exists(const std::string& name) {
	std::ifstream f(name.c_str());
	return f.good();
}

void ZarzadzanieBazaPracownikow::edytujBazePracownikow() {
	std::string tmp;
	std::string login;
	std::string haslo;
	std::string imie;
	std::string nazwisko;
	std::string	pesel;
	std::string kwota;
	std::string log;
	
	std::string loginy = ".\\BazaDanych\\Pracownicy\\LOGINY";
	std::string directory = ".\\BazaDanych\\Pracownicy\\";
	std::string newDirectory = ".\\BazaDanych\\Pracownicy\\";
	
	std::fstream file;
	std::fstream temp;
	std::fstream check;
	bool ok = true;

	temp.open(".\\BazaDanych\\Pracownicy\\temp", std::ios::out);
	if (temp.good()) {
		std::cout << "Podaj login pracownika do edycji: ";
		std::cin >> login;

		directory.insert(directory.size(), login);
		file.open(directory, std::ios::out | std::ios::in);
		if (file.good()) {
			std::cout << "Jesli nie chcesz zmienic danej wpisz \"x\" ";
			while (ok) {
				std::cout << "Aktualny login: " << login << std::endl;
				std::cin >> log;
				newDirectory.insert(newDirectory.size(), log);
				if (exists(newDirectory)) {
					std::cout << "Login zajety sprobuj innego" << std::endl;
				}
				else ok = false;
			}
			file.seekg(0);
			//ustalenie nowego hasla
			std::cout << "Aktualne haslo: ";
			getline(file, tmp);
			std::cout << tmp << std::endl;
			std::cin >> haslo;
			if (haslo != "x") {
				temp << haslo << std::endl;
			}
			else {
				temp << tmp << std::endl;
			}
			//ustalenie nowego imienia
			std::cout << "Aktualne imie: ";
			getline(file, tmp);
			std::cout << tmp << std::endl;
			std::cin >> imie;
			if (imie != "x") {
				temp << imie << std::endl;
			}
			else {
				temp << tmp << std::endl;
			}
			//ustalenie nowego nazwiska
			std::cout << "Aktualne nazwisko: ";
			getline(file, tmp);
			std::cout << tmp << std::endl;
			std::cin >> nazwisko;
			if (nazwisko != "x") {
				temp << nazwisko << std::endl;
			}
			else {
				temp << tmp << std::endl;
			}
			//ustalenie nowego peselu
			std::cout << "Aktualny pesel: ";
			getline(file, tmp);
			std::cout << tmp << std::endl;
			std::cin >> pesel;
			if (pesel != "x") {
				temp << pesel << std::endl;
			}
			else {
				temp << tmp << std::endl;
			}
			//ustalenie nowej kwoty do zaplaty 
			std::cout << "Aktualna kwota do zaplaty: ";
			getline(file, tmp);
			std::cout << tmp << std::endl;
			std::cin >> kwota;
			if (kwota != "x") {
				temp << kwota << std::endl;
			}
			else {
				temp << tmp << std::endl;
			}
		}
		else std::cout << "Blad otwarcia pliku" << std::endl;
		file.close();
	}
	else std::cout << "zamiana obecnie nie mozliwa" << std::endl;
	remove(directory.c_str());
	temp.close();
	if (log == "x") {
		rename(".\\BazaDanych\\Pracownicy\\temp", directory.c_str());
	}
	else {
		rename(".\\BazaDanych\\Pracownicy\\temp", newDirectory.c_str());
	}

	
	

}
void ZarzadzanieBazaPracownikow::dodajPracownika() {
	std::string tmp;
	std::string login;

	std::string loginy = ".\\BazaDanych\\Pracownicy\\LOGINY";
	std::string directory = ".\\BazaDanych\\Pracownicy\\";
	
	std::fstream file;
	std::fstream LOGINY;

	bool ok = true;
	while (ok) {
		std::cout << "Podaj login: ";
		std::cin >> login;
		
		directory.insert(directory.size(), login);
		if (exists(directory)) {
			std::cout << "login zajety" << std::endl;
		}
		else ok = false;
	}
	//do testow
	//std::cout << directory;
	LOGINY.open(loginy, std::ios::app | std::ios::out);
	if (LOGINY.good()) {
		
		file.open(directory, std::ios::app | std::ios::out | std::ios::ate);
		if (file.good()) {
			//dodanie do bazy loginow
			LOGINY << login << std::endl;
			//haslo
			std::cout << "Podaj has³o: ";
			std::cin >> tmp;
			file << tmp << std::endl;
			//imie
			std::cout << "Podaj imie: ";
			std::cin >> tmp;
			file << tmp << std::endl;
			//nazwisko
			std::cout << "Podaj nazwisko: ";
			std::cin >> tmp;
			file << tmp << std::endl;
			//pesel
			std::cout << "Podaj pesel: ";
			std::cin >> tmp;
			file << tmp << std::endl;
			//kwota do zaplaty
			file << 0 << std::endl;
		}
		else std::cout << "Blad otwarcia pliku";

		file.close();
	}
	else std::cout << "Dodanie uzytkownika nie mozliwe, sprobuj ponownie pozniej" << std::endl;
}

bool removeLine(std::string fileDirectory,std::string fileName,std::string toDelete) {
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
			if (tmpString != toDelete) {
				tmp << tmpString << std::endl;
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

void ZarzadzanieBazaPracownikow::usunPracownika() {
	std::string tmp;
	std::string login;
	std::string directory = ".\\BazaDanych\\Pracownicy\\";
	std::string tmpDir = ".\\BazaDanych\\Pracownicy\\";
	std::string logDirectory = ".\\BazaDanych\\Pracownicy\\";
	logDirectory.insert(logDirectory.size(), "LOGINY");
	std::fstream LOGINY;
	
	LOGINY.open(logDirectory, std::ios::out);
	if (LOGINY.good()) {
		bool ok = true;
		while (ok) {
			std::cout << "Podaj login" << std::endl;
			std::cin >> login;

			directory.insert(directory.size(), login);
			if (!exists(directory)) {
				std::cout << "taki pracownik nie istnieje" << std::endl;
			}
			else ok = false;
		}
		
		removeLine(tmpDir, directory, login);
	}
	else std::cout << "usuniecie pracownika niemozliwe" << std::endl;
}