#pragma once
#include <iostream>
#include <string>
using namespace std;

class Masina{
private:
	char* numePosesor;
	char* nrInmatriculare;
	char* status;
public:
	Masina();
	Masina(const char*, const char*, const char*);
	Masina(const Masina&);
	char* getNumePosesor();
	void setNumePosesor(const char*);
	char* getNrInmatriculare();
	void setNrInmatriculare(const char*);
	char* getStatus();
	void setStatus(const char*);
	bool operator==(const Masina&);
	Masina& operator=(const Masina&);
	friend ostream& operator<<(ostream& os, Masina);
	friend istream& operator>>(istream&, Masina&);
	~Masina();

};