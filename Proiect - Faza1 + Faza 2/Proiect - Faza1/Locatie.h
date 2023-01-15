#pragma once
#include <iostream>

using namespace std;

class Locatie
{
private:
	char* adresa;
	int nrMaximDeLocuri;
	int nrLocuriOcupate;
public:
	// constructori
	Locatie()
	{
		this->adresa = new char[strlen("Nedefinita") + 1];
		strcpy(this->adresa, "Nedefinita");
		this->nrMaximDeLocuri = 0;
		this->nrLocuriOcupate = 0;
		cout << "constr implicit - clasa Locatie" << endl;
	}

	Locatie(const char* adresa, int nrMaximDeLocuri, int nrLocuriOcupate)
	{
		if (adresa != nullptr && strlen(adresa) != 0)
		{
			this->adresa = new char[strlen(adresa) + 1];
			strcpy(this->adresa, adresa);
		}
		else
		{
			this->adresa = nullptr;
		}
		if (nrMaximDeLocuri > 0)
		{
			this->nrMaximDeLocuri = nrMaximDeLocuri;
		}
		else
		{
			this->nrMaximDeLocuri = 0;
		}
		if (nrLocuriOcupate > 0)
		{
			this->nrLocuriOcupate = nrLocuriOcupate;
		}
		else
		{
			this->nrLocuriOcupate = 0;
		}
	}

	Locatie(const Locatie& l)
	{
		if (l.adresa != nullptr && strlen(l.adresa) != 0)
		{
			this->adresa = new char[strlen(l.adresa) + 1];
			strcpy(this->adresa, l.adresa);
		}
		else
		{
			this->adresa = nullptr;
		}
		if (l.nrMaximDeLocuri > 0)
		{
			this->nrMaximDeLocuri = l.nrMaximDeLocuri;
		}
		else
		{
			this->nrMaximDeLocuri = 0;
		}
		if (l.nrLocuriOcupate > 0)
		{
			this->nrLocuriOcupate = l.nrLocuriOcupate;
		}
		else
		{
			this->nrLocuriOcupate = 0;
		}
	}

	// destructor
	~Locatie()
	{
		if (this->adresa != nullptr)
		{
			delete[] this->adresa;
			this->adresa = nullptr;
		}
	}

	// operator =
	Locatie& operator=(const Locatie& l)
	{
		if (this != &l)
		{
			if (this->adresa != nullptr)
			{
				delete[] this->adresa;
				this->adresa = nullptr;
			}
			if (l.adresa != nullptr && strlen(l.adresa) != 0)
			{
				this->adresa = new char[strlen(l.adresa) + 1];
				strcpy(this->adresa, l.adresa);
			}
			else
			{
				this->adresa = nullptr;
			}
			if (l.nrMaximDeLocuri > 0)
			{
				this->nrMaximDeLocuri = l.nrMaximDeLocuri;
			}
			else
			{
				this->nrMaximDeLocuri = 0;
			}
			if (l.nrLocuriOcupate > 0)
			{
				this->nrLocuriOcupate = l.nrLocuriOcupate;
			}
			else
			{
				this->nrLocuriOcupate = 0;
			}
		}
		return *this;
	}

	// 2 Metode pentru diverse prelucrari
	void verificareLocuri()
	{
		if (this->nrLocuriOcupate < this->nrMaximDeLocuri)
		{
			cout << "Locuri disponibile!" << endl;
		}
		else
		{
			cout << "Nu mai sunt locuri disponibile!" << endl;
		}
	}

	void adaugareLocuri(int nrLocuri)
	{
		if (this->nrLocuriOcupate + nrLocuri <= this->nrMaximDeLocuri)
		{
			this->nrLocuriOcupate += nrLocuri;
		}
		else
		{
			cout << "Nu se pot adauga locuri!" << endl;
		}
	}

	// getteri si setteri
	int getNrMaximDeLocuri()
	{
		return this->nrMaximDeLocuri;
	}

	int getNrLocuriOcupate()
	{
		return this->nrLocuriOcupate;
	}

	char* getAdresa()
	{
		if (this->adresa != nullptr && strlen(this->adresa) != 0)
		{
			char* copie = new char[strlen(this->adresa) + 1];
			strcpy(copie, this->adresa);
			return copie;
		}
		else
		{
			return nullptr;
		}
	}

	void setAdresa(const char* adresa)
	{
		if (this->adresa != nullptr)
		{
			delete[] this->adresa;
			this->adresa = nullptr;
		}
		if (adresa != nullptr && strlen(adresa) != 0)
		{
			this->adresa = new char[strlen(adresa) + 1];
			strcpy(this->adresa, adresa);
		}
		else
		{
			this->adresa = nullptr;
		}
	}

	void setNrMaximDeLocuri(int nrMaximDeLocuri)
	{
		if (nrMaximDeLocuri > 0)
		{
			this->nrMaximDeLocuri = nrMaximDeLocuri;
		}
		else
		{
			this->nrMaximDeLocuri = 0;
		}
	}

	void setNrLocuriOcupate(int nrLocuriOcupate)
	{
		if (nrLocuriOcupate > 0)
		{
			this->nrLocuriOcupate = nrLocuriOcupate;
		}
		else
		{
			this->nrLocuriOcupate = 0;
		}
	}

	// supraincaracre operator <<
	friend ostream& operator<<(ostream& out, Locatie& l)
	{
		out << "Adresa: " << l.adresa << endl;
		out << "Numar maxim de locuri: " << l.nrMaximDeLocuri << endl;
		out << "Numar locuri ocupate: " << l.nrLocuriOcupate << endl;
		return out;
	}

	// supraincarcare operator >>
	friend istream& operator>>(istream& in, Locatie& l)
	{
		cout << "Adresa: ";
		char buffer[50];
		in >> ws;
		in.getline(buffer, 50);
		if (l.adresa != nullptr)
		{
			delete[] l.adresa;
			l.adresa = nullptr;
		}
		if (buffer != nullptr && strlen(buffer) != 0)
		{
			l.adresa = new char[strlen(buffer) + 1];
			strcpy(l.adresa, buffer);
		}
		else
		{
			l.adresa = nullptr;
		}
		cout << "Numar maxim de locuri: ";
		in >> l.nrMaximDeLocuri;
		cout << "Numar locuri ocupate: ";
		in >> l.nrLocuriOcupate;
		return in;
	}

	// supraincarcare operator ++	
	Locatie& operator++()
	{
		if (this->nrLocuriOcupate < this->nrMaximDeLocuri)
		{
			this->nrLocuriOcupate++;
		}
		else
		{
			cout << "Nu se poate incrementa numarul de locuri ocupate!" << endl;
		}
		return *this;
	}

	// supraincarcare operator --
	Locatie& operator--()
	{
		if (this->nrLocuriOcupate > 0)
		{
			this->nrLocuriOcupate--;
		}
		else
		{
			cout << "Nu se poate decrementa numarul de locuri ocupate!" << endl;
		}
		return *this;
	}
	

};