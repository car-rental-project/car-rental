#ifndef ZBP_HPP
#define ZBP_HPP

#include "Pojazd.hpp"
class ZarzadzanieBazaPojazdow {
public:
	void dodajPojazd(Pojazd * pojazd);
	void usunPojazd(string r);
	//tu juz mamy plik znaleziony
	void edytujBazePojazdow(string rejestracja,int opcja);
	Pojazd *znajdzPojazd(string rejestracja);
}
#endif
