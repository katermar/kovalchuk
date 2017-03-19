#pragma once
#include "ExceptionIn.h"

void myTerminate();
void myUnexpected();

int numberInputError() throw (MyExceptionIn);

int stringInputError(string s) throw (MyExceptionIn);
string stringError();

int stringNumberInputError(string s) throw (MyExceptionIn);
int numberBoundsError(int number, int a, int b) throw (MyExceptionIn);
int nameException(string s) throw (MyExceptionIn);
string nameInputException() throw (MyExceptionIn);

int dateInputError(string s) throw (MyExceptionIn);
string dateError() throw (MyExceptionIn);