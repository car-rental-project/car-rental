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
	std::string rejestracja;
	//Uzytkownik* uzytkownik;
public:
	bool wypozyczAuto(Pojazd *pojazd, Uzytkownik* u,Data datak, Data dataP);
	bool wypozyczAuto(std::string login, Data datak, Data dataP,std::string id);
	void zwroc(std::string id,std::string login);
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

