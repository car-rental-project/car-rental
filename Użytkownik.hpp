#ifndef U¯YTKOWNIK
#define U¯YTKOWNIK

#include "DaneKlienta.hpp"

class Uzytkownik {
private:
	DaneKlienta *daneKlienta = new DaneKlienta;
	
public:
	Uzytkownik() = default;
	DaneKlienta* getDaneKlienta() { return daneKlienta; }

};








#endif // !U¯YTKOWNIK
