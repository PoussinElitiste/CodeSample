#ifndef STATE_H
#define STATE_H

#include <string>
using std::string;

class StateB;

class IState
{
public:
	virtual string Action1() = 0;
	virtual string Action2() = 0;
	virtual string Action3() = 0;
};

class IAutomat;

class StateA
	: public IState
{
	IAutomat * automat_;

public:
	StateA(IAutomat * a)
		:automat_(a)
	{}

	string Action1();
	string Action2();
	string Action3();

};

class StateB
	:public IState
{
	IAutomat * automat_;

public:
	StateB(IAutomat * a)
		:automat_(a)
	{}

	string Action1();
	string Action2();
	string Action3();
};

class StateC
	:public IState
{
	IAutomat * automat_;

public:
	StateC(IAutomat * a)
		:automat_(a)
	{}

	string Action1();
	string Action2();
	string Action3();
};

#endif