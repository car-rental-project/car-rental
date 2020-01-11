#ifndef UZYTKOWNIK
#define UZYTKOWNIK

#include <vector>
#include "DaneKlienta.hpp"
#include "MenuUzytkownika.hpp"
#include "DostepDoPojazdow.hpp"

class Uzytkownik{
private:
	DaneKlienta daneKlienta;
	DostepDoPojazdow dostepDoPojazdow;
	MenuUzytkownika menuUzytkownika;

	friend class MenuUzytkownika;
	
	int kwota;
	int *hisWypozyczen = nullptr;
	std::vector <Wypozyczenie> wypozyczenie;

public:
	Uzytkownik() = default;
	Uzytkownik(string i, string n, string p, int k, int *historia) :daneKlienta(DaneKlienta(i, n, p)), kwota(k), hisWypozyczen(historia){};
	DaneKlienta getDaneKlienta() { return daneKlienta; };
	void setDaneKlienta(string i, string n, string p);
	int getKwota();
	int *getHisWypozyczen();
	void setKwota(int k);
	void setHisWypozyczen(int *historia);
	void wyswietlWszystko();

};
#endif