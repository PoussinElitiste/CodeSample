#ifndef THREAD_AUTONOME_H
#define THREAD_AUTONOME_H

#include <Windows.h>

class ThreadAutonome;

//typedef unsigned long (__stdcall *FunctionPtr)(void *); // thread must be defined outside the class or else it's no more generic
unsigned long (__stdcall ThreadGeneric)(void *);

//Allow starting and stopping at any time
class ThreadAutonome
{ 
	bool complete_;
	HANDLE threadHandle_;
	int sleepTime_;
	//FunctionPtr threadFunction_;

public:
	//interface
	virtual void Action() = 0;

	//for simulate construction and destruction in the thread
	virtual void Begin() = 0;
	virtual void End() = 0;

	ThreadAutonome( const int sleep = 0)//unsigned long (__stdcall *fctPtr)(void *),
		://threadFunction_(fctPtr), 
		sleepTime_(sleep), complete_(false)
	{}

	~ThreadAutonome()
	{
		Stop();
	}

	void Start()
	{
		DWORD id;
		//threadHandle_ = ::CreateThread(0, 0, *threadFunction_, this, 0, &id);
		threadHandle_ = ::CreateThread(0, 0, ThreadGeneric, this, 0, &id);
	}

	void Stop()
	{
		complete_=true; //permet de quitter la boucle du ThreadGeneric!
		{
			::WaitForSingleObject(threadHandle_, INFINITE);
			::CloseHandle(threadHandle_);
		}
	}

	bool GetComplete() const
	{
		return complete_;
	}

	void SetComplete()
	{
		complete_ = true;
	}

	int GetSleepTime() const
	{
		return sleepTime_;
	}
};

unsigned long (__stdcall ThreadGeneric)(void *p)
{
	ThreadAutonome *pA = reinterpret_cast<ThreadAutonome *>(p);

	pA->Begin(); //permet d'appeler des fonction COM(ex: ::CoCreateInstance()) avant d'executer l'action
	while(! pA->GetComplete())
	{
		pA->Action(); // notre interface!!
		::Sleep(pA->GetSleepTime());
	}
	pA->End(); //permet d'appeler des fonction COM(ex: ::Release()) en fin d'execution	
	
	return 0UL;
}

#endif