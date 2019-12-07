#include "Uzytkownik.hpp"

void Uzytkownik::wyswietlWszystko()
{
	this->daneKlienta.wyswietlDane();
	cout << kwota << endl;
	int i = 0;
	cout << "ID Wypozyczen:" << endl;
	while (hisWypozyczen[i] != 0)
	{
		cout << hisWypozyczen[i] << endl;
		i++;
	}
}
void Uzytkownik::setDaneKlienta(string i, string n, string p)
{
	daneKlienta.setImie(i);
	daneKlienta.setNazwisko(n);
	daneKlienta.setPesel(p);
}
int Uzytkownik::getKwota()
{
	return kwota;
}
int *Uzytkownik::getHisWypozyczen()
{
	return hisWypozyczen;
}
void Uzytkownik::setKwota(int k)
{
	kwota = k;
}
void Uzytkownik::setHisWypozyczen(int *historia)
{
	hisWypozyczen = historia;
}