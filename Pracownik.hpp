#ifndef PRACOWNIK
#define PRACOWNIK
#include "Uzytkownik.hpp"
#include "NaliczanieOplat.hpp"
#include "OddaniePojazdu.hpp"
#include "MenuPracownika.hpp"

class Pracownik : public Uzytkownik {
private:
	NaliczanieOplat naliczanieOplat;
	OddaniePojazdu oddaniePojazdu;
	MenuPracownika menuPracownika;

	friend class MenuPracownika;

public:
	Pracownik() { Uzytkownik(); }
};


#endif