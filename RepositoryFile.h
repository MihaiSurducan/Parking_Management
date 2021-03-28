#pragma once
#include <list>
#include <fstream>
#include <iostream>
#include <string>
#include "RepositoryTemplate.h"

using namespace std;

template<class T> class RepositoryFile : public RepositoryTemplate<T>
{
private:
	const char* fileName;
public:
	RepositoryFile();
	RepositoryFile(const char*);
	void saveToFile();
	void loadFromFile(const char*);
	int addElem(T);
	int delElem(T);
	void updateElem(T, const T);
	~RepositoryFile();
};

/*Constructorul*/
template<class T> RepositoryFile<T>::RepositoryFile() :RepositoryTemplate<T>()
{
	fileName = "";
}

/*Declaram fisierul unde vrem sa fie salvate datele*/
template<class T> RepositoryFile<T>::RepositoryFile(const char* file) : RepositoryTemplate<T>() 
{
	loadFromFile(file);
}

/*Salveaza in fisier*/
template<class T> void RepositoryFile<T>::saveToFile()
{
	ofstream f(this->fileName);
	for (int i = 0; i < RepositoryTemplate<T>::dim(); i++)
		f << RepositoryTemplate<T>::getItemFromPos(i);
	f.close();
}

/*Ia date din fisier*/
template<class T> void RepositoryFile<T>::loadFromFile(const char* file) 
{

	fileName = file;
	ifstream f(file);
	char* nume = new char[25];
	char* nr = new char[25];
	char* status = new char[25];

	while (!f.eof()) {
		f >> nume >> nr >> status;
		if (nume != "") {
			T m(nume, nr, status);
			RepositoryTemplate<T>::addElem(m);
		}
	}

	delete[] nume;
	delete[] nr;
	delete[] status;
	f.close();
}

/*Adaugare Element*/
template<class T> int RepositoryFile<T>::addElem(T m) 
{
	int rezultat = RepositoryTemplate<T>::addElem(m);
	return rezultat;
}

/*stergere Element*/
template<class T> int RepositoryFile<T>::delElem(T m) 
{
	int rezultat = RepositoryTemplate<T>::delElem(m);
	return rezultat;
}

/*Modificare Element*/
template<class T> void RepositoryFile<T>::updateElem(T vecheaM, const T nouaM) 
{
	RepositoryTemplate<T>::updateElem(vecheaM, nouaM);
}

/*Destructorul*/
template<class T> RepositoryFile<T>::~RepositoryFile()
{
}