#include <iostream>
using std::cout;
using std::endl;

class Observer
{
public:
	virtual void Update(string operation, string record) = 0;
};

class Archiver
	:public Observer
{
public:
	Archiver()
	{}

	void Update(string operation, string record)
	{
		cout << "archiver operation : " << operation << ", record : " << record << endl;
	};
};

class Client
	:public Observer
{
public:
	Client()
	{}

	void Update(string operation, string record)
	{
		cout << "Client operation : " << operation << ", record : " << record << endl;
	};
};

class Boss
	:public Observer
{
public:
	Boss()
	{}

	void Update(string operation, string record)
	{
		cout << "Boss operation : " << operation << ", record : " << record << endl;
	};
};