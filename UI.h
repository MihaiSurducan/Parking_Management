#pragma once
#include "Service.h"

class UI {
private:
	Service service;
	void printMenu();
	void addMasina();
	void delMasina();
	void updateMasina();
	void printAll();
	void intrareParcare();
	void iesireParcare();
public:
	UI(Service& s) :service(s) {};
	void run();
	~UI();
};