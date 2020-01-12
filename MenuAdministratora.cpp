#include "MenuAdministratora.hpp"
#include <iostream>

void MenuAdministratora::menuAdministrator(Administrator &a) {

	int wybor;
	std::string login;
	std::string rejestracja;

	std::cout << "Wpisz cyfre odpowiadajaca akcji:" << std::endl;
	std::cout << "1. Zarzadzaj baza klientow" << std::endl;
	std::cout << "2. Zarzadzaj baza pracownikow" << std::endl;
	std::cout << "3. Zarzadzaj baza pojazdow" << std::endl;

	std::cin >> wybor;

	switch (wybor)
	{
	//klienci
	case(1):
		std::cout << std::endl << "1. Przegladaj baze klientow" << std::endl;
		std::cout << "2. Dodaj klienta" << std::endl;
		std::cout << "3. Edytuj klienta" << std::endl;
		std::cout << "4. Usun klienta" << std::endl;
		std::cout << "5. Przegladaj wypozyczenia klienta" << std::endl;

		std::cin >> wybor;

		switch (wybor) {
			//przegladaj
		case(1):
			a.zarzadzanieBazaKlientow.przegladajBazeKlientow();
			break;
			//dodaj
		case(2):
			a.zarzadzanieBazaKlientow.dodajKlienta();
			break;
			//edytuj
		case(3):
			a.zarzadzanieBazaKlientow.edytujBazeKlientow();
			break;
		//usun
		case(4):
			a.zarzadzanieBazaKlientow.usunKlienta();
			break;
		case(5):
			std::cout << "Podaj login" << std::endl;
			std::cin >> login;
			a.zarzadzanieBazaKlientow.przegladajWypozyczenia(login);
			break;
		default:
			std::cout << "blad" << std::endl << "sproboj ponownie" << std::endl;
			break;
		}
		break;
	//pracownicy
	case(2):
		std::cout << std::endl << "1. Przegladaj baze pracownikow" << std::endl;
		std::cout << "2. Dodaj pracownika" << std::endl;
		std::cout << "3. Edytuj pracownika" << std::endl;
		std::cout << "4. Usun pracownika" << std::endl;

		std::cin >> wybor;

		switch (wybor) {
			//przegladaj
		case(1):
			a.zarzadzanieBazaPracownikow.przegladajBazePracownikow();
			break;
			//dodaj
		case(2):
			a.zarzadzanieBazaPracownikow.dodajPracownika();
			break;
			//edytuj
		case(3):
			a.zarzadzanieBazaPracownikow.edytujBazePracownikow();
			break;
			//usun
		case(4):
			a.zarzadzanieBazaPracownikow.usunPracownika();
			break;
		default:
			std::cout << "blad" << std::endl << "sproboj ponownie" << std::endl;
			break;
		break;
		}
	//pojazdy
	case(3):
		std::cout << std::endl << "1. Przegladaj baze pojazdow" << std::endl;
		std::cout << "2. Dodaj pojazd" << std::endl;
		std::cout << "3. Edytuj pojazd" << std::endl;
		std::cout << "4. Usun pojazd" << std::endl;

		std::cin >> wybor;

		switch (wybor) {
		//przegladaj baze pojazdow
		case(1):
			a.zarzadzanieBazaPojazdow.przegladajBazePojazdow();
			break;
		//dodaj
		case(2):
			a.zarzadzanieBazaPojazdow.dodajPojazd();
			break;
		//edytuj
		case(3):
			std::cout << "podaj rejestracje" << std::endl;
			std::cin >> rejestracja;
			std::cout << "wybierz co chcesz edytowac" << std::endl;
			std::cout << "0. " << std::endl;
			std::cout << "1. " << std::endl;
			std::cout << "2. " << std::endl;
			std::cout << "3. " << std::endl;
			std::cout << "4. " << std::endl;
			std::cout << "5. " << std::endl;
			std::cout << "6. " << std::endl;
			std::cout << "7. " << std::endl;
			std::cin >> wybor;
			a.zarzadzanieBazaPojazdow.edytujBazePojazdow(rejestracja,wybor);
			break;
		//usun
		case(4):
			std::cout << "podaj rejestracje" << std::endl;
			std::cin >> rejestracja;
			a.zarzadzanieBazaPojazdow.usunPojazd(rejestracja);
			break;

		}
		break;
	default:
		std::cout << "blad" << std::endl << "sproboj ponownie" << std::endl;

		break;
	}

}