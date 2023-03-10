#pragma once
#include <iostream>

using namespace std;

class Bilet
{
private:
	const int id;
	int nrLoc;
	int nrRand;
	char* tipLoc;
	int pret;
public:
	//constructor implicit
	Bilet() : id(0)
	{
		this->nrLoc = 0;
		this->nrRand = 0;
		this->tipLoc = new char[strlen("Peluza") + 1];
		strcpy(this->tipLoc, "Peluza");
		this->pret = 0;
		cout << "constructor implicit - clasa Bilet" << endl;
	}

	//constructor cu toti parametrii
	Bilet(int id, int nrLoc, int nrRand, const char* tipLoc, int pret) : id(id)
	{
		if (nrLoc >= 0 && tipLoc != nullptr && nrRand >= 0 && strlen(tipLoc) != 0)
		{
			this->nrLoc = nrLoc;
			this->nrRand = nrRand;
			this->tipLoc = new char[strlen(tipLoc) + 1];
			strcpy(this->tipLoc, tipLoc);
			this->pret = pret;
			cout << "constructor cu toti parametrii - clasa Bilet" << endl;

		}
		else
		{
			cout << "Date invalide!" << endl;
		}
	}

	//constructor de copiere	(regula celor 3)
	Bilet(const Bilet& b) : id(b.id)
	{
		this->nrLoc = b.nrLoc;
		this->nrRand = b.nrRand;
		this->pret = b.pret;
		if (b.tipLoc != nullptr)
		{
			this->tipLoc = new char[strlen(b.tipLoc) + 1];
			strcpy(this->tipLoc, b.tipLoc);
		}
		else
		{
			this->tipLoc = nullptr;
		}
		cout << "constructor de copiere - clasa Bilet" << endl;
	}

	// destructor	(regula celor 3)
	~Bilet()
	{
		if (this->tipLoc != NULL)
		{
			delete[] this->tipLoc;
			this->tipLoc = NULL;
		}
		cout << "destructor = clasa Bilet" << endl;
	}

	// operator =	(regula celor 3)
	Bilet& operator=(const Bilet& b)
	{
		//evita auto-asignarea
		if (this != &b)
		{
			if (this->tipLoc != NULL)
			{
				delete[] this->tipLoc;
				this->tipLoc = NULL;
			}
			cout << "operator = clasa Bilet " << endl;
			this->nrLoc = b.nrLoc;
			this->nrRand = b.nrRand;
			this->pret = b.pret;
			if (b.tipLoc != nullptr)
			{
				this->tipLoc = new char[strlen(b.tipLoc) + 1];
				strcpy(this->tipLoc, b.tipLoc);
			}
			else
			{
				this->tipLoc = nullptr;
			}
		}
		//evitarea apelului in cascada
		return*this;
	}

	// Metoda statica
	static void afisareMesaj()
	{
		cout << "Bine ati venit la meciul de Fotbal!" << endl;
	}

	// 2 Metode pentru diverse prelucrari
	// verifica daca id ul este valid
	void verificareId(int id)
	{
		if (this->id == id)
		{
			cout << "Biletul este valid!" << endl;
		}
		else
		{
			cout << "Biletul nu este valid!" << endl;
		}
	}

	// afiseaza tipul locului
	void prelucrareLoc()
	{
		if (this->tipLoc != nullptr)
		{
			if (strcmp(this->tipLoc, "VIP") == 0)
			{
				cout << "Felicitari! Locul este la VIP!" << endl;
			}
			else if (strcmp(this->tipLoc, "Peluza") == 0)
			{
				cout << "Felicitari! Locul este la Peluza!" << endl;
			}
			else if (strcmp(this->tipLoc, "Tribuna 1") == 0)
			{
				cout << "Felicitari! Locul este la Tribuna 1!" << endl;
			}
			else if (strcmp(this->tipLoc, "Tribuna 2") == 0)
			{
				cout << "Felicitari! Locul este la Tribuna 2" << endl;
			}
			else
			{
				cout << "Locul este normal!" << endl;
			}
		}
	}

	// getter & setteri
	int getId()
	{
		return this->id;
	}

	int getNrLoc()
	{
		return this->nrLoc;
	}

	int getNrRand()
	{
		return this->nrRand;
	}

	char* getTipLoc()
	{
		if (this->tipLoc != nullptr)
		{
			char* copie = new char[strlen(this->tipLoc) + 1];
			strcpy(copie, this->tipLoc);
			return copie;
		}
		else
		{
			return nullptr;
		}
	}

	int getPret()
	{
		return this->pret;
	}

	void setNrLoc(int nrLoc)
	{
		if (nrLoc >= 0)
		{
			this->nrLoc = nrLoc;
		}
		else
		{
			cout << "Numarul locului este invalid!" << endl;
		}
	}

	void setNrRand(int nrRand)
	{
		if (nrRand >= 0)
		{
			this->nrRand = nrRand;
		}
		else
		{
			cout << "Numarul randului este invalid!" << endl;
		}
	}

	void setipLoc(const char* tipLoc)
	{
		if (tipLoc != nullptr && strlen(tipLoc) != 0)
		{
			if (this->tipLoc != nullptr)
			{
				delete[] this->tipLoc;
				this->tipLoc = nullptr;
			}
			this->tipLoc = new char[strlen(tipLoc) + 1];
			strcpy(this->tipLoc, tipLoc);
		}
		else
		{
			cout << "Tipul locului este invalid!" << endl;
		}
	}

	void setPret(int pret)
	{
		if (pret >= 0)
		{
			this->pret = pret;
		}
		else
		{
			cout << "Pretul este invalid!" << endl;
		}
	}

	// supraincarcarea operatorului <<
	friend ostream& operator<<(ostream& out, Bilet& b)
	{
		out << "Biletul cu id - ul " << b.id << " are numarul locului " << b.nrLoc << " pe randul " << b.nrRand << " si are tipul locului " << b.tipLoc <<  
			" si pretul de " << b.pret << " lei." << endl;
		return out;
	}

	// supraincarcarea operatorului >>
	friend istream& operator>>(istream& in, Bilet& b)
	{
		cout << "Introduceti numarul locului: ";
		in >> b.nrLoc;
		cout << "Introduceti numarul randului: ";
		in >> b.nrRand;
		cout << "Introduceti tipul locului: ";
		char buffer[50];
		in >> buffer;
		if (b.tipLoc != nullptr)
		{
			delete[] b.tipLoc;
		}
		b.tipLoc = new char[strlen(buffer) + 1];
		strcpy(b.tipLoc, buffer);
		cout << "Introduceti pretul: ";
		in >> b.pret;
		return in;
	}

	// supraincarcarea operatorului ==
	// daca 2 bilete au acelasi nr de locuri si randuri si acelasi tip de loc, atunci sunt egale
	bool operator==(Bilet& b)
	{
		if (this->nrLoc == b.nrLoc && this->nrRand == b.nrRand && strcmp(this->tipLoc, b.tipLoc) == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	// supraincarcarea operatorului cast	
	// converteste la tipul int
	operator int()
	{
		return this->pret;
	}
	
	// metoda virtuala 
	virtual int calculReducere()
	{
		return pret;
	}
	

	
	
	

};