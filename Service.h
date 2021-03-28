#pragma once
#include "Masina.h"
#include "RepositoryFile.h"
#include "RepositoryTemplate.h"

class Service {
private:
	int parcare;
	RepositoryTemplate<Masina>& repo;
public:
	int numar;
	Service(RepositoryTemplate<Masina>& r) :repo(r) {numar = 0; repo = r;  };
	int addMasinaService(Masina);
	int delMasinaService(Masina);
	int updateMasinaService(const Masina&, Masina);
	int dim();
	Masina getItemFromPos(int);
	list<Masina> getAll();
	bool findElemService(const Masina&);
	void seteazaNumarulDeLocuri(int);
	int intrareParcare(Masina);
	int iesireParcare(Masina);
	~Service();
};