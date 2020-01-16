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
	Data(int d, int m, int r) : dzien(d), miesiac(m), rok(r) {};

	
	void wyswietlDate();
	int getDzien() { return dzien; }
	int getMiesiac() { return miesiac;}
	int getRok() { return rok; }
	std::string getDataStr();
};

bool porownanieZakresu(Data p1, Data k1, Data p2, Data k2);

#endif // !DATA
