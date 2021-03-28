#include <iostream>
#include <ostream>
#include <assert.h>
#include "Masina.h"
#include "Repository.h"
#include "Service.h"

using namespace std;

/*Teste Masina*/
void TestMasina()
{
	Masina M1("Andrei", "B999FGH", "New");
	Masina M2("Vlad", "CJ89DGI", "Second");
	Masina M3("George", "BH69CSM", "New");
	Masina M4("David", "TM19GYM", "NEW");

	assert(strcmp(M1.getNrInmatriculare(), "B999FGH") == 0);
	M1.setNrInmatriculare("CJ70ASF");
	assert(strcmp(M1.getNrInmatriculare(), "CJ70ASF") == 0);

	assert(strcmp(M2.getNumePosesor(), "Vlad") == 0);
	M2.setNumePosesor("Razvan");
	assert(strcmp(M2.getNumePosesor(), "Razvan") == 0);

	assert(strcmp(M3.getStatus(), "New") == 0);
	M3.setStatus("Old");
	assert(strcmp(M3.getStatus(), "Old") == 0);

	Masina M5;
	M5 = M1;
	assert(strcmp(M5.getNrInmatriculare(), "CJ70ASF") == 0);
	assert(M5 == M1);

	Masina M6;
	assert(M6.getNrInmatriculare() == NULL);
	assert(M6.getStatus() == NULL);
	assert(M6.getNumePosesor() == NULL);
}

/*Teste Repository*/
void TestRepository()
{
	Masina M1("Andrei", "B999FGH", "New");
	Masina M2("Vlad", "CJ89DGI", "Second");
	Masina M3("George", "BH69CSM", "New");
	Masina M4("David", "TM19GYM", "NEW");
	Repository rep;
	rep.addElem(M1);
	rep.addElem(M2);
	rep.addElem(M3);
	rep.addElem(M4);
	list<Masina> l = rep.getAll();
	assert(l.front() == M1);
	assert(l.back() == M4);
	assert(rep.size() == 4);

}

/*Teste Service*/
void TestService()
{
	Masina M1("Andrei", "B999FGH", "Ocupat");
	Masina M2("Vlad", "CJ89DGI", "Liber");
	Masina M3("George", "BH69CSM", "Liber");
	Masina M4("David", "TM19GYM", "Ocupat");
	RepositoryTemplate<Masina> repo;
	Service ser(repo);
	ser.addMasinaService(M1);
	ser.addMasinaService(M2);
	ser.addMasinaService(M3);
	ser.addMasinaService(M4);
	list<Masina> l = ser.getAll();
	assert(l.front() == M1);
	assert(l.back() == M4);
	ser.delMasinaService(M1);
}

/*In aceasta functie apelem testele de mai sus*/
void MainTests()
{
	cout << "Primele teste" << endl;
	TestMasina();
	TestRepository();
	TestService();
	cout << "Testel au fost perfecte" << endl;
	cout << endl;
}
