#pragma once
#include "Masina.h"
#include <iostream>
#include <list>

using namespace std;

class Repository
{
protected:
	list<Masina> elem;
public:
	Repository();
	int addElem(Masina);
	void updateElem(const Masina&, const char*, const char*, const char*);
	int findElem(Masina);
	int delElem(const Masina&);
	list<Masina> getAll();
	int size();
	bool findMasina(const Masina&);
	Masina getItemFromPos(int);
	~Repository();
};


