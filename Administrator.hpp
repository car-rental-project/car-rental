#ifndef ADMINISTRATOR_HPP
#define ADMINISTRATOR_HPP
#include "Pracownik.hpp"
#include "MenuAdministratora.hpp"
#include "ZarzadzanieBazaKlientow.hpp"
#include "ZarzadzanieBazaPojazdow.hpp"
#include "ZarzadzanieBazaPracownikow.hpp"



class Administrator : public Pracownik  {

	MenuAdministratora menuAdministratora;
	ZarzadzanieBazaKlientow zarzadzanieBazaKlientow;
	ZarzadzanieBazaPojazdow zarzadzanieBazaPojazdow;
	ZarzadzanieBazaPracownikow zarzadzanieBazaPracownikow;

	friend class MenuAdministratora;

public:
	Administrator() { Pracownik(); }

};


#endif // !ADMINISTRATOR_GPP
