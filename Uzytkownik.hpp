#ifndef UZYTKOWNIK
#define UZYTKOWNIK

#include "DaneKlienta.hpp"

class Uzytkownik{
private:
	DaneKlienta daneKlienta;
	int kwota;
	int *hisWypozyczen = nullptr;

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