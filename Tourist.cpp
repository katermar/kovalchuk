#pragma once
#include "head/Tourist.h"

using namespace std;

Tourist :: Tourist() : Person()
{
	*passportNum = NULL;
}

Tourist :: Tourist(char *name, char *surname, int birth, char *passport, borderCross *data) : Person(name, surname, birth)
{
	strcpy(this->passportNum, passport);

	for (unsigned i = 0; i < sizeof(*data)/sizeof(borderCross); i++)
		this->data[i] = data[i];
}

Tourist :: Tourist(const Tourist &obj) : Person(obj)
{
	strcpy(this->passportNum, obj.passportNum);

	for (unsigned i = 0; i < sizeof(*(obj.data))/sizeof(borderCross); i++)
		this->data[i] = obj.data[i];
}

Tourist :: ~Tourist()
{
	//cout << "DESTRUCTOR tourist" << endl;
	for (unsigned i = 0; i < strlen(passportNum); i++)
		passportNum[i] = 0;
}

//**********************************************************

char* Tourist :: getPassportNum()
{
	return passportNum;
}

void Tourist :: setPassportNum(char* num)
{
	strcpy(passportNum, num);
}

borderCross* Tourist :: getData()
{
	return data;
}

void Tourist :: setData(borderCross *data)
{
	for (unsigned i = 0; i < sizeof(*(data))/sizeof(borderCross); i++)
		this->data[i] = data[i];
}

void Tourist :: edge()
{
	cout << "===========================================================================" << endl;
	cout << "                                TOURIST                        " << endl;
	cout << "===========================================================================" << endl;
	cout << "|           NAME              | BIRTH  |   PASSPORT   |  BORDERCROSSINGS   |" << endl;
	cout << "|-----------------------------|--------|--------------|--------------------|" << endl;
}

ostream &operator<< (ostream &out, Tourist bt)
{
	//bt.edge();
	for (int k = 0, l = 0; k < sizeof(*bt.getData())/sizeof(borderCross); l++, k++)
	{
		out << *(dynamic_cast<Person*>(&bt)) << setw(14) << bt.getPassportNum() << "|"
			<< setw(18) << bt.getData()[k].country << " " << bt.getData()[k].date 
			<< endl << "|-----------------------------|--------|--------------|--------------------|" << endl;
	}
	return out;
}

istream &operator>> (istream &in, Tourist &bt)
{
	in >> *(dynamic_cast<Person*>(&bt));

	cout << "\nenter num. of passport: ";
	strcpy(bt.passportNum, passportNumError().c_str());

	for (int i = 0; i < 1; i++)
	{
		cout << "\nenter date of crossing the border(dd/mm/yyyy) : ";
		strcpy(bt.data[i].date, dateError().c_str());

		cout << "\nenter country: ";
		strcpy(bt.data[i].country, nameInputException().c_str());
	}

	return in;
}
//works super cool
ofstream &operator<< (ofstream &out, Tourist& obj)
{
	out << *(dynamic_cast<Person*>(&obj)) << obj.data[0].country << " " << obj.data[0].date << " " << obj.passportNum << "$";
	return out;
}

ifstream &operator>> (ifstream &in, Tourist& obj)
{
	in >> *(dynamic_cast<Person*>(&obj));
	in.getline(obj.data[0].country, 20, ' ');
	in.getline(obj.data[0].date, 11, ' ');
	in.getline(obj.passportNum, 10, '$');
	return in;
}