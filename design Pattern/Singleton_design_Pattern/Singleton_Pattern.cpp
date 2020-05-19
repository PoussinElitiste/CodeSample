// Description:
// Test que 2 threads ne peuvent recuperer qu'un seul singleton

#include <iostream>
using std::cout;
using std::endl;
#include <string>
using std::string;
#include "Autoverrou.h"

unsigned long __stdcall testSingletonThread1(void *);
unsigned long __stdcall testSingletonThread2(void *);

class Database
{
	string name_;
	int record_;

	static Mutex mutex_;
	//static Database * instance_;

	Database(string n)
		:name_(n), record_(0)
	{}

public:
	~Database()
	{
		//delete instance_;
	}

	/*static Database * GetInstance(string n)
	{
		Autoverrou av(mutex_);
		if (!instance_)
			instance_ = new Database(n);

		return instance_;
	}*/

	static Database * GetInstance(string n)
	{
		Autoverrou av(mutex_);
		static Database instance_(n);

		return &instance_;
	}

	string & GetName()
	{
		return name_;
	}
};

//Database * Database::instance_ = 0;
Mutex Database::mutex_;

int main()
{
	/*Database * database;

	database = database->GetInstance("Product");
	cout << "database name : " << database->GetName() << endl;

	database = database->GetInstance("client");
	cout << "database name : " << database->GetName() << endl; */

	HANDLE threadHdl1 = CreateThread(0,0,testSingletonThread1,0,CREATE_SUSPENDED,0);
	HANDLE threadHdl2 = CreateThread(0,0,testSingletonThread2,0,CREATE_SUSPENDED,0);

	
	//Sleep(5);//on attend avant d ecrire pour ne pas polluer cout
	ResumeThread(threadHdl1);
	ResumeThread(threadHdl2); //pour lancer le thread suspendu
	
	WaitForMultipleObjects(1, &threadHdl2, true, INFINITE);
	WaitForMultipleObjects(1, &threadHdl1, true, INFINITE);

	CloseHandle(threadHdl1);
	CloseHandle(threadHdl2);
}

unsigned long __stdcall testSingletonThread1(void *)
{
	Database * database = database->GetInstance("Product"); 
	cout << "database name : " << database->GetName() << endl;

	return 0L;
}

unsigned long __stdcall testSingletonThread2(void *)
{
	Sleep(5);//pour creer expres un temps de retard
	Database * database = database->GetInstance("client"); //magie! il ne cree pas de nouveau singleton :)
	cout << "database name : " << database->GetName() << endl; 

	return 0L;
}