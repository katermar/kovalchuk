#pragma once
#include "head\Businesstourist.h"

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
	int error = 0;

	cout << "\nenter num. of passport: ";
	strcpy(bt.passportNum, stringError().c_str());
	fflush(stdin);
	/*do {
		try {
			in >> bt.passportNum;
			stringInputError(bt.passportNum);
			error = 1;
		} catch (MyExceptionIn ex) {
			cin.clear();
			fflush(stdin);
			cout << ex.what() << "detected. try again" << endl;
		} catch (...) {
			cin.clear();
			fflush(stdin);
			cout << "Ошибка! Вызван абсолютный обработчик!";
		}
	} while(!error);*/
	for (int i = 0; i < 1; i++)
	{
		cout << "\nenter date of crossing the border(dd/mm/yyyy) : ";
		strcpy(bt.data[i].date, dateError().c_str());
		////in >> bt.data[i].date;
		//do {
		//	try {
		//		in >> bt.data[i].date;
		//		dateInputError(bt.data[i].date);
		//		//stringInputError(bt.data[i].date);
		//		error = 1;
		//	} catch (MyExceptionIn ex) {
		//		cout << ex.what() << " detected. try again" << endl;
		//	}
		//} while(!error);

		cout << "\nenter country: ";
		strcpy(bt.data[i].country, stringError().c_str());
		////in >> bt.data[i].country;
		//do {
		//	try {
		//		in >> bt.data[i].country;
		//		stringInputError(bt.data[i].country);
		//		error = 1;
		//	} catch (MyExceptionIn ex) {
		//		cout << ex.what() << " detected. try again" << endl;
		//	}
		//} while(!error);
	}
	cout << "enter adress: ";
	strcpy(bt.adress, stringError().c_str());
	//in >> bt.adress;
	//do {
	//		try {
	//			in >> bt.adress;
	//			stringInputError(bt.adress);
	//			error = 1;
	//		} catch (MyExceptionIn ex) {
	//			cout << ex.what() << " detected. try again" << endl;
	//		}
	//} while(!error);
	
	return in;
}
