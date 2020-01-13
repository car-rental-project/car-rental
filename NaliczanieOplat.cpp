#include "NaliczanieOplat.hpp"
#include <iostream>
#include <fstream>
#include <stdlib.h> 
#include <string>

void NaliczanieOplat::naliczOplate() {

		std::string tmp;
		std::string login;
		std::string haslo;
		std::string imie;
		std::string nazwisko;
		std::string	pesel;
		int kwota;
		std::string log;
		std::string doDodania;

		std::string loginy = ".\\BazaDanych\\Klienci\\LOGINY";
		std::string directory = ".\\BazaDanych\\Klienci\\";
		std::string newDirectory = ".\\BazaDanych\\Klienci\\";

		std::fstream file;		//plik uzytkownika
		std::fstream temp;
		std::fstream check;
		std::fstream bazaLoginow;
		bool ok = true;

		//bazaLoginow.open(loginy.c_str(), std::ios::out | std::ios::in);
		//if (bazaLoginow.good()) {
		temp.open(".\\BazaDanych\\Klienci\\temp", std::ios::out);
		if (temp.good()) {
			std::cout << "Podaj login klienta do edycji: ";
			std::cin >> login;

			directory.insert(directory.size(), login);
			file.open(directory, std::ios::out | std::ios::in);
			if (file.good()) {

				getline(file, tmp);

				temp << tmp << std::endl;

				getline(file, tmp);

				temp << tmp << std::endl;

				getline(file, tmp);

				temp << tmp << std::endl;

				getline(file, tmp);

				//}
				//ustalenie nowej kwoty do zaplaty 
				std::cout << "Aktualna kwota do zaplaty: ";
				getline(file, tmp);
				kwota = atoi(tmp.c_str());
				std::cout << tmp << std::endl;
				std::cout << "podaj kwote do naliczenia" << std::endl;
				std::cin >> doDodania;
				if (doDodania != "x") {
					temp << kwota << std::endl;
				}
				else {
					kwota += atoi(doDodania.c_str());
					temp << tmp << std::endl;
				}
			}
			else std::cout << "zamiana obecnie nie mozliwa" << std::endl;
		}
		else std::cout << "Blad otwarcia pliku" << std::endl;
		file.close();

		remove(directory.c_str());
		temp.close();
		if (log == "x") {

			rename(".\\BazaDanych\\Klienci\\temp", directory.c_str());
		}
		else {
			rename(".\\BazaDanych\\Klienci\\temp", newDirectory.c_str());
		}
		//}
			//	else std::cout << "zamiana obecnie nie mozliwa" << std::endl;
				//poni¿sza linia dodana
		remove(".\\BazaDanych\\Klienci\\temp");




	}

void NaliczanieOplat::zaplac() {
	std::string tmp;
	std::string login;
	std::string haslo;
	std::string imie;
	std::string nazwisko;
	std::string	pesel;
	int kwota;
	std::string log;
	std::string doDodania;

	std::string loginy = ".\\BazaDanych\\Klienci\\LOGINY";
	std::string directory = ".\\BazaDanych\\Klienci\\";
	std::string newDirectory = ".\\BazaDanych\\Klienci\\";

	std::fstream file;		//plik uzytkownika
	std::fstream temp;
	std::fstream check;
	std::fstream bazaLoginow;
	bool ok = true;

	//bazaLoginow.open(loginy.c_str(), std::ios::out | std::ios::in);
	//if (bazaLoginow.good()) {
	temp.open(".\\BazaDanych\\Klienci\\temp", std::ios::out);
	if (temp.good()) {
		std::cout << "Podaj login klienta do edycji: ";
		std::cin >> login;

		directory.insert(directory.size(), login);
		file.open(directory, std::ios::out | std::ios::in);
		if (file.good()) {

			getline(file, tmp);

			temp << tmp << std::endl;

			getline(file, tmp);

			temp << tmp << std::endl;

			getline(file, tmp);

			temp << tmp << std::endl;

			getline(file, tmp);

			//}
			//ustalenie nowej kwoty do zaplaty 
			std::cout << "Aktualna kwota do zaplaty: ";
			getline(file, tmp);
			kwota = atoi(tmp.c_str());
			std::cout << tmp << std::endl;
			std::cout << "podaj kwote zaplacona" << std::endl;
			std::cin >> doDodania;
			if (doDodania != "x") {
				temp << kwota << std::endl;
			}
			else {
				kwota -= atoi(doDodania.c_str());
				temp << tmp << std::endl;
			}
		}
		else std::cout << "zamiana obecnie nie mozliwa" << std::endl;
	}
	else std::cout << "Blad otwarcia pliku" << std::endl;
	file.close();

	remove(directory.c_str());
	temp.close();
	if (log == "x") {
		rename(".\\BazaDanych\\Klienci\\temp", directory.c_str());
	}
	else {
		rename(".\\BazaDanych\\Klienci\\temp", newDirectory.c_str());
	}
	//}
		//	else std::cout << "zamiana obecnie nie mozliwa" << std::endl;
			//poni¿sza linia dodana
	remove(".\\BazaDanych\\Klienci\\temp");




}
