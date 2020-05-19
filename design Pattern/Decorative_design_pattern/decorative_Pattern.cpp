// |------------|
// | Computer	|
// |	Desc.()	|
// |------------|
//		^
//		|					|-----------|
// |------------|	  |----	|	CD		|
// | Decorative	|	  |		|-----------|
// | Component	| <-------- |	Disk	|
// |	Desc.()	|	  |		|-----------|
// |------------|	  |----	|	Monitor	|
//							|-----------|

#include <string>
using std::string;
#include <iostream>
using std::cout;

class Computer
{
	string description_;

public:
	Computer()
		: description_("I'm a computer")
	{
	}

	virtual string Description()
	{
		return description_;
	}
};

class DecorativeComponent
	: public Computer
{
	public:
		virtual string Description()=0;
};

class Disk
	: public DecorativeComponent
{
	Computer * computer_;

public:
	Disk(Computer * computer)
		: computer_(computer)
	{
	}

	string Description()
	{
		return computer_->Description() + " and a disk";
	}
};

class CD
	: public DecorativeComponent
{
	Computer * computer_;

public:
	CD(Computer * computer)
		: computer_(computer)
	{
	}

	string Description()
	{
		return computer_->Description() + " and a CD";
	}
};

class Moniteur:
	public DecorativeComponent
{
	Computer * computer_;

public:
	Moniteur(Computer * computer)
		: computer_(computer)
	{
	}

	string Description()
	{
		return computer_->Description() + " and a Monitor";
	}
};

int main()
{
	Computer * computer = new Computer();
	computer = new Disk(computer);
	computer = new Moniteur(computer);
	computer = new CD(computer);
	computer = new CD(computer);

	cout << computer->Description();
}