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


bool porownanieZakresu(Data p1, Data k1, Data p2, Data k2) {
	//zwraca true jesli przedzialy czasowe ze soba nie koliduja
	//1
	if (p1.getRok() < p2.getRok() ) {
		
		if(k1.getRok() < p2.getRok()) {
			return true;
		}
		else return false;

	}
	//2
	else if (p1.getRok() > p2.getRok()) {

		if (k2.getRok() < p1.getRok()) {
			return true;
		}

		else return false;
		
	}
	else if (p1.getRok() == p2.getRok()) {
		//1
		if (p1.getMiesiac() < p2.getMiesiac()) {

			if (k1.getMiesiac() < p2.getMiesiac()) {
				return true;
			}
			else return false;

		}
		//2
		else if (p1.getMiesiac() > p2.getMiesiac()) {

			if (k2.getMiesiac() < p1.getMiesiac()) {
				return true;
			}

			else return false;

		}
		else if (p1.getMiesiac() == p2.getMiesiac()) {
			//1
			if (p1.getDzien() < p2.getDzien()) {

				if (k1.getDzien() < p2.getDzien()) {
					return true;
				}
				else return false;

			}
			//2
			else if (p1.getDzien() > p2.getDzien()) {

				if (k2.getDzien() < p1.getDzien()) {
					return true;
				}

				else return false;

			}
		}
	}


}

std::string Data::getDataStr() {
	std::string tmp,ret;
	//dodanie dnia
	sprintf((char*)tmp.c_str(), "%d", this->dzien);
	std::string str = tmp.c_str();
	ret.insert(ret.size(), str);
	//dodanie miesiaca
	sprintf((char*)tmp.c_str(), "%d", this->miesiac);
	str = tmp.c_str();
	ret.insert(ret.size(), str);
	//dodanie roku
	sprintf((char*)tmp.c_str(), "%d", this->rok);
	str = tmp.c_str();
	ret.insert(ret.size(), str);
}