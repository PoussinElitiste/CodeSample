// pilotage a distance
// |--------------------|
// | client				|
// | |--------------|	|			|---------------|
// | |Automat Proxy	| <------------>|Automat Server	|
// | |--------------|	|			|---------------|
// |--------------------|
#include <winsock2.h>
#include "ThreadAutonome.h"
#include "IAutomat.h"
#include "Autoverrou.h"
#include "State.h"

#include <iostream>
using std::cout;
using std::endl;

class Thread
	:public ThreadAutonome
{
	Mutex & mutex_;

public:
	Thread(Mutex & mutex, const int sleep = 0)
		:ThreadAutonome(sleep), mutex_(mutex)
	{}

	// equivalent au constructeur/destructeur
	void Begin()
	{
		Autoverrou av(mutex_);
		cout << "Thread: Begin" << endl;
	}

	void End()
	{
		Autoverrou av(mutex_);
		cout << "Thread: End" << endl;
	}

	void Action()
	{
		Autoverrou av(mutex_);
		cout << "Thread: hello world" << endl;
		SetComplete();//permet de quitter la boucle du ThreadGeneric
	}
};

class AutomatServer
	:IAutomat
{
	IState * stateA_;
	IState * stateB_;
	IState * stateC_;
	IState * currentState_;
	Thread serverThread_;
	// to do

public:
	AutomatServer(Mutex & mutex, const int sleep = 0)
		:stateA_(new StateA(this)),
		stateB_(new StateB(this)),
		stateC_(new StateC(this)),
		currentState_(stateA_),
		serverThread_(mutex, sleep)
	{}

	~AutomatServer()
	{
		delete stateA_;
		delete stateB_;
		delete stateC_;
	}
};

class AutomatProxy
	:IAutomat
{
	
};

int main()
{
	Mutex mutex;
	Thread server(mutex, 10);
	Thread proxy1(mutex, 10);
	//Thread proxy2(mutex, 10);

	//pas besoin de faire stop car Thread Autonome en RAII
	server.Start();
	proxy1.Start();
	//proxy2.Start();

	::Sleep(server.GetSleepTime() + 100); //pour laisser tourner les threads au moins une fois
}