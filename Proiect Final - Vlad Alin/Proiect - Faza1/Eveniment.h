#pragma once
#include <iostream>

using namespace std;

class Eveniment
{
	int zi;
	int luna;
	int an;
	int ora;
	char* denumire;
	static int nrMaximBilete;
public:
	// constructori
	Eveniment()
	{
		this->zi = 0;
		this->luna = 0;
		this->an = 0;
		this->ora = 0;
		this->denumire = new char[strlen("Argentina vs Franta") + 1];
		strcpy(this->denumire, "Argentina vs Franta");
		cout << "Argentina vs Franta - clasa evenimnet" << endl;
	}

	Eveniment(int zi, int luna, int an, int ora, const char* denumire)
	{
		this->zi = zi;
		this->luna = luna;
		this->an = an;
		this->ora = ora;
		if (denumire != nullptr && strlen(denumire) != 0)
		{
			this->denumire = new char[strlen(denumire) + 1];
			strcpy(this->denumire, denumire);
		}
		else
		{
			this->denumire = nullptr;
		}
	}

	Eveniment(const Eveniment& e)
	{
		this->zi = e.zi;
		this->luna = e.luna;
		this->an = e.an;
		this->ora = e.ora;
		if (e.denumire != nullptr && strlen(e.denumire) != 0)
		{
			this->denumire = new char[strlen(e.denumire) + 1];
			strcpy(this->denumire, e.denumire);
		}
		else
		{
			this->denumire = nullptr;
		}
	}

	// destructor
	~Eveniment()
	{
		if (this->denumire != nullptr)
		{
			delete[] this->denumire;
			this->denumire = nullptr;
		}
	}

	// operator =
	Eveniment& operator=(const Eveniment& e)
	{
		if (this != &e)
		{
			if (this->denumire != nullptr)
			{
				delete[] this->denumire;
				this->denumire = nullptr;
			}
			this->zi = e.zi;
			this->luna = e.luna;
			this->an = e.an;
			this->ora = e.ora;
			if (e.denumire != nullptr && strlen(e.denumire) != 0)
			{
				this->denumire = new char[strlen(e.denumire) + 1];
				strcpy(this->denumire, e.denumire);
			}
			else
			{
				this->denumire = nullptr;
			}
		}
		return *this;
	}

	// 2 Metode pentru diverse prelucrari
	void verificareData()
	{
		if (this->zi > 31 || this->zi < 1)
		{
			cout << "Ziua este invalida!" << endl;
		}
		else if (this->luna > 12 || this->luna < 1)
		{
			cout << "Luna este invalida!" << endl;
		}
		else if (this->an < 2022)
		{
			cout << "Anul este invalid!" << endl;
		}
		else if (this->ora > 24 || this->ora < 0)
		{
			cout << "Ora este invalida!" << endl;
		}
		else
		{
			cout << "Data este valida!" << endl;
		}
	}

	// getter & setteri
	int getZi()
	{
		return this->zi;
	}

	int getLuna()
	{
		return this->luna;
	}

	int getAn()
	{
		return this->an;
	}

	int getOra()
	{
		return this->ora;
	}

	static int getNrMaximBilete()
	{
		return nrMaximBilete;
	}

	char* getDenumire()
	{
		if (this->denumire != nullptr)
		{
			char* copie = new char[strlen(this->denumire) + 1];
			strcpy(copie, this->denumire);
			return copie;
		}
		else
		{
			return nullptr;
		}
	}

	void setZi(int zi)
	{
		if (zi > 0 && zi < 32)
		{
			this->zi = zi;
		}
		else
		{
			cout << "Ziua este invalida!" << endl;
		}
	}

	void setLuna(int luna)
	{
		if (luna > 0 && luna < 13)
		{
			this->luna = luna;
		}
		else
		{
			cout << "Luna este invalida!" << endl;
		}
	}

	void setAn(int an)
	{
		if (an >= 2022)
		{
			this->an = an;
		}
		else
		{
			cout << "Anul este invalid!" << endl;
		}
	}

	void setOra(int ora)
	{
		if (ora >= 0 && ora < 25)
		{
			this->ora = ora;
		}
		else
		{
			cout << "Ora este invalida!" << endl;
		}
	}

	void setDenumire(const char* denumire)
	{
		if (denumire != nullptr && strlen(denumire) != 0)
		{
			if (this->denumire != nullptr)
			{
				delete[] this->denumire;
				this->denumire = nullptr;
			}
			this->denumire = new char[strlen(denumire) + 1];
			strcpy(this->denumire, denumire);
		}
		else
		{
			cout << "Denumirea este invalida!" << endl;
		}
	}

	static void setNrMaximBilete(int nrMaximBilete)
	{
		if (nrMaximBilete > 0)
		{
			Eveniment::nrMaximBilete = nrMaximBilete;
		}
		else
		{
			cout << "Numarul maxim de bilete este invalid!" << endl;
		}
	}

	// supraincarcare operator <<
	friend ostream& operator<<(ostream& out, Eveniment& e)
	{
		out << "Denumire: " << e.denumire << endl;
		out << "Data: " << e.zi << "." << e.luna << "." << e.an << endl;
		out << "Ora: " << e.ora << endl;
		return out;
	}

	// supraincarcare operator >>
	friend istream& operator>>(istream& in, Eveniment& e)
	{
		cout << "Denumire: ";
		char buffer[50];
		in >> buffer;
		if (e.denumire != nullptr)
		{
			delete[] e.denumire;
			e.denumire = nullptr;
		}
		e.denumire = new char[strlen(buffer) + 1];
		strcpy(e.denumire, buffer);
		cout << "Zi: ";
		in >> e.zi;
		cout << "Luna: ";
		in >> e.luna;
		cout << "An: ";
		in >> e.an;
		cout << "Ora: ";
		in >> e.ora;
		return in;
	}

	// supraincarcare operator +
	// creste ora daca vreau sa intarzi evenimentul
	Eveniment operator+(int valoare)
	{
		Eveniment copie = *this;
		if (this->ora + valoare < 24)
		{
			copie.ora += valoare;
		}
		else
		{
			cout << "Nu se poate adauga valoarea la ora!";
		}
	}

	// supraincarcare operator !
	// valideaza atributele obiectului
	bool operator!()
	{
		if (this->zi > 0 && this->zi < 32 && this->luna > 0 && this->luna < 13 && this->an >= 2022 && this->ora > 0 && this->ora < 25)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	// O metoda virtuala care va fi definita de clasa derivata Private.h	
	// durata evenimentului in ore
	virtual int oraFinalizariiEvent()
	{
		return ora;
	}

};

int Eveniment::nrMaximBilete = 10000;