#pragma once
#include "head/Businessman.h"
//#include "head\Person.h"

using namespace std;

Businessman :: Businessman() : Person(), lisenceNum(0)
{
}

Businessman :: Businessman(char *name, char *surname, int birth, int lisence, taxData *info) : Person(name, surname, birth)
{
	this->lisenceNum = lisence;

	for (unsigned i = 0; i < sizeof(*info)/sizeof(taxData); i++)
		this->info[i] = info[i];
}

Businessman :: Businessman(const Businessman &obj) : Person(obj)
{
	this->lisenceNum = obj.lisenceNum;

	for (unsigned i = 0; i < sizeof(*(obj.info))/sizeof(taxData); i++)
		this->info[i] = obj.info[i];
}

Businessman :: ~Businessman()
{
	//cout << "DESTRUCTOR businessman" << endl;
	lisenceNum = NULL;
}
//****************************************************************

int Businessman :: getLisenceNum() const
{
	return this->lisenceNum;
}

void Businessman :: setLisenceNum(int num)
{
	this->lisenceNum = num;
}

taxData* Businessman :: getInfo()
{
	return this->info;
}

void Businessman :: setInfo(taxData *info)
{
	for (unsigned i = 0; i < sizeof(*(this->info))/sizeof(taxData); i++)
		this->info[i] = info[i];
}

void Businessman :: edge()
{
	cout << "==========================================================================" << endl;
	cout << "                            BUSINESSMAN                                   " << endl;
	cout << "==========================================================================" << endl;
	cout << "|           NAME              | BIRTH  |   LISENCE   |        TAXES       |" << endl;
	cout << "|-----------------------------|--------|-------------|--------------------|" << endl;
}

ostream &operator<< (ostream &out, Businessman bt)
{
	for (int k = 0, l = 0; l < sizeof(*bt.getInfo())/sizeof(taxData); l++, k++)
	{
		out << *(dynamic_cast<Person*>(&bt))
			<< setw(13) << bt.getLisenceNum()  << "|"
			<< setw(18) << bt.getInfo()[l].amount << " " << bt.getInfo()[l].date 
			<< endl;
	}
	return out;
}

istream &operator>> (istream &in, Businessman &bt)
{
	in >> *(dynamic_cast<Person*>(&bt));

	set_terminate(myTerminate);
	set_unexpected(myUnexpected);

	int error = 0;

	for (int i = 0; i < 1; i++)
	{
		cout << "\nenter tax amount:" ;
		bt.info[i].amount = numberInputError();

		cout << "enter tax date:(dd/mm/yyyy)  ";
		strcpy(bt.info[i].date, dateError().c_str());
	}

	cout << "\nenter lisence №: ";
	do {
		try {
			bt.lisenceNum = numberInputError();
			numberBoundsError(bt.lisenceNum, 0, 999999999);
			error = 1;
		} catch (MyExceptionIn ex) {
			cin.clear();
			fflush(stdin);
			cout << ex.what() << " detected. try again" << endl;
		} catch (...) {
			cin.clear();
			fflush(stdin);
			cout << "Ошибка! Вызван абсолютный обработчик!";
		}
	} while(!error);

	return in;
}
//**********************************************************

ofstream &operator<< (ofstream &out, Businessman& obj)
{
	out << *(dynamic_cast<Person*>(&obj)) << obj.info[0].amount << " " << obj.info[0].date << " " << obj.lisenceNum << "$" ;
	return out;
}

ifstream &operator>> (ifstream &in, Businessman& obj)
{
	in >> *(dynamic_cast<Person*>(&obj));
	char a[10];
	in.getline(a, 10, ' ');
	obj.info[0].amount = atoi(a);
	in.getline(obj.info[0].date, 11, ' ');
	in.getline(a, 10, '$');
	obj.lisenceNum = atoi(a);
	return in;
}

//**********************************************************