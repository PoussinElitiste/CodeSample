#ifndef STATE_H
#define STATE_H

#include <string>
using std::string;
class Mediator;

class Welcome
{
	Mediator * mediator_;
	string response_;

public:
	Welcome(Mediator * m);
	void Go();
};

class Shop
{
	Mediator * mediator_;
	string response_;

public:
	Shop(Mediator * m);
	void Go();
};

class Purchase
{
	Mediator * mediator_;
	string response_;

public:
	Purchase(Mediator * m);
	void Go();
};

class Exit
{
	Mediator * mediator_;
	string response_;

public:
	Exit(Mediator * m);
	void Go();
};

#endif