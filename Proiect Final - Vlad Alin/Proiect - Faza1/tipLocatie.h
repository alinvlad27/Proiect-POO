#pragma once
#include <iostream>
#include "Locatie.h"

using namespace std;

//Cel puțin o nouă clasă va fi creată prin derivarea unei clase existente
class tipLocatieInchis : public Locatie
{
private:
	int pretInchiriere;
public:
	tipLocatieInchis() :Locatie()
	{
		this->pretInchiriere = 0;
	}

	tipLocatieInchis(const char* adresa, int nrMaximDeLocuri, int nrLocuriOcupate, int pretInchiriere) :Locatie(adresa, nrMaximDeLocuri, nrLocuriOcupate)
	{
		if (pretInchiriere > 0)
		{
			this->pretInchiriere = pretInchiriere;
		}
		else
		{
			this->pretInchiriere = 0;
		}
	}

	tipLocatieInchis(const tipLocatieInchis& tli) :Locatie(tli)
	{
		this->pretInchiriere = tli.pretInchiriere;
	}

	int getPretInchiriere()
	{
		return this->pretInchiriere;
	}

	void setPretInchiriere(int pretInchiriere)
	{
		if (pretInchiriere > 0)
		{
			this->pretInchiriere = pretInchiriere;
		}
		else
		{
			this->pretInchiriere = 0;
		}
	}

	void afisareMesaj()
	{
		cout << "Adresa locatiei " << this->getAdresa() << " are pretul de inchiriere de " << this->pretInchiriere << " lei" << endl;
	}

	friend ostream& operator<<(ostream& out, tipLocatieInchis& tli)
	{
		out << (Locatie&)tli;
		out << "Pret inchiriere: " << tli.pretInchiriere << endl;
		return out;
	}

	friend istream& operator>>(istream& in, tipLocatieInchis& tli)
	{
		in >> (Locatie&)tli;
		cout << "Pret inchiriere: ";
		in >> tli.pretInchiriere;
		return in;
	}

	virtual int calculPretInchiriere(Locatie& l)
	{
		if (l.getNrLocuriOcupate() > 50 && l.getNrLocuriOcupate() < 100)
		{
			return l.getNrLocuriOcupate() * this->pretInchiriere * 0.9;
		}
		else if (l.getNrLocuriOcupate() > 100)
		{
			return l.getNrLocuriOcupate() * this->pretInchiriere * 0.8;
		}
		else
		{
			return l.getNrLocuriOcupate() * this->pretInchiriere;
		}
	}

	
};
	
	
