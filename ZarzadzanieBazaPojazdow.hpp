#ifndef ZBP_HPP
#define ZBP_HPP

#include "Pojazd.hpp"
class ZarzadzanieBazaPojazdow {
public:
	void dodajPojazd();
	void dodajPojazd(Pojazd * pojazd);
	void usunPojazd();
	//tu juz mamy plik znaleziony
	void edytujBazePojazdow();
	Pojazd *znajdzPojazd(string rejestracja);
	void przegladajBaz
		ePojazdow();
	void przegladajBazePojazdow(Data P, Data K);
	void wypiszDanyPojazd(Pojazd * pojazd);
	
}
#endif
