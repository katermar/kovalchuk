#pragma once
#include "head/funcEx.h"
#include "head/Header.h"

void myTerminate()
{
	cout << "terminate handler called\n";
	exit(1);  
}

void myUnexpected()
{
	cout << "unexpected handler called\n";
	exit(1);  
}

int numberInputError() throw (MyExceptionIn)
{
	int n;
	int error = 0;
	set_terminate(myTerminate);
	set_unexpected(myUnexpected);
	do {
		try {
			cin >> n;
			if (!cin || (char)cin.get() != '\n') throw MyExceptionIn(211, "numberInputException");
			error = 1;
		} catch (MyExceptionIn ex) {
			cin.clear();
			fflush(stdin);
			cout << ex.what() << " detected. try again" << endl;
		} catch (...) {
			cout << "Ошибка! Вызван абсолютный обработчик!";
			cin.clear();
			fflush(stdin);
		}
	} while(!error);

	return n;
}

int dateInputError(string s) throw (MyExceptionIn)
{
	if (s.length() != 10 || s[5] != '/' || s[2] != '/')
		throw MyExceptionIn(208, "dateInputError ");

	return 0;
}

string dateError()
{
	string date;
	int error = 0;
	set_terminate(myTerminate);
	set_unexpected(myUnexpected);
	do {
		try {
			cin >> date;
			dateInputError(date);
			error = 1;
		} catch (MyExceptionIn ex) {
			cout << ex.what() << " detected. try again" << endl;
		} catch (...) {
			cout << "Ошибка! Вызван абсолютный обработчик!";
		}
	} while(!error);

	return date;
}

int stringInputError(string s) throw (MyExceptionIn)
{
	auto lan = 0;
	for (auto i = 0; i < s.length(); i++) {
		int n  = (int)s[i];
		if ((n > 64 && n < 91) || (n > 96 && n < 123) || (n > 47 && n < 58) || n == 47 || n == 92 || n == 58 || n == 45) 
		{
			if (lan == 0) lan = 1;
			if (lan == 2) throw MyExceptionIn(202, "differentLanguageError");
		}
		else if ((n < 0) || n == 183 || n == 167 || (n > 47 && n < 58) || n == 47 || n == 92 || n == 58 || n == 45)
		{
			if (lan == 0) lan = 2;
			if (lan == 1) throw MyExceptionIn(202, "differentLanguageError");
		}
		else throw MyExceptionIn(205, "stringInputError");
	}
	return lan;
}

string stringError()
{
	string s;
	int error = 0;
	set_terminate(myTerminate);
	set_unexpected(myUnexpected);
	do {
		try {
			cin >> s;
			stringInputError(s);
			error = 1;
		} catch (MyExceptionIn ex) {
			cout << ex.what() << " detected. try again" << endl;
		} catch (...) {
			cout << "Ошибка! Вызван абсолютный обработчик!";
		}
	} while(!error);

	return s;
}

string nameInputException()
{
	string name;
	int error = 0;
	set_terminate(myTerminate);
	set_unexpected(myUnexpected);
	do {
		try {
			cin >> name;
			nameException(name);
			error = 1;
		} catch (MyExceptionIn ex) {
			cout << ex.what() << " detected. try again" << endl;
		} catch (...) {
			cout << "Ошибка! Вызван абсолютный обработчик!";
		}
	} while(!error);

	return name;
}

int nameException(string s) throw (MyExceptionIn) 
{
	int lan = 0;
	for (int i = 0; i < s.length(); i++) {
		int n  = (int)s[i];
		if ((int)s[0] <= 65 || (int)s[0] >= 90) throw MyExceptionIn(206, "notCorrectInput");
		if ((int)s[1] <= 96 || (int)s[1] >= 123) throw MyExceptionIn(206, "notCorrectInput");
		if ((n > 64 && n < 91) || (n > 96 && n < 123) || n == 47 || n == 92 || n == 58 || n == 45) 
		{
			if (lan == 0) lan = 1;
			if (lan == 2) throw MyExceptionIn(201, "differentLanguageError");
		}
		else if ((n < 0) || n == 183 || n == 167 || n == 47 || n == 92 || n == 58 || n == 45)
		{
			if (lan == 0) lan = 2;
			if (lan == 1) throw MyExceptionIn(201, "differentLanguageError");
		}
		else throw MyExceptionIn(200, "nameInputException");
	}
	return lan;
}

int stringNumberInputError(string s) throw (MyExceptionIn)
{
	int lan = 0;
	for (int i = 0; i < s.length(); i++) {
		int n  = (int)s[i];
		if ((n > 64 && n < 91) || (n > 96 && n < 123) || (n > 47 && n < 58)) 
		{
			if (lan == 0) lan = 1;
			if (lan == 2) throw MyExceptionIn(209, "differentLanguageError");
		}
		//else if ((n > 191 && n < 256) || n == 183 || n == 167 || (n > 47 && n < 58))
		else if ((n < 0) || n == 183 || n == 167 || (n > 47 && n < 58))
		{
			if (lan == 0) lan = 2;
			if (lan == 1) throw MyExceptionIn(209, "differentLanguageError");
		}
		else throw MyExceptionIn(210, "stringNumberInputError");
	}
	return lan;
}

int numberBoundsError(int number, int a, int b) throw (MyExceptionIn)
{
	if (number > b || number < a) 
		throw MyExceptionIn(213, "numberBoundsError");
	else return 1;
}