#pragma once
#include "head/Person.h"

using namespace std;

Person :: Person()
{
	this->birth = 0;
}

Person :: Person(char *name, char *surname)
{
	this->birth = 0;
	strcpy(this->name, name);
	strcpy(this->surname, surname);
}

Person :: Person(char *name, char *surname, int birth)
{
	this->birth = birth;

	strcpy(this->name, name);
	strcpy(this->surname, surname);
}

Person :: Person(const Person &obj)
{
	birth = obj.birth;

	strcpy(this->name, obj.name);

	strcpy(this->surname, obj.surname);
}

Person :: ~Person()
{
	//cout << "DESTRUCTOR person" << endl;
	birth = NULL;
}
//*******************************************************************/

char* Person :: getName()
{
	return this->name;
}

char* Person :: getSurname()
{
	return this->surname;
}

int Person :: getBirth()
{
	return this->birth;
}

void Person :: setName(char* str)
{
	strcpy(this->name, name);
}

void Person :: setSurname(char* str)
{
	strcpy(this->surname, surname);
}

void Person :: setBirth(int birth)
{
	this->birth = birth;
}

void Person :: edge()
{
	/*cout << setw(24) << "NAME" << "|"<< setw(24) << "BIRTH" << "|" << setw(24) 
	<< "LISENCE"  << "|" << setw(24) << "PASSPORT"  << "|" << setw(24) << "TAXES"  << "|" << setw(24) << "BORDERCROSSINGS"  << endl;*/

	cout << "========================================" << endl
		<< "                PERSON                  " << endl
		<< "========================================" << endl
		<< "|           NAME              | BIRTH  |" << endl
		<< "|-----------------------------|--------|" << endl;
}

ostream &operator<< (ostream &out, Person obj)
{
	//obj.edge();
	/*out << setw(14) << obj.getName() << " " << setw(15) << obj.getSurname() << "|"
	<< setw(8) << obj.getBirth() << "|";*/
	out << obj.getName() << " " << obj.getSurname() << "|"
		<< obj.getBirth() << "|";

	return out;
}


istream &operator>> (istream &in, Person &bt)
{
	int error = 0;
	set_terminate(myTerminate);
	set_unexpected(myUnexpected);

	cout << "enter name: ";
	strcpy(bt.name, nameInputException().c_str());
	//char *name = new char[128];
	//do {
	//	try {
	//		in >> bt.name;
	//		nameInputException(bt.name);
	//		error = 1;
	//	} catch (MyExceptionIn ex) {
	//		cout << ex.what() << " detected. try again" << endl;
	//	}
	//} while(!error);
	//	
	//error = 0;

	cout << "\nenter surname: ";
	strcpy(bt.surname, nameInputException().c_str());
	//do {
	//	try {
	//		in >> bt.surname;
	//		nameInputException(bt.surname);
	//		error = 1;
	//	} catch (MyExceptionIn ex) {
	//		cout << ex.what() << "detected. try again" << endl;
	//	}
	//} while(!error);
	////in >> bt.surname;


	cout << "\nenter birth year: ";
	do {
		try {
			fflush(stdin);
			int date = numberInputError();
			numberBoundsError(date, 1900, 2017);
			bt.birth = date;
			error = 1;
		} catch (MyExceptionIn ex) {
			cout << ex.what() << " detected. try again" << endl;
		} catch (...) {
			cin.clear();
			fflush(stdin);
			cout << "Ошибка! Вызван абсолютный обработчик!";
		}
	} while(!error);

	return in;
}

bool Person :: isNull() const
{
	if (std::strlen(name) == 0 || strlen(surname) == 0 || birth == 0) return true;
	return false;
}

bool Person :: operator>(const Person& obj) const
{
	if (strcmp(this->name, obj.name) > 0)
		return true;
	else return false;
}

bool Person :: operator>=(const Person& obj) const
{
	if (strcmp(this->name, obj.name) > 0 || strcmp(this->name, obj.name) == 0)
		return true;
	else return false;
}

bool Person :: operator<(const Person& obj) const
{
	if (strcmp(this->name, obj.name) < 0)
		return true;
	else return false;
}

bool Person :: operator<=(const Person& obj) const
{
	if (strcmp(this->name, obj.name) > 0 || strcmp(this->name, obj.name) == 0)
		return true;
	else return false;
}
bool Person :: operator==(const Person& obj) const
{
	if (strcmp(this->name, obj.name) == 0)
		return true;
	else return false;
}

//**************************************************************

ofstream &operator<< (ofstream &out, Person& obj)
{
	out << obj.name << " " << obj.surname << " " << obj.birth << "$";
	return out;
}

ifstream &operator>> (ifstream &in, Person& obj)
{
	in.getline(obj.name, 20, ' ');
	in.getline(obj.surname, 20, ' ');
	char b[6];
	in.getline(b, 6, '$');
	obj.birth = atoi(b);

	return in;
}

//**************************************************************