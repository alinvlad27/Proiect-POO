#pragma once
#include <iostream>
#include "eveniment.h"

using namespace std;

// //Cel puțin o nouă clasă va fi creată prin derivarea unei clase existente
class privateEvent : public Eveniment
{
private:
	int nrInvitati;
	char* numeInvitatSpecial;
	int durata;
public:
	privateEvent() :Eveniment()
	{
		this->nrInvitati = 0;
		this->numeInvitatSpecial = new char[strlen("Nedefinit") + 1];
		strcpy(this->numeInvitatSpecial, "Nedefinit");
		this->durata = 0;
	}
	privateEvent(int zi, int luna, int an, int ora, const char* denumire, int nrInvitati, const char* numeInvitatSpecial, int durata) :Eveniment(zi, luna, an, ora, denumire)
	{
		if (nrInvitati > 0)
		{
			this->nrInvitati = nrInvitati;
		}
		else
		{
			this->nrInvitati = 0;
		}
		if (numeInvitatSpecial != nullptr && strlen(numeInvitatSpecial) != 0)
		{
			this->numeInvitatSpecial = new char[strlen(numeInvitatSpecial) + 1];
			strcpy(this->numeInvitatSpecial, numeInvitatSpecial);
		}
		else
		{
			this->numeInvitatSpecial = nullptr;
		}
		if (durata > 0)
		{
			this->durata = durata;
		}
		else
		{
			this->durata = 0;
		}
	}

	privateEvent(const privateEvent& pe) :Eveniment(pe)
	{
		this->nrInvitati = pe.nrInvitati;
		if (pe.numeInvitatSpecial != nullptr && strlen(pe.numeInvitatSpecial) != 0)
		{
			this->numeInvitatSpecial = new char[strlen(pe.numeInvitatSpecial) + 1];
			strcpy(this->numeInvitatSpecial, pe.numeInvitatSpecial);
		}
		else
		{
			this->numeInvitatSpecial = nullptr;
		}
		this->durata = pe.durata;
	}

	~privateEvent()
	{
		if (this->numeInvitatSpecial != nullptr)
		{
			delete[] this->numeInvitatSpecial;
			this->numeInvitatSpecial = nullptr;
		}
	}

	//operator =
	privateEvent& operator=(const privateEvent& pe)
	{
		if (this != &pe)
		{
			Eveniment::operator=(pe);
			this->nrInvitati = pe.nrInvitati;
			if (this->numeInvitatSpecial != nullptr)
			{
				delete[] this->numeInvitatSpecial;
				this->numeInvitatSpecial = nullptr;
			}
			if (pe.numeInvitatSpecial != nullptr && strlen(pe.numeInvitatSpecial) != 0)
			{
				this->numeInvitatSpecial = new char[strlen(pe.numeInvitatSpecial) + 1];
				strcpy(this->numeInvitatSpecial, pe.numeInvitatSpecial);
			}
			else
			{
				this->numeInvitatSpecial = nullptr;
			}
			this->durata = pe.durata;
			return *this;
		}
	}

	// getteri si setteri
	int getNrInvitati()
	{
		return this->nrInvitati;
	}
	
	char* getNumeInvitatSpecial()
	{
		if (this->numeInvitatSpecial != nullptr && strlen(this->numeInvitatSpecial) != 0)
		{
			char* copie = new char[strlen(this->numeInvitatSpecial) + 1];
			strcpy(copie, this->numeInvitatSpecial);
			return copie;
		}
		else
		{
			return nullptr;
		}
	}

	int getDurata()
	{
		return this->durata;
	}
	
	void setNrInvitati(int nrInvitati)
	{
		if (nrInvitati > 0)
		{
			this->nrInvitati = nrInvitati;
		}
		else
		{
			this->nrInvitati = 0;
		}
	}

	void setNumeInvitatSpecial(char* numeInvitatSpecial)
	{
		if (this->numeInvitatSpecial != nullptr)
		{
			delete[] this->numeInvitatSpecial;
			this->numeInvitatSpecial = nullptr;
		}
		if (numeInvitatSpecial != nullptr && strlen(numeInvitatSpecial) != 0)
		{
			this->numeInvitatSpecial = new char[strlen(numeInvitatSpecial) + 1];
			strcpy(this->numeInvitatSpecial, numeInvitatSpecial);
		}
		else
		{
			this->numeInvitatSpecial = nullptr;
		}
	}

	void setDurata(int durata)
	{
		if (durata > 0)
		{
			this->durata = durata;
		}
		else
		{
			this->durata = 0;
		}
	}

	friend ostream& operator<<(ostream& out, privateEvent& pe)
	{
		out << (Eveniment&)pe;
		out << "Nr. invitati: " << pe.nrInvitati << endl;
		out << "Nume invitat special: " << pe.numeInvitatSpecial << endl;
		out << "Durata: " << pe.durata << endl;
		return out;
	}

	friend istream& operator>>(istream& in, privateEvent& pe)
	{
		in >> (Eveniment&)pe;
		cout << "Nr. invitati: ";
		in >> pe.nrInvitati;
		cout << "Nume invitat special: ";
		char buffer[50];
		in >> buffer;
		if (pe.numeInvitatSpecial != nullptr)
		{
			delete[] pe.numeInvitatSpecial;
			pe.numeInvitatSpecial = nullptr;
		}
		if (buffer != nullptr && strlen(buffer) != 0)
		{
			pe.numeInvitatSpecial = new char[strlen(buffer) + 1];
			strcpy(pe.numeInvitatSpecial, buffer);
		}
		else
		{
			pe.numeInvitatSpecial = nullptr;
		}
		cout << "Durata: ";
		in >> pe.durata;
		return in;
	}

	
	//  Metoda virtuala in clasa derivata
	virtual int oraFinalizariiEvent(Eveniment& e)
	{
		return this->durata + e.getOra();
	}
	

};