#include "Logowanie.hpp"
string Logowanie::getLogin()
{
	return login;
}
string Logowanie::getHaslo()
{
	return haslo;
}
void Logowanie::setLogin(string l)
{
	login = l;
}
void Logowanie::setHaslo(string h)
{
	haslo = h;
}

Uzytkownik Logowanie::zaloguj()
{
	Uzytkownik pom;
	fstream plik;
	string loginp, haslop, haslou;
	string pomImie, pomNazwisko, pomPesel;
	int pomKwota, i = 0;
	int *pomHistoria = new int[i];
	cout << "Login:";
	cin >> login;
	loginp =login + ".txt";
	plik.open("BazaDanych/Uzytkownicy/"+loginp);
	if (plik.good() !=0)
	{
		powrot:
		cout << "Haslo:";
		cin >> haslou;
		plik >> haslop;
		if (haslop == haslou)
		{
			haslo = haslou;
			plik >> pomImie >> pomNazwisko >> pomPesel >> pomKwota;
			while (plik.eof() == 0)
			{
				plik >> pomHistoria[i];
				i++;
				int *pomHistoria = new int[i];
			}
			pom.setDaneKlienta(pomImie, pomNazwisko, pomPesel);
			pom.setKwota(pomKwota);
			pom.setHisWypozyczen(pomHistoria);
			return pom;
		}
		else if (haslou == "x")
		{
			haslo = haslou;
			return pom;
		}
		else
		{
			cout << "Nieprawidlowe haslo!!! (wprowadz x aby zrezygnowac)" << endl;
			goto powrot;
		}
	}
	else if (loginp == "z.txt")
	{
		login = "z";
		return pom;
	}
	else
	{
		cout << "Nieprawidlowy login!!! (wprowadz z aby zrezygnowac)" << endl;
		zaloguj();
	}
	plik.close();

	return pom;
}