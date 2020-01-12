#include "MenuPracownika.hpp"
#include <iostream>

void MenuPracownika::menuPracownik(Pracownik &p) {

	int wybor;

	std::cout << "Wpisz cyfre odpowiadajaca akcji:" << std::endl;
	std::cout << "1.Nalicz oplaty" << std::endl;
	std::cout << "2.Zaplac" << std::endl;
	std::cout << "3.Oddaj pojazd" << std::endl;

	std::cin >> wybor;

	switch (wybor)
	{
	//nalicz oplaty
	case (1):
		p.naliczanieOplat.naliczOplate();
		break;
	//zaplac
	case(2):
		p.naliczanieOplat.zaplac();
		break;
	//oddaj pojazd
	case(3):
		p.oddaniePojazdu.oddajPojazd();
		break;
	default:
		std::cout << "blad" << std::endl << "sproboj ponownie" << std::endl;
		break;
	}


}