
// PROIECT FAZA 1 - VLAD ALIN PETRISOR, GRUPA 1061, SERIA E

#include <iostream>
#include <string>
#include "Bilet.h"
#include "Eveniment.h"
#include "Locatie.h"
#include "BiletReducere.h"
#include <fstream>
#include "Private.h"
#include "tipLocatie.h"

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

	// apel operator cast
	Bilet b7(10, 20, 30, "VIP", 400);
	cout << "Returnarea numarului locului dupa cast : " << (int)b7 << endl;

	Eveniment e1(4, 5, 2022, 5, "PSG vs Barcelona");
	Locatie l1;

	//apel metoda virtuala pt bilet
	BiletReducere B10(6, 7, 8, "VIP", 100, 10);
	cout << "Pretul biletului dupa reducere : " << B10.calculReducere(B10) << endl;
	
	//apel metoda virtuala pt eveniment<
	privateEvent e2(2, 5, 2022, 5, "PSG vs Real MADRID", 20, "Shakira", 3);
	cout << "Ora la care se termina evenimentul : " << e2.oraFinalizariiEvent(e2) << endl;

	//apel metoda virtuala pt locatie
	tipLocatieInchis l2("Sector 3", 200, 60, 1000);
	cout << "Pretul inchirierii locatiei : " << l2.calculPretInchiriere(l2) << endl;
	

	
	/*Programul poate primi ca parametru în linia de comandă modalitate de funcționare :
	dacă utilizează un meniu în consolă sau prelucrează un fișier text cu toate datele de intrare
	(exemplu: dacă aplicația se numește opp.exe, atunci poate fi lansată în execuție în felul următor: opp.exe date.txt,
	situație în care va prelucra datele din fișierul primit ca parametru)*/
	//int argc;
	//const char* argv[100];
	//argc = 2;
	//argv[0] = "source.exe";
	//argv[1] = "date.txt";
	//if (argc == 2)
	//{
	//	cout << "Fisierul de intrare este : " << argv[1] << endl;
	//}
	//else
	//{
	//	cout << "Fisierul de intrare nu a fost introdus" << endl;
	//}

	// Aplicația poate procesa data dintr-un fișier text și va urma la consolă conform celor mai sus menționate
	Locatie l5;
	ifstream fisInput("locatie.txt");
	if (!fisInput) // daca nu exista
	{
		cout << "Fisierul nu a fost gasit" << endl;
	}
	else
	{
		cout << "Fisierul a fost gasit" << endl;
	}

	// Aplicația va utiliza fișierele binare pentru a salva biletele emise până în prezent; la repornirea aplicației datele vor fi restaurate
	// creeaza fisierul bilete.bin de tip binar
	ofstream file("bilete.bin", ios::binary);
	
	
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
		cout << "9. Pretul biletului dupa reducere" << endl;
		cout << "10. Ora la care se termina evenimentul" << endl;
		cout << "11. Pretul inchirierii locatiei" << endl;
		cout << "12. Scriere in fisier binar" << endl;
		cout << "13. Citire din fisier text" << endl;
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
		case 9: 
			cout << B10.calculReducere(B10);
			cout << endl;
			break;
		case 10:
			cout << e2.oraFinalizariiEvent(e2);
			cout << endl;
			break;
		case 11:
			cout << l2.calculPretInchiriere(l2);
			cout << endl;
			break;
		case 12:
			// daca fisierul binar s a deschis cu succes se scrie in el obiectele de tip bilet
			if (file.is_open())
			{
				file.write((char*)&b1, sizeof(Bilet));
				file.write((char*)&b2, sizeof(Bilet));
				file.write((char*)&b4, sizeof(Bilet));
				file.write((char*)&b5, sizeof(Bilet));
				file.write((char*)&b6, sizeof(Bilet));
				file.write((char*)&b7, sizeof(Bilet));
				file.close();
				cout << "Fisierul a fost deschis" << endl;
			}
			else
			{
				cout << "Fisierul nu a fost deschis" << endl;
	
			}
			break;
		case 13:
			// daca fisierul txt s a deschis cu succes se citeste din el obiectele de tip bilet
			if (fisInput.is_open())
			{
				cout << "Fisierul a fost deschis" << endl;
				fisInput >> l5; // primeste l5 datele din fisierul txt
				cout << l5;
				fisInput.close();
				
			}
			else
			{
				cout << "Fisierul nu a fost deschis" << endl;
			}
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
