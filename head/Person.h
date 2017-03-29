#pragma once
#include "Header.h"

using namespace std;

class Person 
{
protected:
	char name[20];
	char surname[20];
	int birth;
public:
	Person();
	Person(char *name, char *surname);
	Person(char *name, char *surname, int birth);
	Person(const Person &obj);
	virtual ~Person();
	char* getName();
	char* getSurname();
	int getBirth();
	void setName(char* str);
	void setSurname(char* str);
	void setBirth(int);
	virtual void edge();

	friend ostream &operator<< (ostream &out, Person obj);
	friend istream &operator>> (istream &in, Person& bt);

	friend ofstream &operator<< (ofstream &out, Person& obj);
	friend ifstream &operator>> (ifstream &in, Person& obj);

	bool isNull() const;
	bool operator>(const Person& obj) const;
	bool operator>=(const Person& obj) const;
	bool operator<(const Person& obj) const;
	bool operator<=(const Person& obj) const;
	bool operator==(const Person& obj) const;

};
