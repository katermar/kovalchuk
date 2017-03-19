#pragma once
#include "Header.h"
#include "Person.h"

class Tourist : virtual public Person
{
protected:
	char passportNum[10];
	borderCross data[1];
public:
	Tourist(char *name, char *surname, int birth, char *passport, borderCross *data);
	Tourist(const Tourist &obj);
	Tourist();
	virtual ~Tourist();
	char* getPassportNum();
	void setPassportNum(char*);
	borderCross* getData();
	void setData(borderCross *data);
	void edge();

	friend ostream &operator<< (ostream &out, Tourist obj);
	friend istream &operator>> (istream &in, Tourist& bt);

	friend ofstream &operator<< (ofstream &out, Tourist& obj);
	friend ifstream &operator>> (ifstream &in, Tourist& obj);
};