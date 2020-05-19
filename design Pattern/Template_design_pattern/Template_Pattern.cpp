// |----------------------------|
// | class derive				|
// |	|-------------------|	|
// |	| Class	Base		|	|
// |	|					|	|
// |	| method 1			|	|
// |	| method 2			|	|
// |	| method 3			|	|
// |	| method 4			|	|
// |	|					|	|
// |	|-------------------|	|
// |							|
// |	method 2 modified		|
// |	method 3 modified		|
// |							|
// |----------------------------|

#include <iostream>
using std::cout;
using std::endl;
#include <string>
using std::string;

class RobotTemplate
{
public:
	virtual void Start()
	{
		cout << "basic starting..." << endl;
	}

	virtual void GetParts()
	{
		cout << "basic getting parts..." << endl;
	}

	virtual void Assemble()
	{
		cout << "basic assembling..." << endl;
	}
	
	virtual void Test()
	{
		cout << "basic testing..." << endl;
	}

	virtual bool TestOK()
	{
		return true;
	};

	virtual void Stop()
	{
		cout << "basic stopping..." << endl;
	}

	void Go()
	{
		Start();
		GetParts();
		Assemble();
		if (TestOK()) // hook technique
			Test();
		Stop();
	}
};


class SpecialRobot
	: public RobotTemplate
{
	string name_;
public:

	SpecialRobot(const string & name)
		:name_(name)
	{}

	void GetParts()
	{
		cout << "Special getting parts..." << endl;
	}

	void Assemble()
	{
		cout << "special assembling..." << endl;
	}

	const string & GetName() const
	{
		return name_;
	}
};

class CookieRobot
	: public RobotTemplate
{
	string name_;

public:
	CookieRobot(const string & name)
		:name_(name)
	{}

	void GetParts()
	{
		cout << "getting ingredients..." << endl;
	}

	void Assemble()
	{
		cout << "cooking..." << endl;
	}

	void Test()
	{
		cout << "tasting..." << endl;
	}

	bool TestOK()
	{
		cout << "no tasting ahah..." << endl;
		return false;
	}

	const string & GetName() const
	{
		return name_;
	}
};


int main()
{
	SpecialRobot robotSP("Momo");

	cout << robotSP.GetName() << endl;
	robotSP.Go();

	CookieRobot robotCook("the chief");
	cout << robotCook.GetName() << endl;
	robotCook.Go();

}