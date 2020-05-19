#include <vector>
using std::vector;
#include <algorithm>
using std::find;
using std::for_each;

class Subject
{
public:
	virtual void RegisterObserver(Observer * o) = 0;
	virtual void UnregisterObserver(Observer * o) = 0;
	virtual void NotifyObservers() = 0;
};

class Database
	:public Subject
{
	vector<Observer *> observers_;

	string operation_;
	string record_;

	void NotifyObservers()
	{
		for_each(observers_.begin(), observers_.end(), Fctr(operation_, record_));
	}

public:
	void RegisterObserver(Observer * o)
	{
		observers_.push_back(o);
	}

	void UnregisterObserver(Observer * o)
	{
		observers_.erase(find(observers_.begin(), observers_.end(), o));
	}

	// created for for_each function
	struct Fctr
	{
		string & oper_;
		string & rec_;

		Fctr(string & oper, string & rec)
			:oper_(oper), rec_(rec)
		{}

		void operator()(Observer * o)
		{
			o->Update(oper_, rec_);
		}
	};

	// service allowing notification process
	void EditRecord(string operation, string record) 
	{
		operation_ = operation;
		record_ = record;
		NotifyObservers();
	}
};