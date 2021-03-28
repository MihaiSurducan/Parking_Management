#include "Repository.h"
#include "RepositoryFile.h"
#include "Service.h"
#include "RepositoryTemplate.h"
#include "UI.h"
#include "Tests.h"
#include <iostream>

using namespace std;

/*Apelam functia run ca sa putem introduce date si sa vedem ca toate functiile isi fac treaba*/
int main()
{
	MainTests();
	RepositoryFile<Masina> repo("Masini.txt");
	Service serv(repo);
	UI ui(serv);
	ui.run();
	repo.saveToFile();
	return 0;
}