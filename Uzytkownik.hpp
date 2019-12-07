#ifndef UZYTKOWNIK
#define UZYTKOWNIK

#include "DaneKlienta.hpp"
#include "Data.hpp"

class Uzytkownik {
private:
	DaneKlienta *daneKlienta = new DaneKlienta;
	Data *data = new Data;

public:
	Uzytkownik() = default;
	DaneKlienta* getDaneKlienta() { return daneKlienta; }

};



