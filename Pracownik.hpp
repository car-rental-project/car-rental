#ifndef PRACOWNIK
#define PRACOWNIK
#include "U¿ytkownik.hpp"

class Pracownik : public Uzytkownik {
private:
	NaliczanieOplat *naliczanieOplat;
	OddaniePojazdu *oddaniePojazdu;
public:
	Pracownik() { Uzytkownik(); }
};


#endif