#pragma once
#include "ExceptionIn.h"

void myTerminate();
void myUnexpected();

int numberInputError();

int stringInputError(string s);
string stringError();

int stringNumberInputError(string s);
int numberBoundsError(int number, int a, int b);
int nameException(string s);
string nameInputException();

int dateInputError(string s);
string dateError();