#include "DaneKlienta.hpp"
#include "ZarzadzanieBazaKlientow.hpp"

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
	cout << "Nr PESEL: " << pesel << endl;
}

void DaneKlienta::edytujDaneWBazie() {
	std::string tmp;
	//std::string login;
	std::string haslo;
	std::string imie;
	std::string nazwisko;
	std::string	pesel;
	std::string kwota;
	std::string log;

	std::string loginy = ".\\BazaDanych\\Klienci\\LOGINY";
	std::string directory = ".\\BazaDanych\\Klienci\\";
	std::string newDirectory = ".\\BazaDanych\\Klienci\\";

	std::fstream file;		//plik uzytkownika
	std::fstream temp;
	std::fstream check;
	std::fstream bazaLoginow;
	bool ok = true;

	//bazaLoginow.open(loginy.c_str(), std::ios::out | std::ios::in);
	//if (bazaLoginow.good()) {
	temp.open(".\\BazaDanych\\Klienci\\temp", std::ios::out);
	if (temp.good()) {
		//std::cout << "Podaj login klienta do edycji: ";
		//std::cin >> login;

		directory.insert(directory.size(), login);
		file.open(directory, std::ios::out | std::ios::in);
		if (file.good()) {
			std::cout << "Jesli nie chcesz zmienic danej wpisz \"x\" ";
			while (ok) {
				std::cout << "Aktualny login: " << login << std::endl;
				std::cin >> log;
				if (log == "x") {
					ok = false;
					newDirectory.insert(newDirectory.size(), login);
					break;
				}
				newDirectory.insert(newDirectory.size(), log);
				if (exists(newDirectory)) {
					std::cout << "Login zajety sprobuj innego" << std::endl;
					newDirectory.erase(newDirectory.size() - log.size());
				}
				else ok = false;
			}
			///tu zamienilem dwie ponizsze linie ze sb
	//		bazaLoginow.close();
			removeLine(".\\BazaDanych\\Klienci\\", "LOGINY", login);

			bazaLoginow.open(loginy.c_str(), std::ios::out | std::ios::app);
			if (bazaLoginow.good()) {
				bazaLoginow << /*std::endl <<*/ log;
				//tu doda³em zamkniecie pliku
				bazaLoginow.close();
				file.seekg(0);
				//ustalenie nowego hasla
				std::cout << "Aktualne haslo: ";
				getline(file, tmp);
				std::cout << tmp << std::endl;
				std::cin >> haslo;
				if (haslo != "x") {
					temp << haslo << std::endl;
				}
				else {
					temp << tmp << std::endl;
				}
				//ustalenie nowego imienia
				//std::cout << "Aktualne imie: ";
				getline(file, tmp);
				//std::cout << tmp << std::endl;
				/*std::cin >> imie;
				if (imie != "x") {
					temp << imie << std::endl;
				}
				else {*/
					temp << tmp << std::endl;
				//}
				//ustalenie nowego nazwiska
				//std::cout << "Aktualne nazwisko: ";
				getline(file, tmp);
				//std::cout << tmp << std::endl;
				//std::cin >> nazwisko;
				//if (nazwisko != "x") {
				//	temp << nazwisko << std::endl;
				//}
				//else {
					temp << tmp << std::endl;
				//}
				//ustalenie nowego peselu
				//std::cout << "Aktualny pesel: ";
				getline(file, tmp);
				//std::cout << tmp << std::endl;
				//std::cin >> pesel;
				//if (pesel != "x") {
				//	temp << pesel << std::endl;
				//}
				//else {
					temp << tmp << std::endl;
				//}
				//ustalenie nowej kwoty do zaplaty 
				//std::cout << "Aktualna kwota do zaplaty: ";
				getline(file, tmp);
				//std::cout << tmp << std::endl;
				//std::cin >> kwota;
				//if (kwota != "x") {
				//	temp << kwota << std::endl;
				//}
				//else {
					temp << tmp << std::endl;
				//}
			}
			else std::cout << "zamiana obecnie nie mozliwa" << std::endl;
		}
		else std::cout << "Blad otwarcia pliku" << std::endl;
		file.close();
	}
	else std::cout << "zamiana obecnie nie mozliwa" << std::endl;
	remove(directory.c_str());
	temp.close();
	if (log == "x") {
		rename(".\\BazaDanych\\Klienci\\temp", directory.c_str());
	}
	else {
		rename(".\\BazaDanych\\Klienci\\temp", newDirectory.c_str());
	}
	//	}
	//	else std::cout << "zamiana obecnie nie mozliwa" << std::endl;
		//poni¿sza linia dodana
	remove(".\\BazaDanych\\Klienci\\temp");


}
