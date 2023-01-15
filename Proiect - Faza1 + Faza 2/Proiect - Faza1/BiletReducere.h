#pragma once
#include <iostream>
#include "Bilet.h"
#include "Eveniment.h"
#include "Locatie.h"

using namespace std;

//Cel puțin o nouă clasă va fi creată prin derivarea unei clase existente
class BiletReducere : public Bilet
{
private:
	int reducere;
public:
	BiletReducere() :Bilet()
	{
		this->reducere = 0;
	}

	BiletReducere(int id, int nrLoc, int nrRand, const char* tipLoc, int pret, int reducere) :Bilet(id, nrLoc, nrRand, tipLoc, pret)
	{
		if (reducere > 0)
		{
			this->reducere = reducere;
		}
		else
		{
			this->reducere = 0;
		}
	}

	BiletReducere(const BiletReducere& br) :Bilet(br)
	{
		this->reducere = br.reducere;
	}


	int getReducere()
	{
		return this->reducere;
	}

	void setReducere(int reducere)
	{
		if (reducere > 0)
		{
			this->reducere = reducere;
		}
		else
		{
			this->reducere = 0;
		}
	}

	void afisareMesaj()
	{
		cout << "Biletul cu id-ul " << this->getId() << " are reducere de " << this->reducere << " lei" << endl;
	}

	friend ostream& operator<<(ostream& out, BiletReducere& br)
	{
		out << "Id-ul biletului este : " << br.getId() << endl;
		out << "Numarul locului este : " << br.getNrLoc() << endl;
		out << "Pretul biletului este : " << br.getPret() << endl;
		out << "Tipul locului este : " << br.getTipLoc() << endl;
		out << "Reducerea este : " << br.reducere << endl;
		return out;
	}
		

	
};
	