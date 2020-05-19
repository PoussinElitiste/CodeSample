#include "Mutex.h"

class Autoverrou
{
	Mutex & mutex_;

public:
	Autoverrou(Mutex & mutex)
		:mutex_(mutex)
	{
		//mutex_.Obtenir();//bloc le thread
		mutex_.Obtenir(0);//ne bloc pas le thread
	}

	~Autoverrou()
	{
		mutex_.Relacher();
	}
};