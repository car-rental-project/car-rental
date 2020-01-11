#include "MenuUzytkownika.hpp"
#include "ZarzadzanieBazaKlientow.hpp"
#include "Wypozyczenie.hpp"

#include <iostream>

void MenuUzytkownika::menuUzytkownik(Uzytkownik &u) {
	unsigned int wybor;
	std::string dataP, dataK;
	std::string id;


	std::cout << "Wpisz cyfre odpowiadajaca akcji:" << std::endl;
	std::cout << "1.Wypo¿ycz pojazd" << std::endl;
	std::cout << "2.Przegladnij baze pojazdow" << std::endl;
	std::cout << "3.Sprawdz warunki wypozyczenia" << std::endl;
	std::cout << "4.Edytuj dane" << std::endl;
	std::cout << "5.Oplaty" << std::endl;

	std::cin >> wybor;

	switch (wybor) {
	//wypozycz pojazd
	case (1):
		std::cout << "data poczatkowa: ";
		std::cin >> dataP;
		Data p(dataP);
		std::cout << std::endl << "data koncowa: ";
		std::cin >> dataK;
		Data k(dataK);
		u.dostepDoPojazdow.wyswietlBazePojazdow(p, k);
		std::cout << "ID pojazdu do wypozyczenia: ";
		std::cin >> id;
		u.wypozyczenie.push_back(new Wypozyczenie);
		//wypozyczenie auta na bazie jego id czyli nazwy pliku w systemie nie obiektu pojazd bo cos takiego w systemie nie bd istniec
		//u.wypozyczenie.at(u.wypozyczenie.back()).wypozyczAuto
		break;
	case(2):
		u.dostepDoPojazdow.wyswietlBazePojazdow();
		break;
	case(3):
		for (int i = 0; i < u.wypozyczenie.size(); ++i) {
			u.wypozyczenie[i].wyswietlWarunki();
		}
		break;
		//edytuj dane
	case(4):
		u.daneKlienta.edytujDaneWBazie();
		break;
		//oplaty
	case(5):
		u.getKwota();
		break;

	}
}