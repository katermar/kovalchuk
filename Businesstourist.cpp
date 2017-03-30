#pragma once
#include "head/Businesstourist.h"

using namespace std;


Businesstourist :: Businesstourist(char *name, char *surname, int birth, int lisence, taxData *info, char *passport, borderCross *data, char *adress, int n) : Person(name, surname, birth), Businessman(name, surname, birth, lisence, info), Tourist(name, surname, birth, passport, data)
{
	strcpy(this->adress, adress);
}

Businesstourist :: Businesstourist() : Businessman(), Tourist()
{

}

Businesstourist :: Businesstourist(const Businesstourist &obj) : Person(obj), Tourist(obj), Businessman(obj)
{

	strcpy(adress,obj.adress);	
}

/*
Businesstourist& Businesstourist :: operator=(const Businesstourist &obj)
{
birth = obj.birth;

strcpy(this->name, obj.name);

strcpy(this->surname, obj.surname);

strcpy(this->passportNum, obj.passportNum);

for (unsigned i = 0; i < sizeof(obj.data); i++)
this->data[i] = obj.data[i];

this->lisenceNum = obj.lisenceNum;

for (unsigned i = 0; i < sizeof(*(obj.info))/sizeof(taxData); i++)
this->info[i] = obj.info[i];	

strcpy(adress,obj.adress);

return *this;
}*/

Businesstourist :: ~Businesstourist()
{
	//cout << "EEEEEEEEEEEE" << endl;
	//for (int i = 0; i < adressCounter; i++)
	//	delete [] adress[0];
	//delete []adress;
	//	adressCounter = 0;
}
//**********************************************************

char* Businesstourist :: getAdress()
{
	return this->adress;
}

void Businesstourist :: setAdress(char *adress)
{
	strcpy(this->adress, adress);

}



void Businesstourist :: edge()
{
	cout << "==============================================================================================================" << endl;
	cout << "                                              BUSINESSTOURIST                                                 " << endl;
	cout << "==============================================================================================================" << endl;
	cout << "|           NAME              | BIRTH  |   LISENCE   |   PASSPORT   |        TAXES       |  BORDERCROSSINGS   |" << endl;
	cout << "|-----------------------------|--------|-------------|--------------|--------------------|--------------------|" << endl;
}

ostream &operator<< (ostream &out, Businesstourist bt)
{
	//bt.edge();
	for (int k = 0, l = 0; k < sizeof(*bt.getData())/sizeof(borderCross) || l < sizeof(*bt.getInfo())/sizeof(taxData); l++, k++)
	{
		out << setw(28) << bt.getName() << " " << bt.getSurname() << "|"
			<< setw(8) << bt.getBirth() << "|"
			<< setw(13) << bt.getLisenceNum()  << "|" << setw(14) << bt.getPassportNum() << "|"
			<< setw(18) << bt.getInfo()[l].amount << " " << bt.getInfo()[l].date << "|"
			<< setw(18) << bt.getData()[k].country << " " << bt.getData()[k].date 
			<< endl << "|-----------------------------|--------|-------------|--------------|--------------------|--------------------|" << endl;
	}
	return out;
}

istream &operator>> (istream &in, Businesstourist &bt)
{
	in >> dynamic_cast<Businessman&>(bt);
	set_terminate(myTerminate);
	set_unexpected(myUnexpected);

	cout << "\nenter num. of passport: ";
	strcpy(bt.passportNum, passportNumError().c_str());
	fflush(stdin);

	for (int i = 0; i < 1; i++)
	{
		cout << "\nenter date of crossing the border(dd/mm/yyyy) : ";
		strcpy(bt.data[i].date, dateError().c_str());
		cout << "\nenter country: ";

	}
	cout << "enter adress: ";
	strcpy(bt.adress, stringError().c_str());

	return in;
}

ofstream &operator<< (ofstream &out, Businesstourist& obj)
{
	out << *(dynamic_cast<Businessman*>(&obj))  << obj.data[0].country << " " << obj.data[0].date << " " << obj.passportNum << " " << obj.adress << "$";
	return out;
}

ifstream &operator>> (ifstream &in, Businesstourist& obj)
{
	in >> *(dynamic_cast<Businessman*>(&obj));
	in.getline(obj.data[0].country, 20, ' ');
	in.getline(obj.data[0].date, 11, ' ');
	in.getline(obj.passportNum, 10, ' ');
	in.getline(obj.adress, 40, '$');
	return in;
}
