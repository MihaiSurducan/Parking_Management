#include "UI.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/*Meniul care v-a aparea la rulare*/
void UI::printMenu() 
{
	cout << endl;
	cout << "1. Adaugare Masina " << endl;
	cout << "2. Stergere Masina " << endl;
	cout << "3. Modificare Masina " << endl;
	cout << "4. Afisarea tuturor Masinilor" << endl;
	cout << "5. Intrare Masina in Parcare" << endl;
	cout << "6. Iesire Masina din Parcare"<< endl;
	cout << "7. Cate masini au vrut sa intre in parcare si nu au avut loc" << endl;
	cout << "0. Exit" << endl;
}


/*Adaugare Masina UI*/
void UI::addMasina() 
{
	Masina m;
	cin >> m;
	if (strcmp(m.getStatus(), "liber") == 0 or strcmp(m.getStatus(), "ocupat") == 0)
	{
		int rezultat = service.addMasinaService(m);
		if (rezultat == 0)	    cout << "Masina a fost adaugata cu succes!" << endl;
		else if (rezultat == -1)	cout << "Masina nu a fost putut introdusa!" << endl;
		else if (rezultat == -2)	cout << "Masina nu poate fi adaugata ca ocupata!" << endl;
	}
	else  cout << "Statusul trebuie sa fie 'liber' sau 'ocupat'!" << endl;
}

/*Stergere Masina UI*/
void UI::delMasina() 
{
	Masina m;
	cin >> m;
	if (strcmp(m.getStatus(), "liber") == 0 or strcmp(m.getStatus(), "ocupat") == 0)
	{
		int rezultat = service.delMasinaService(m);
		if (rezultat == 0)		cout << "Masina a fost stearsa cu succes!" << endl;
		else if (rezultat == -1)		cout << "Masina nu exista!" << endl;
		else if (rezultat == -2)		cout << "Masina este inca in parcare!" << endl;
	}
	else   cout << " Status trebuie sa fie 'liber' sau 'ocupat'! " << endl;
}

/*Modificare Masina UI*/
void UI::updateMasina() 
{
	cout << " Introduceti datele masinii pe care doriti sa o modificati:" << endl;
	Masina m;
	cin >> m;
	if (service.findElemService(m))
	{
		cout << " Noile date ale masini:" << endl;
		Masina nouaM;
		cin >> nouaM;
		if (strcmp(nouaM.getStatus(), "liber") == 0 or strcmp(nouaM.getStatus(), "ocupat") == 0)
		{
			int rezultat = service.updateMasinaService(m, nouaM);
			if (rezultat == -2)
				cout << "Masina nu poate modificata ca 'ocupat'!" << endl;
		}
		else
			cout << "Statusul trebuie sa fie 'liber' sau 'ocupat'!" << endl;
	}
	else
		cout << "Masina nu exista!" << endl;
}

/*Afisarea tuturor masinilor UI*/
void UI::printAll()
{
	list<Masina> masina = service.getAll();
	for (Masina m : masina)
		cout << m;
}

/*Intrare in Parcare UI*/
void UI::intrareParcare() 
{
	char* nr = new char[25];
	cout << "Numarul de Inmatriculare a Masinii care doriti sa intre in parcare: ";
	cin >> nr;
	Masina m;
	for (int i = 0; i < service.dim(); i++)
		if (strcmp(service.getItemFromPos(i).getNrInmatriculare(), nr) == 0)
			m = service.getItemFromPos(i);
	delete[] nr;

	if (service.findElemService(m) == true) 
	{
		int rezultat = service.intrareParcare(m);
		if (rezultat == 0)		cout << "Masina a intrat cu succes in parcare!" << endl;
		else if (rezultat == -1)	cout << "Masina este deja in parcare!" << endl;
		else if (rezultat == -2)	cout << "Parcarea este plina!" << endl;
	}
	else
		cout << "Masina nu exista!" << endl;
}

/*Iesire din Parcare UI*/
void UI::iesireParcare() 
{
	char* nr = new char[25];
	cout << "Numarul de Inmatriculare a Masinii care doriti sa intre in parcare: ";
	cin >> nr;
	Masina m;
	for (int i = 0; i < service.dim(); i++)
		if (strcmp(service.getItemFromPos(i).getNrInmatriculare(), nr) == 0)
			m = service.getItemFromPos(i);
	delete[] nr;

	if (service.findElemService(m) == true)
	{
		int rezultat = service.iesireParcare(m);
		if (rezultat == 0)		cout << "Masina a iesit cu succes din parcare!" << endl;
		else if (rezultat == -1)	cout << "Masina nu este in parcare!" << endl;
	}
	else
		cout << "Masina nu exista!" << endl;
}

/*In aceasta functie se executa optiunile alese de utilizator*/
void UI::run()
{
	cout << "Numarul locurilor de parcare: ";
	int nr;
	cin >> nr;
	service.seteazaNumarulDeLocuri(nr);
	int option;
	bool ok = true;
	while (ok)
	{
		printMenu();
		cout << "Optiunea: ";
		cin >> option;
		switch (option)
		{
		case 1:addMasina(); break;
		case 2:delMasina(); break;
		case 3:updateMasina(); break;
		case 4:printAll(); break;
		case 5:intrareParcare(); break;
		case 6:iesireParcare(); break;
		case 7:cout << service.numar << " Masini nu au reusit sa intre in parcare! " << endl; break;
		case 0:	ok = false; break;
		default:
			cout << "Nu exista optiunea pe care ati introdusa.Incercati din nou." << endl;
		}
	}
}

/*Destructorul UI*/
UI::~UI() 
{
}