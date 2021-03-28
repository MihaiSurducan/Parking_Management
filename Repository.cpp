#include "Repository.h"
#include <string>
#include <fstream>

using namespace std;

/*Constructorul*/
Repository::Repository()
{
}

/*Adaugare element*/
int Repository::addElem(Masina m)
{
	list<Masina>::iterator it;
	int ok = 1;
	for (it = elem.begin(); it != elem.end(); it++)
		if (strcmp((*it).getNrInmatriculare(), m.getNrInmatriculare()) == 0)
			ok = 0;
	it = find(elem.begin(), elem.end(), m);
	if (it == elem.end() and ok == 1)
	{
		elem.push_back(m);
		return 1;
	}
	return 0;
}

/*Modificare elem*/
void Repository::updateElem(const Masina& m, const char* newNumePosesor, const char* newNrInmatriculare, const char* newStatus)
{
	list<Masina>::iterator it;
	it = find(elem.begin(), elem.end(), m);
	if (it != elem.end()) {
		(*it).setNrInmatriculare(newNrInmatriculare);
		(*it).setNumePosesor(newNumePosesor);
		(*it).setStatus(newStatus);
	}

}

//returneaza pozitia la care se gaseste studentul s, sau -1, daca acesta nu apare
int Repository::findElem(Masina m)
{
	list<Masina>::iterator it;
	it = find(elem.begin(), elem.end(), m);
	if (it != elem.end()) {
		return distance(elem.begin(), it);
	}
	return -1;
}

//sterge elementul s din repository, returneaza 0 la succes, -1 altfel
int Repository::delElem(const Masina& m)
{
	list<Masina>::iterator it;
	it = find(elem.begin(), elem.end(), m);
	if (it != elem.end()) {
		elem.erase(it);
		return 0;
	}
	return -1;

}

/*Returneaza toate elementele*/
list<Masina> Repository::getAll()
{
	return elem;
}

/*REturneaza numarul de elemente*/
int Repository::size()
{
	return elem.size();
}

/*Cautare Masina*/
bool Repository::findMasina(const Masina& m) {
	list<Masina>::iterator it;
	it = find(elem.begin(), elem.end(), m);
	if (it != elem.end())
		return true;
	return false;
}

/*Returneaza elemntul de pe poz i*/
Masina Repository::getItemFromPos(int i) {
	list<Masina>::iterator it;
	int k = 0;
	for (it = elem.begin(); it != elem.end(); it++)
	{
		if (k == i)
			return *it;
		k++;

	}
	return Masina("", "", "");
}

/*Destructorul*/
Repository::~Repository()
{

}

