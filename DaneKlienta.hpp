#ifndef DANEKLIENTA
#define DANEKLIENTA
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class DaneKlienta
{
	string imie;
	string nazwisko;
	string pesel;
public:
	DaneKlienta() = default;
	string getPesel();
	string getNazwisko();
	string getImie();
	void setPesel(string p);
	void setNazwisko(string n);
	void setImie(string i);
	void wyswietlDane();
	void edytujDane();
	//void pobierzDane(); ---> do zrobienia po ogarniêciu bazy
};


#endif

