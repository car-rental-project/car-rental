#include "DaneKlienta.hpp"

string DaneKlienta::getPesel()
	{
		return pesel;
	}
string DaneKlienta::getNazwisko()
	{
		return nazwisko;
	}
string DaneKlienta::getImie()
	{
		return imie;
	}
void DaneKlienta::setPesel(string p)
	{
		pesel = p;
	}
void DaneKlienta::setNazwisko(string n)
	{
		nazwisko = n;
	}
void DaneKlienta::setImie(string i)
	{
		imie = i;
	}

void DaneKlienta::edytujDane()
{
	string pom;
	system("CLS");

	wyswietlDane();

	cout << "(wprowadz 'x' jezeli nie chcesz wprowadzic zmian)" << endl;

	cout << "Nowe imie: " << endl;
	cin >> pom;
	if (pom != "x")
	{
		imie = pom;
	}
	cout << "Nowe nazwisko: " << endl;
	cin >> pom;
	if (pom != "x")
	{
		nazwisko = pom;
	}
	cout << "Nowy PESEL: " << endl;
	cin >> pom;
	if (pom != "x")
	{
		pesel = pom;
	}
	cout << endl;
	wyswietlDane();
	cout << "Czy aktualne dane sa poprawne (Y/N)?" << endl;
	cin >> pom;
	if (pom == "N")
	{
		edytujDane();
	}


}
void DaneKlienta::wyswietlDane()
{
	cout << "Imie: " << imie << endl;
	cout << "Nazwisko:" << nazwisko << endl;
	cout << "Nr PESEL: " << pesel << endl << endl;
}
