
// PROIECT FAZA 1 - VLAD ALIN PETRISOR, GRUPA 1061, SERIA E

#include <iostream>
#include "Bilet.h"
#include "Eveniment.h"
#include "Locatie.h"

using namespace std;

int main()
{
	Bilet b1;
	Bilet b2(4, 5, 4, "Peluza");
	Bilet b3(b2);
	b1 = b2;
	cout << "Returnarea id-ului constructorului implicit : " << b1.getId() << endl;
	cout << "Returnarea tipului locului constructorului cu parametrii : " << b2.getTipLoc() << endl;
	b2.setNrLoc(10);
	cout << "Returnarea numarului locului dupa modificare : " << b2.getNrLoc() << endl;
	b2.setipLoc("Tribuna");
	cout << "Returnarea tipului locului dupa modificare : " << b2.getTipLoc() << endl;
	b1.afisareMesaj();
	// apel metoda
	b2.verificareId(2);
	Bilet b4(5, 2, 45, "VIP");
	b4.prelucrareLoc();
	// apel <<
	cout << b4;
	// apel >>
	//cin >> b4;
	//cout << b4;
	
	// apel operator ==
	Bilet b5(3, 4, 5, "Tribuna 1");
	Bilet b6(3, 4, 5, "Tribuna 1");
	if (b5 == b6)
	{
		cout << "Biletele sunt egale" << endl;
	}
	else
	{
		cout << "Biletele nu sunt egale" << endl;
	}
	
	// apel operator /
	Bilet b7(10, 20, 30, "VIP");
	Bilet b8 = b7 / 2;
	cout << b8;

	Eveniment e1;
	Locatie l1;
}
