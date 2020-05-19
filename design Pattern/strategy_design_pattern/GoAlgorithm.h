#include <iostream>
using std::cout;
using std::endl;

class GoAlgorithm
{
public:
	virtual void Go() = 0;
};

class GoDrivingAlgorithm
	:public GoAlgorithm
{
public:
	void Go()
	{
		cout << "I'm driving" << endl;
	}
};

class GoFlyingAlgorithm
	:public GoAlgorithm
{
public:
	void Go()
	{
		cout << "I'm flying" << endl;
	}
};

class GoFlyingFastAlgorithm
	:public GoAlgorithm
{
public:
	void Go()
	{
		cout << "I'm flying fast" << endl;
	}
};