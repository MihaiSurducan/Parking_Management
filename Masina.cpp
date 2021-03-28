#include "Masina.h"
#include <string.h>
#include <iostream>

using namespace std;

/*Constructorul*/
Masina::Masina() 
{
	numePosesor = NULL;
	nrInmatriculare = NULL;
	status = NULL;
}

Masina::Masina(const char* nume, const char* nr, const char* sta)
{
	numePosesor = new char[strlen(nume) + 1];
	strcpy_s(numePosesor, strlen(nume) + 1, nume);

	nrInmatriculare = new char[strlen(nr) + 1];
	strcpy_s(nrInmatriculare, strlen(nr) + 1, nr);
	
	status = new char[strlen(sta) + 1];
	strcpy_s(status, strlen(sta) + 1, sta);
}

Masina::Masina(const Masina& m) 
{
	numePosesor = new char[strlen(m.numePosesor) + 1];
	strcpy_s(numePosesor, strlen(m.numePosesor) + 1, m.numePosesor);

	nrInmatriculare = new char[strlen(m.nrInmatriculare) + 1];
	strcpy_s(nrInmatriculare, strlen(m.nrInmatriculare) + 1, m.nrInmatriculare);

	status = new char[strlen(m.status) + 1];
	strcpy_s(status, strlen(m.status) + 1, m.status);
}

/*Returneaza Numele Posesorului*/
char* Masina::getNumePosesor() 
{
	return numePosesor;
}

/*Schimbam Numele Posesorului*/
void Masina::setNumePosesor(const char* newNumePosesor) 
{
	if (numePosesor) delete[] numePosesor;
	numePosesor = new char[strlen(newNumePosesor) + 1];
	strcpy_s(numePosesor, strlen(newNumePosesor) + 1, newNumePosesor);
}

/*Returneaza Numarul de Inmatriculare*/
char* Masina::getNrInmatriculare() 
{
	return nrInmatriculare;
}

/*Schimbam numarul de inmatriculare*/
void Masina::setNrInmatriculare(const char* newNrInmatriculare)
{
	if (nrInmatriculare) delete[] nrInmatriculare;
	nrInmatriculare = new char[strlen(newNrInmatriculare) + 1];
	strcpy_s(nrInmatriculare, strlen(newNrInmatriculare) + 1, newNrInmatriculare);
}

/*Returneaza statusul masinii*/
char* Masina::getStatus()
{
	return status;
}

//Schimbam statusul masinii
void Masina::setStatus(const char* newStatus) 
{
	if (status)	delete[] status;
	status = new char[strlen(newStatus) + 1];
	strcpy_s(status, strlen(newStatus) + 1, newStatus);
}

Masina& Masina::operator=(const Masina& m) 
{
	if (this == &m) return *this;
	if (m.numePosesor)	setNumePosesor(m.numePosesor);
	if (m.nrInmatriculare)	setNrInmatriculare(m.nrInmatriculare);
	if (m.status)	setStatus(m.status);
	return *this;
}

/*Declaram operatorul de egalitate*/
bool Masina::operator==(const Masina& m) 
{
	if (m.numePosesor and m.nrInmatriculare and m.status)
		return (strcmp(numePosesor, m.numePosesor) == 0 and strcmp(nrInmatriculare, m.nrInmatriculare) == 0 and strcmp(status, m.status) == 0);
	return false;
}

/*Cu ajutorul acestei functiei putem afisa un obiect de tip Masina*/
ostream& operator<<(ostream& os, Masina m) 
{
	if (m.getNumePosesor())
		os << "NumePosesor - " << m.getNumePosesor() << "	NrInmatriculare - " << m.getNrInmatriculare() << "     Status - " << m.getStatus() << endl;
	return os;
}

/*Declaram operatorul de citire pentru un obiect de tip Masina*/
istream& operator>>(istream& is, Masina& m)
{
	cout << "Nume Posesor: ";
	char* nume = new char[25];
	is >> nume;

	cout << "Numar de Inmatriculare: ";
	char* nr = new char[25];
	is >> nr;

	cout << "Status (liber sau ocupat): ";
	char* status = new char[25];
	is >> status;

	m.setNumePosesor(nume);
	m.setNrInmatriculare(nr);
	m.setStatus(status);

	delete[] nume;
	delete[] nr;
	delete[] status;
	return is;
}

/*Destructorul*/
Masina::~Masina() 
{
	if (numePosesor){
		delete[] numePosesor;
		numePosesor = NULL;
	}

	if (nrInmatriculare){
		delete[] nrInmatriculare;
		nrInmatriculare = NULL;
	}

	if (status){
		delete[] status;
		status = NULL;
	}
}
