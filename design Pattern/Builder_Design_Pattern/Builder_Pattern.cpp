// |----------------------------|
// | class derive				|
// |	|-------------------|	|
// |	| Class	Base		|	|
// |	|					|	|
// |	| go{}				|	|
// |	| 					|	|-----------|
// |	|-------------------|	|			|
// |							|			|
// |	actionList defined		|			|
// |							|			|
// |----------------------------|			|
//											|
// |----------------|		|---------------------------|
// | client	code	|		| CookieRobotBuilder		|
// | ex:			|------>|							|
// | - addStart		|<------|	|-------------------|	|
// | - addTest		|robot	|	| Class	Base		|	|
// | - addGetParts	|		|	|	interfaces		|	|
// | - addAssemble	|		|	|-------------------|	|
// | - addStop		|		|	addStart				|
// | - getRobot		|		|	addTest					|
// |				|		|	addGetParts				|
// |----------------|		|	addAssemble				|
//							|	addStop					|
//							|	getRobot				|
//							|---------------------------|

#include <iostream>
using std::cout;
using std::endl;
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <algorithm>
using std::for_each;

enum Action
{
	START = 0,
	GET_PARTS,
	ASSEMBLE,
	TEST,
	STOP
};

class CookieRobotBuildable;

//Foncteur
//struct ActionSelector
//{
//	CookieRobotBuildable & robot_;
//
//public:
//	ActionSelector(CookieRobotBuildable & robot)
//		:robot_(robot)
//	{}
//
//	void operator()(Action & ac)
//	{
//		switch(ac)
//		{
//		case START:
//			robot_.Start();
//			break;
//		case GET_PARTS:
//			robot_.GetParts();
//			break;
//		case ASSEMBLE:
//			robot_.Assemble();
//			break;
//		case TEST:
//			robot_.Test();
//			break;
//		case STOP:
//			robot_.Stop();
//			break;
//		}
//	}
//};

class IRobotBuildable
{
public:
	virtual void Go() = 0;
	virtual const string & GetName() const = 0; 
};

class CookieRobotBuildable
	:public IRobotBuildable
{
	string name_;
	vector<Action> actions_;

public:
	CookieRobotBuildable(const string & name)
		:name_(name)
	{}

	struct ActionSelector
	{
		void operator()(Action & ac)
		{
			switch(ac)
			{
			case START:
				Start();
				break;
			case GET_PARTS:
				GetParts();
				break;
			case ASSEMBLE:
				Assemble();
				break;
			case TEST:
				Test();
				break;
			case STOP:
				Stop();
				break;
			}
		}

		void Start()
		{
			cout << "starting..." << endl;
		}

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

		void Stop()
		{
			cout << "stopping..." << endl;
		}
	};

	void LoadActions(vector<Action> & actions)
	{
		actions_ = actions;
	}

	void Go()
	{
		for_each(actions_.begin(), actions_.end(), ActionSelector());
	}
	
	const string & GetName() const
	{
		return name_;
	}
};

class IRobotBuilder
{
public:
	virtual void addStart() = 0;
	virtual void addTest() = 0;
	virtual void addAssemble() = 0;
	virtual void addGetParts() = 0;
	virtual void addStop() = 0;
	virtual IRobotBuildable & GetRobot() = 0;
};

class CookieRobotBuilder
	:public IRobotBuilder
{
	CookieRobotBuildable robot_;
	vector<Action> actions_;

public:
	CookieRobotBuilder(const string & robotName)
		:robot_(robotName)
	{}

	void addStart()
	{
		actions_.push_back(Action::START);
	}

	void addAssemble()
	{
		actions_.push_back(Action::ASSEMBLE);
	}

	void addGetParts()
	{
		actions_.push_back(Action::GET_PARTS);
	}

	void addTest()
	{
		actions_.push_back(Action::TEST);
	}

	void addStop()
	{
		actions_.push_back(Action::STOP);
	}

	CookieRobotBuildable & GetRobot()
	{
		robot_.LoadActions(actions_);
		return robot_;
	}
};

int main()
{
	IRobotBuilder * builder = new CookieRobotBuilder("Jef");

	builder->addStart();
	builder->addGetParts();
	builder->addAssemble();
	builder->addTest();
	builder->addStop();

	IRobotBuildable & robot = builder->GetRobot();

	cout << "robot name : " << robot.GetName() << endl;
	robot.Go();

	delete builder;
}