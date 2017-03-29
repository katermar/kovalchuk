#pragma once
#include "Header.h"
#include "Businessman.h"
#include "Tourist.h"

class Businesstourist : public Businessman, public Tourist
{
protected:
	char adress[40];
public:
	Businesstourist(char *name, char *surname, int birth, int lisence, taxData *info, char *passport, borderCross *data, char *adress, int n);
	Businesstourist(const Businesstourist &obj);
	Businesstourist();
	~Businesstourist();
	char * getAdress();
	void setAdress(char*);
	void edge() override;

	friend ostream &operator<< (ostream &out, Businesstourist obj);
	friend istream &operator>> (istream &in, Businesstourist& bt);

	friend ofstream &operator<< (ofstream &out, Businesstourist& obj);
	friend ifstream &operator>> (ifstream &in, Businesstourist& obj);
};