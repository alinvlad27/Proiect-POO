
// PROIECT FAZA 1 - VLAD ALIN PETRISOR, GRUPA 1061, SERIA E

#include <iostream>
#include <string>
#include "Bilet.h"
#include "Eveniment.h"
#include "Locatie.h"

using namespace std;




int main()
{
	Bilet b1;
	Bilet b2(4, 5, 4, "Peluza", 100);
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
	Bilet b4(5, 2, 45, "VIP", 200);
	b4.prelucrareLoc();
	// apel <<
	cout << b4;
	// apel >>
	//cin >> b4;
	//cout << b4;

	// apel operator ==
	Bilet b5(3, 4, 5, "Tribuna 1", 300);
	Bilet b6(3, 4, 5, "Tribuna 1", 300);
	if (b5 == b6)
	{
		cout << "Biletele sunt egale" << endl;
	}
	else
	{
		cout << "Biletele nu sunt egale" << endl;
	}

	// apel operator /
	Bilet b7(10, 20, 30, "VIP", 400);
	Bilet b8 = b7 / 2;
	cout << b8;

	Eveniment e1;
	Locatie l1;

	
	/*Programul poate primi ca parametru în linia de comandă modalitate de funcționare :
	dacă utilizează un meniu în consolă sau prelucrează un fișier text cu toate datele de intrare
	(exemplu: dacă aplicația se numește opp.exe, atunci poate fi lansată în execuție în felul următor: opp.exe date.txt,
	situație în care va prelucra datele din fișierul primit ca parametru)*/
	int argc;
	const char* argv[100];
	argc = 2;
	argv[0] = "source.exe";
	argv[1] = "date.txt";
	if (argc == 2)
	{
		cout << "Fisierul de intrare este : " << argv[1] << endl;
	}
	else
	{
		cout << "Fisierul de intrare nu a fost introdus" << endl;
	}


	
	
	//Un meniu va fi implementat pentru a ajuta utilizatorul să navigheze printre diferitele funcționalități
	int optiune;
	do
	{
		cout << "Alegeti o optiune: " << endl;
		cout << "1. Afisare mesaj" << endl;
		cout << "2. Verificare id" << endl;
		cout << "3. Prelucrare loc" << endl;
		cout << "4. Afisare bilet" << endl;
		cout << "5. Citire bilet" << endl;
		cout << "6. Verificare egalitate bilete" << endl;
		cout << "7. Afisare eveniment" << endl;
		cout << "8. Afisare locatie" << endl;
		cout << "0. Iesire" << endl;
		cout << "Optiunea dumneavoastra: ";
		cin >> optiune;
		switch (optiune)
		{
		case 1:
			b1.afisareMesaj();
			cout << endl;
			break;
		case 2:
			b2.verificareId(2);
			cout << endl;
			break;
		case 3:
			b4.prelucrareLoc();
			cout << endl;
			break;
		case 4:
			cout << b4;
			cout << endl;
			break;
		case 5:
			cin >> b4;
			cout << b4;
			cout << endl;
			break;
		case 6:
			if (b5 == b6)
			{
				cout << "Biletele sunt egale" << endl;
			}
			else
			{
				cout << "Biletele nu sunt egale" << endl;
			}
			cout << endl;
			break;
		case 7:
			cout << e1;
			cout << endl;
			break;
		case 8:
			cout << l1;
			cout << endl;
			break;
		case 0:
			cout << "La revedere!" << endl;\
				cout << endl;
			break;
		default:
			cout << "Optiune invalida!" << endl;
			cout << endl;
			break;
		}
	} while (optiune != 0);
	
}
