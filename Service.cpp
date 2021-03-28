#include "Service.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/*Adaugare Masina Service*/
int Service::addMasinaService(Masina m) 
{
	if (strcmp(m.getStatus(), "ocupat") == 0) 
	{
		int k = 0;
		for (int i = 0; i < repo.dim(); i++)
			if (strcmp(getItemFromPos(i).getStatus(), "ocupat") == 0)
				k++;
		if (k >= parcare) 
		{
			numar++;
			return -2;
		}
	}
	int rezultat = repo.addElem(m);
	return rezultat;
}

/*Stergere Masina Service*/
int Service::delMasinaService(Masina m) 
{
	if (strcmp(m.getStatus(), "liber") == 0) 
	{
		return repo.delElem(m);
	}
	else
		return -2;

}

/*Modificare Masina Service*/
int Service::updateMasinaService(const Masina& m, Masina nouaM) 
{
	if (strcmp(nouaM.getStatus(), "ocupat") == 0) 
	{
		int k = 0;
		for (int i = 0; i < repo.dim(); i++)
			if (strcmp(getItemFromPos(i).getStatus(), "ocupat") == 0)
				k++;
		if (k >= parcare) 
		{
			numar++;
			return -2;
		}
	}
	repo.updateElem(m, nouaM);
	return 0;
}

/*Afisarea tuturor masinilor Service*/
list<Masina> Service::getAll() 
{
	return repo.getAll();
}

/*Returneaza numarul de masini*/
int Service::dim() 
{
	return repo.dim();
}

/*Returneaza masina cautata*/
bool Service::findElemService(const Masina& m) 
{
	return repo.findElem(m);
}

/*Returneaza masina de pe pozitia i*/
Masina Service::getItemFromPos(int i) 
{
	return repo.getItemFromPos(i);
}

/*In aceasta functie setam numarul de locuri al parcari*/
void Service::seteazaNumarulDeLocuri(int nr)
{
	parcare = nr;
}

/*In aceasta functie introducem masina in parcare daca ea este 'libera' si parcarea nu este plina*/
int Service::intrareParcare(Masina m) 
{
	if (m.getStatus())
		if (strcmp(m.getStatus(), "ocupat") == 0) 
			return -1;
		else 
		{
			int k = 0;
			for (int i = 0; i < repo.dim(); i++)
				if (strcmp(getItemFromPos(i).getStatus(), "ocupat") == 0)
					k++;
			if (k >= parcare) 
			{
				numar++;
				return -2;
			}
		}
	Masina nouaM(m.getNumePosesor(), m.getNrInmatriculare(), "ocupat");
	repo.updateElem(m, nouaM);
	return 0;
}

/*In aceasta functie scoatem masina din parcare*/
int Service::iesireParcare(Masina m) 
{
	if (strcmp(m.getStatus(), "ocupat") == 0) 
	{
		Masina nouaM(m.getNumePosesor(), m.getNrInmatriculare(), "liber");
		repo.updateElem(m, nouaM);
		numar = 0;
		return 0;
	}
	else
		return -1;
}

/*Destructorul*/
Service::~Service() 
{
}