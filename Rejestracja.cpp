#include "Rejestracja.hpp"

bool Rejestracja::zarejestruj()
{
	fstream plik;
	string imie, nazwisko, pesel, login, haslo;
	cout << "Login:";
	cin >> login;
	if (login == "X")
	{
		return true;
	}
	plik.open("BazaDanych/Uzytkownicy/" + login + ".txt", ios::in);
	if (plik.good() == true)
	{
		cout << "konto o danym loginie juz istnieje!!! (wprowadz X aby wyjsc)" << endl;
		plik.close();
		zarejestruj();
	}
	else
	{
		plik.close();
		plik.open("BazaDanych/Uzytkownicy/" + login + ".txt", ios::out);
		cout << "Haslo:";
		cin >> haslo;
		cout << "Imie:";
		cin >> imie;
		cout << "Nazwisko:";
		cin >> nazwisko;
		cout << "Nr PESEL:";
		cin >> pesel;
		plik << haslo << endl;
		plik << imie << endl;
		plik << nazwisko << endl;
		plik << pesel << endl;
		plik << "0" << endl;
		cout << "konto zostalo utworzone" << endl;
	}
	plik.close();
}