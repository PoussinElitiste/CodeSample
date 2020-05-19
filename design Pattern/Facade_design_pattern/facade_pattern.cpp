// |------------|-----------|-----------|
// |			|			|			|
// | Complex	| Facade	| Simple	|
// | interface	|			| Interface	|
// |			|			|			|
// |------------|-----------|-----------|

#ifndef FACADE_PATTERN
#define FACADE_PATTERN

#include <iostream>
using std::cout;
using std::endl;
#include <string>
using std::string;

class DifficultObject
{
	enum{NB_CHAR = 7};
	char name_[7];

public:
	DifficultObject()
	{
	}

	void SetChar0(const char c)
	{
		name_[0] = c;
	}

	void SetChar1(const char c)
	{
		name_[1] = c;
	}

	void SetChar2(const char c)
	{
		name_[2] = c;
	}

	void SetChar3(const char c)
	{
		name_[3] = c;
	}
	void SetChar4(const char c)
	{
		name_[4] = c;
	}
	void SetChar5(const char c)
	{
		name_[5] = c;
	}
	void SetChar6(const char c)
	{
		name_[6] = c;
	}
	string GetName()
	{
		return string(name_, NB_CHAR);
	};
};

class SimpleFacade
{
	DifficultObject obj_;

public:
	SimpleFacade()
	{}

	void SetName(const string & name)
	{
		if (name.length() >1)
		{
			obj_.SetChar0(name[0]);
		}

		if (name.length() >2)
		{
			obj_.SetChar1(name[1]);
		}

		if (name.length() >3)
		{
			obj_.SetChar2(name[2]);
		}

		if (name.length() >4)
		{
			obj_.SetChar3(name[3]);
		}

		if (name.length() >5)
		{
			obj_.SetChar4(name[4]);
		}

		if (name.length() >6)
		{
			obj_.SetChar5(name[5]);
		}

		if (name.length() >=7)
		{
			obj_.SetChar6(name[6]);
		}
	}

	string GetName()
	{
		return obj_.GetName();
	}
};

int main()
{
	// Avant
	/*DifficultObject obj;

	obj.SetChar0('P');
	obj.SetChar1('r');
	obj.SetChar2('i');
	obj.SetChar3('n');
	obj.SetChar4('t');
	obj.SetChar5('e');
	obj.SetChar6('r');*/

	// Apres
	SimpleFacade obj;

	obj.SetName("Ptinter");

	cout << obj.GetName() << endl;
};

#endif