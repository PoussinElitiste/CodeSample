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

	virtual string & Description()
	{
		return description_;
	}
};

class DecorativeComponent
	: public Computer
{
	string description_;

	public:
		DecorativeComponent(string & description)
			:description_(description)
		{
		}

		string & Description()
		{
			return description_;
		}
};

class Disk
	: virtual public DecorativeComponent
{
	//Computer * computer_;

public:
	Disk(Computer * computer)
		//: computer_(computer), 
		: DecorativeComponent(computer->Description() + " and a disk")
	{
	}

	/*string Description()
	{
		return computer_->Description() + " and a disk";
	}*/
};

class CD
	: virtual public DecorativeComponent
{
	//Computer * computer_;

public:
	CD(Computer * computer)
		//: computer_(computer), 
		: DecorativeComponent(computer->Description() + " and a CD")
	{
	}

	/*string Description()
	{
		return computer_->Description() + " and a CD";
	}*/
};

class Moniteur
	: virtual public DecorativeComponent
{
	//Computer * computer_;

public:
	Moniteur(Computer * computer)
		//:  computer_(computer), 
		: DecorativeComponent(computer->Description() + " and a Monitor")
	{
	}

	/*string Description()
	{
		return computer_->Description() + " and a Monitor";
	}*/
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