#ifndef WYPOZYCZENIE_HPP
#define WYPOZYCZENIE_HPP

#include "Pojazd.hpp"
#include "Data.hpp"
class Wypozyczenie{
private:
	Data dataPoczatkowa;
	Data dataKoncowa;
	bool aktualne;
	Pojazd* pojazd;
public:
	bool wypozyczAuto(Pojazd *pojazd);
	bool wypozyczMotocykl();
	void zwroc();
	void wyswietlWarunki();
};
#endif

