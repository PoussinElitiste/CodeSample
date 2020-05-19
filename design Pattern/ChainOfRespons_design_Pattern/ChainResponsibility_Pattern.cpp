// definit qui est le responsable en fct du message
// |--------|
// | IHelp	|
// |--------|
//		^
//		|
// |------------|		|-----------|		|-----------|
// | FrontEnd	|		| InterLayer|		| Applic.	|
// ||-------|	|		||-------|	|		||-------|	|
// || IHelp	| <------->	|| IHelp | <------>	|| IHelp |  |
// ||-------|	|		||-------|	|		||-------|	|
// |------------|		|-----------|		|-----------|


#include <iostream>
using std::cout;
using std::endl;

enum HelpConstant
{
	FRONT_END_HELP = 1,
	INTERMEDIATE_LAYER_HELP = 2,
	GENERAL_HELP = 3
};

class HelpInterface
{
public:
	virtual void GetHelp(HelpConstant helpConstant)=0;
};

class FrontEnd
	:public HelpInterface
{
	HelpInterface * successor_;

public:
	FrontEnd(HelpInterface * s)
	{
		successor_ = s;
	}
	
 void GetHelp(HelpConstant helpConstant)
 {
	 if (helpConstant!= FRONT_END_HELP)
		successor_->GetHelp(helpConstant);
	 else
		 cout << "This is the front end" << endl;
 }
};

class IntermediateLayer
	:public HelpInterface
{
	HelpInterface * successor_;

public:
	IntermediateLayer(HelpInterface * s)
	{
		successor_ = s;
	}

	void GetHelp(HelpConstant helpConstant)
	{
		if (helpConstant != INTERMEDIATE_LAYER_HELP)
			successor_->GetHelp(helpConstant);
		else
			cout << "This is the intermediate Layer" << endl;
	}
};

class Application
	:public HelpInterface
{
	HelpInterface * successor_;

public:
	Application()
	{}

	void GetHelp(HelpConstant helpConstant)
	{
		cout << "This is the MagaGigaCo Application" << endl;
	}
};

int main()
{
	Application application;

	IntermediateLayer intermediataLayer(&application);
	FrontEnd frontEnd(&intermediataLayer);

	frontEnd.GetHelp(GENERAL_HELP);
	frontEnd.GetHelp(INTERMEDIATE_LAYER_HELP);
	frontEnd.GetHelp(FRONT_END_HELP);
}