#include "Logowanie.hpp"


int main()
{

	Logowanie test;
	Uzytkownik proba=test.zaloguj();
	if (test.getHaslo() == "x")
	{
		return 0;
	}
	if (test.getLogin() == "z")
	{
		return 0;
	}
	proba.wyswietlWszystko();

	system("PAUSE");
	return 0;
}