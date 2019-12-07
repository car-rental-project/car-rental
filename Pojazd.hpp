#ifndef POJAZD_HPP
#define POJAZD_HPP

class Pojazd {
private:
	string rejestracja;
	string marka;
	string model;
	unsigned int pojemnoscSilnika;
	unsigned int pojemnoscBagaznika;
	unsigned int liczbaDrzwi;
	float moc;
	char klasa;
	long unsigned int przebieg;
public:
	string getRejestracja() {
		return rejestracja;
	}
	string getMarka() {
		return marka;
	}
	string getModel() {
		return model;
	}
	int getPojemnoscSilnika() {
		return pojemnoscSilnika;
	}
	int getLiczbaDrzwi() {
		return liczbaDrzwi;
	}
	float getMoc() {
		return moc;
	}
	char getKlasa() {
		return klasa;
	}
	long unsigned int getPrzebieg() {
		return przebieg;
	}
	void setRejestracja() {
		this.rejestracja = rejestracja;
	}
	void setMarka() {
		this.marka = marka;
	}
	void setModel() {
		this.model = model;
	}
	void setPojemnoscSilnika() {
		this.pojemnoscSilnika = pojemnnoscSilnika;
	}
	void setLiczbaDrzwi() {
		this.liczbaDrzwi = liczbaDrzwi;
	}
	void setMoc() {
		this.moc = moc;
	}
	void setKlasa() {
		this.klasa = klasa;
	}
	void setPrzebieg() {
		this.przebieg = przebieg;
	}
	void wyswietlDane();
#endif