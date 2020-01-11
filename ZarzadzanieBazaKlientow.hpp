#ifndef ZARZADZANIEBAZAKLIENTOW
#define ZARZADZANIEBAZAKLIENTOW


class ZarzadzanieBazaKlientow {
public:
	void przegladajBazeKlientow();
	void edytujBazeKlientow();
	void edytujBazeKlientow(std::string login);
	void dodajKlienta();
	void usunKlienta();
	void przegladajWypozyczenia(std::string login);
};

bool removeLine(std::string fileDirectory, std::string fileName, std::string toDelete);
bool exists(const std::string& name);

#endif // !ZARZADZANIEBAZAKLIENTOW
