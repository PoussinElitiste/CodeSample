#ifndef MUTEX_H
#define MUTEX_H

#include <Windows.h>

class Mutex
{
	HANDLE mutex_;

public:
	Mutex()
		:mutex_(CreateMutex(0, FALSE, 0))
	{

	}

	~Mutex()
	{
		CloseHandle(mutex_);
	}

	bool Obtenir(const int delai) const throw()
	{	
		return SUCCEEDED(WaitForSingleObject(mutex_, delai));
	}

	bool Obtenir() const throw()
	{
		return Obtenir(INFINITE);
	}

	void Relacher() const throw()
	{
		ReleaseMutex(mutex_);
	}
};

#endif