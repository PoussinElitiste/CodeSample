#include "Automat.h"

#include <iostream>
using std::cout;
using std::endl;

void Automat::Action1()
{
	cout << currentState_->Action1() << endl;
}

void Automat::Action2()
{
	cout << currentState_->Action2() << endl;
}

void Automat::Action3()
{
	cout << currentState_->Action3() << endl;
}