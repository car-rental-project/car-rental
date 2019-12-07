#ifndef LOGOWANIE
#define LOGOWANIE
#include <iostream>
#include <string>
#include <fstream>
#include "Uzytkownik.hpp"

using namespace std;

class Logowanie
{
private:
	string login;
	string haslo;
public:
	Logowanie() = default;
	Logowanie(string l, string h) :login(l), haslo(h) {};
	string getLogin();
	string getHaslo();
	void setLogin(string l);
	void setHaslo(string h);
	Uzytkownik zaloguj();
};


#endif