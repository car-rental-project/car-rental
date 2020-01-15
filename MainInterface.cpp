#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include "ZarzadzanieBazaPojazdow.hpp"
#include "Administrator.hpp"
#include "DaneKlienta.hpp"
#include "DostepDoPojazdow.hpp"
#include "Logowanie.hpp"
#include "MenuAdministratora.hpp"
#include "MenuPracownika.hpp"
#include "MenuUzytkownika.hpp"
#include "NaliczanieOplat.hpp"
#include "OddaniePojazdu.hpp"
#include "Pracownik.hpp"
#include "Rejestracja.hpp"
#include "Uzytkownik.hpp"
#include "Wypozyczenie.hpp"
#include "ZarzadzanieBazaKlientow.hpp"
#include "ZarzadzanieBazaPracownikow.hpp"
#include "ZarzadzanieBazaWypozyczen.hpp"
#include "Pojazd.hpp"
#include "Data.hpp"

int main() {
	int option;
	while (true) {
		cout << "----WYPOZYCZALNIA SAMOCHODOW-----\n\n";
		cout << "Wybierz co chcesz zrobiæ\n";
		cout << "1. Zalogowac siê. " << endl;
		cout << "2. Zarejestrowac sie." << endl;
		cout << "2.Obejrzec pojazdy z naszej oferty";
		cout << "3. Wyjscie z programu." << endl;
		cout"\n\nDodatkowe akcje mozliwe sa dopiero po zalogowaniu.\n\n";

		cout << "WYBOR :";
		cin >> option;
		swich(option) {
			case 1:
				Logowanie logowanie;
				Uzytkownik uzytkownik = logowanie.zaloguj();
			case 2:
				Rejestracja
		}
		cout << "--------------------------------------------------------\n";


	}
}