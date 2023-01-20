#pragma once
#include <iostream>

using namespace std;

// Aplicația va conține cel puțin o clasă abstractă (poate fi și interfață) ce conține cel puțin o practică virtuală pură.
class sponsorizare
{
	virtual void suma() = 0;
};

// Metoda pură va fi supradefinită într-o clasă derivată
class brand : public sponsorizare
{
private:
	char* nume;
	int suma;
public:
	brand()
	{
		this->nume = new char[strlen("Nedefinit") + 1];
		strcpy(this->nume, "Nedefinit");
		this->suma = 0;
	}

	brand(const char* nume, int suma)
	{
		if (nume != nullptr && strlen(nume) != 0)
		{
			this->nume = new char[strlen(nume) + 1];
			strcpy(this->nume, nume);
		}
		else
		{
			this->nume = nullptr;
		}
		if (suma > 0)
		{
			this->suma = suma;
		}
		else
		{
			this->suma = 0;
		}
	}

	brand(const brand& b)
	{
		if (b.nume != nullptr && strlen(b.nume) != 0)
		{
			this->nume = new char[strlen(b.nume) + 1];
			strcpy(this->nume, b.nume);
		}
		else
		{
			this->nume = nullptr;
		}
		this->suma = b.suma;
	}

	~brand()
	{
		if (this->nume != nullptr)
		{
			delete[] this->nume;
			this->nume = nullptr;
		}
	}

	brand& operator=(const brand& b)
	{
		// evita auto-asignarea
		if (this != &b)
		{
			if (this->nume != nullptr)
			{
				delete[] this->nume;
			}
			if (b.nume != nullptr && strlen(b.nume) != 0)
			{
				this->nume = new char[strlen(b.nume) + 1];
				strcpy(this->nume, b.nume);
			}
			else
			{
				this->nume = nullptr;
			}
			this->suma = b.suma;
			return *this; // evita apelul in cascada
		}
	}

	char* getNume()
	{
		return this->nume;
	}

	void setNume(const char* nume)
	{
		if (nume != nullptr && strlen(nume) != 0)
		{
			if (this->nume != nullptr)
			{
				delete[] this->nume;
			}
			this->nume = new char[strlen(nume) + 1];
			strcpy(this->nume, nume);
		}
	}

	int getSuma()
	{
		return this->suma;
	}

	void setSuma(int suma)
	{
		if (suma > 0)
		{
			this->suma = suma;
		}
		else
		{
			this->suma = 0;
		}
	}

	friend ostream& operator<<(ostream& out, brand& b)
	{
		out << "Nume: " << b.nume << endl;
		out << "Suma: " << b.suma << endl;
		return out;
	}

	friend istream& operator>>(istream& in, brand& b)
	{
		cout << "Nume: ";
		char buffer[50];
		in >> buffer;
		if (b.nume != nullptr)
		{
			delete[] b.nume;
		}
		b.nume = new char[strlen(buffer) + 1];
		strcpy(b.nume, buffer);
		cout << "Suma: ";
		in >> b.suma;
		return in;
	}

	// obliga implementarea metodei pură din clasa de bază
	// apeleaza metoda din clasa de bază
	virtual void suma()
	{
		cout << "Suma sponsorizata este: " << this->suma << endl;
	}

};
	
