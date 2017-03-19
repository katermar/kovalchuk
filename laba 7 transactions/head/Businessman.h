#pragma once
#include "Header.h"
#include "Person.h"

class Businessman : virtual public Person
{
protected:
	int lisenceNum;
	taxData info[1];
public:
	Businessman(char *name, char *surname, int birth, int lisence, taxData *info);
	Businessman();
	Businessman(const Businessman &obj);
	virtual ~Businessman();
	int getLisenceNum();
	void setLisenceNum(int);
	taxData* getInfo();
	void setInfo(taxData*);
	void edge();

	friend ostream &operator<< (ostream &out, Businessman obj);
	friend istream &operator>> (istream &in, Businessman& bt);
	
	friend ofstream &operator<< (ofstream &out, Businessman& obj);
	friend ifstream &operator>> (ifstream &in, Businessman& obj);
};