#ifndef PRACOWNIK
#define PRACOWNIK
#include "Użytkownik.hpp"

class Pracownik : public Uzytkownik {
private:
	NaliczanieOplat *naliczanieOplat;
	OddaniePojazdu *oddaniePojazdu;
public:
	Pracownik() { Uzytkownik(); }
};


#endif