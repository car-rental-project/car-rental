#include "Data.hpp"

Data::Data(std::string pesel) {
	std::string tmpString;
	std::string tmpRok;
	std::string tmpMiesiac;
	std::string tmpDzien;
	//wyciagniecie roku z peselu
	tmpRok = pesel;
	tmpRok.erase(2, 9);
	rok = std::atoi(tmpRok.c_str());
	//wyciagniecie miesiaca z peselu
	tmpMiesiac = pesel;
	tmpMiesiac.erase(4);
	
	tmpMiesiac.erase(0,2);
	
	miesiac = std::atoi(tmpMiesiac.c_str());
	//wyciagniecie dnia z peselu
	tmpDzien = pesel;
	tmpDzien.erase(6, 9);
	tmpDzien.erase(0, 4);
	dzien = atoi(tmpDzien.c_str());
}

void Data::wyswietlDate() {
	std::cout << "dzien: " << dzien << std::endl;
	std::cout << "miesiac: " << miesiac << std::endl;
	if(rok < 10){
		std::cout << "rok: " << "0" << rok << std::endl;
	}
	else
	std::cout << "rok: " << rok << std::endl;
}