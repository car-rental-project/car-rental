#ifndef DATA
#define DATA

#include<iostream>
#include<string>

class Data {
private:
	unsigned int dzien;
	unsigned int miesiac;
	unsigned int rok;
public:
	Data() : dzien(0), miesiac(0), rok(0) {};
	Data(unsigned int D, unsigned int M, unsigned int R) : dzien(D), miesiac(M), rok(R) {};
	Data(std::string pesel);

	void wyswietlDate();
};

#endif // !DATA
