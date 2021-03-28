#pragma once
#include <list>
#include <algorithm>

using namespace std;

template <class T>class RepositoryTemplate 
{
protected:
	list<T> elem;
public:
	RepositoryTemplate<T>();
	virtual int addElem(const T&);
	virtual int delElem(const T&);
	virtual bool findElem(const T&);
	void updateElem(const T& vecheaM, const T nouaM);
	int dim();
	T getItemFromPos(int);
	list<T> getAll();
	~RepositoryTemplate();
};

/*Constructorul*/
template <class T> RepositoryTemplate<T>::RepositoryTemplate()
{
}

/*Adaugare element*/
template<class T> int RepositoryTemplate<T>::addElem(const T& m)
{
	typename list<T>::iterator it;
	it = find(elem.begin(), elem.end(), m);
	if (it == elem.end())
	{
		elem.push_back(m);
		return 0;
	}
	return -1;
}

/*Stergere element*/
template<class T> int RepositoryTemplate<T>::delElem(const T& m)
{
	typename list<T>::iterator it;
	it = find(elem.begin(), elem.end(), m);
	if (it != elem.end())
	{
		elem.erase(it);
		return 0;
	}
	return -1;
}

/*Modificare element*/
template<class T> void RepositoryTemplate<T>::updateElem(const T& vecheaM, const T nouaM)
{
	replace(elem.begin(), elem.end(), vecheaM, nouaM);
}

/*Cautare element*/
template<class T> bool RepositoryTemplate<T>::findElem(const T& m)
{
	typename list<T>::iterator it;
	it = find(elem.begin(), elem.end(), m);
	if (it != elem.end())
		return true;
	return false;
}

/*Returneaza numarul de element*/
template<class T> int RepositoryTemplate<T>::dim()
{
	return elem.size();
}

/*Retruneaza toate elementele*/
template<class T> list<T> RepositoryTemplate<T>::getAll()
{
	return elem;
}

/*REturneaza elementul de pe pozitia i*/
template<class T> T RepositoryTemplate<T>::getItemFromPos(int i) {
	typename list<T>::iterator it;
	int k = 0;
	for (it = elem.begin(); it != elem.end(); it++)
	{
		if (k == i)
			return *it;
		k++;
	}
	return T();
}

/*Destructorul*/
template <class T> RepositoryTemplate<T>::~RepositoryTemplate()
{
}