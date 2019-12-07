#ifndef WYPOZYCZENIE_HPP
#define WYPOZYCZENIE_HPP

#include "Pojazd.hpp"
#include "Data.hpp"
#include "Uzytkownik.hpp"
class Wypozyczenie {
private:
	Data dataPoczatkowa;
	Data dataKoncowa;
	bool aktualne;
	Pojazd* pojazd;
	Uzytkownik* uzytkownik;
public:
	bool wypozyczAuto(Pojazd *pojazd, Uzytkownik* u,Data datak, Data dataP);
	void zwroc();
	void wyswietlWarunki();
	Data getDataKoncowa();
	Data getDataPoczatkowa();
	void setDataKoncowa(Data);
	void setDataPoczatkowa(Data);
	bool getAktualne();
	void setAktualne(bool);
	Pojazd* getPojazd();
	void setPojazd(Pojazd *pojazd);
	Uzytkownik* getUzytkownik();
	void setUzytkownik(Uzytkownik* u);
};
#endif

