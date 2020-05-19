//#include <Windows.h>
#include <ctime>
#include <algorithm>
using std::for_each;
#include <iostream>
using std::cout;
using std::endl;

//#include "Mutex.h"
#include "Autoverrou.h"

unsigned long __stdcall ChicThread(void *);

//HANDLE ChicMutex; //1.

//struct ThreadData
//{
//	int * donnee_;
//	int index_;
//
//	//HANDLE * mutex_; //2.
//	Mutex * mutex_; //3.
//};

class ThreadData
{
	int * donnee_;
	int index_;
	static Mutex  mutex_;

public:
	ThreadData() throw()
		:donnee_(0), index_(0)
	{}
	
	void Initialiser(int * donnee, const int index)
	{
		donnee_ = donnee;
		index_ = index;
	}

	~ThreadData() throw()
	{
	}

	bool Operation()
	{
		bool resultat = true;

		//Premet de ne pas bloquer le thread
		/*if (mutex_.Obtenir(0))
		{
			*(donnee_) = rand() % (index_ + 1);
			if (!*(donnee_))
			{
				cout << "thread #" << index_ << "; arret" << endl;
				cout << "datas :" << *(donnee_) << endl;
				resultat = false;
			}
			mutex_.Relacher();
		}*/
		
		Autoverrou av(mutex_); //Bloc le thread
		*(donnee_) = rand() % (index_ + 1);
		if (!*(donnee_))
		{
			cout << "thread #" << index_ << "; arret" << endl;
			cout << "datas :" << *(donnee_) << endl;
			resultat = false;
		}

		Sleep(1); // pour controler le rafraichissement
		return resultat;
	}
};

Mutex ThreadData::mutex_;

int main()
{
	const int NB_THREAD = 10;
	HANDLE threadHandle[NB_THREAD];
	DWORD threadID[NB_THREAD];
	ThreadData threadDatas[NB_THREAD] ;

	//dedicated to be modify by all threads via threadDatas
	int donnee = 10, cpt;

	//par defaut srand(1)
	srand(static_cast<unsigned int>(time(0)));

	//on n'a besoin que d'un seul mutex
	//ChicMutex = CreateMutex(0,FALSE,0); //1.
	//HANDLE ChicMutex = CreateMutex(0,FALSE,0); //2.
	//Mutex ChicMutex; //3.

	for (cpt=0; cpt<NB_THREAD; ++cpt)
	{
		//threadDatas[cpt].donnee_ = &donnee;//is it necessary to use this technique?
		//threadDatas[cpt].index_ = cpt;
		//threadDatas[cpt].mutex_ = &ChicMutex; //2.
		threadDatas[cpt].Initialiser(&donnee, cpt);
		threadHandle[cpt] = CreateThread(0, 0, ChicThread, threadDatas+cpt, 0, threadID+cpt);
	}

	WaitForMultipleObjects(NB_THREAD, threadHandle, true, INFINITE);
	for_each(threadHandle, threadHandle+NB_THREAD, CloseHandle);
	//CloseHandle(ChicMutex); // 2.
}

unsigned long __stdcall ChicThread(void * p)
{
	const int ATTENTE_MS = 0; // temp d'attente -> on attend pas 
	ThreadData * datas = reinterpret_cast<ThreadData * >(p);
	bool continuer = true;

	do 
	{
		//rappel: on attend tjrs le jeton du mutex
		//HRESULT hr = WaitForSingleObject(ChicMutex, ATTENTE_MS); // 1.
		// HRESULT hr = WaitForSingleObject(*(datas->mutex_), ATTENTE_MS); 2.
		//if (SUCCEEDED(hr))
		//if (datas->mutex_->Obtenir(ATTENTE_MS))
		//{
		//	*(datas->donnee_) = rand() % (datas->index_ + 1);
		//	if (!*(datas->donnee_))
		//	{
		//		cout << "thread #" << datas->index_ << "; arret" << endl;
		//		cout << "datas :" << *(datas->donnee_) << endl;
		//		continuer = false;
		//	}
		//	//ReleaseMutex(ChicMutex); //1.
		//	//ReleaseMutex(*(datas->mutex_)); //2.
		//	datas->mutex_->Relacher();

		//	Sleep(1); // pour controler le rafraichissement
		//}
		continuer = datas->Operation();
	} while(continuer);
	return 0L;
}