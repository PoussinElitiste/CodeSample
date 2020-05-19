#include "ThreadAutonome.h"
#include "Autoverrou.h"
#include <iostream>
using std::cout;
using std::endl;

class ServerThread
	:public ThreadAutonome
{
	Mutex & mutex_;

public:
	ServerThread(Mutex & mutex, const int sleep = 0)
		:ThreadAutonome(sleep), mutex_(mutex)
	{}

	// equivalent au constructeur/destructeur
	void Begin()
	{
		Autoverrou av(mutex_);
		cout << "ServerThread: Begin" << endl;
	}

	void End()
	{
		Autoverrou av(mutex_);
		cout << "ServerThread: End" << endl;
	}

	void Action()
	{
		Autoverrou av(mutex_);
		cout << "ServerThread: hello world" << endl;
		SetComplete(); //permet de quitter la boucle du ThreadGeneric
	}
};

class ProxyThread
	:public ThreadAutonome
{
	Mutex & mutex_;
public:
	ProxyThread(Mutex & mutex, const int sleep = 0)
		:ThreadAutonome(sleep), mutex_(mutex)
	{}

	// equivalent au constructeur/destructeur
	void Begin()
	{
		Autoverrou av(mutex_);
		cout << "ProxyThread: Begin" << endl;
	}

	void End()
	{
		Autoverrou av(mutex_);
		cout << "ProxyThread: End" << endl;
	}

	void Action()
	{
		Autoverrou av(mutex_);
		cout << "ProxyThread: hello world" << endl;
		SetComplete();//permet de quitter la boucle du ThreadGeneric
	}
};

int main()
{
	Mutex mutex;
	ServerThread server(mutex, 10);
	ProxyThread proxy(mutex, 10);

	//pas besoin de faire stop car Thread Autonome en RAII
	server.Start();
	proxy.Start();

	::Sleep(server.GetSleepTime() + 10); //pour laisser tourner les threads au moins une fois
}