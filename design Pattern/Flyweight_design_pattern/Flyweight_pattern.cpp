// configuration a la volee d'un objet au lieu de creer plusieurs instances
// |------------|		|-----------|		|-----------|
// |			| <-->	| Config 1	| <-->	|			|
// |			|		|-----------|		| Flyweight	|
// |	Code	| <-->	| Config 2	| <-->	| Object	|
// |			|		|-----------|		|			|
// |			| <-->	| Config 3	| <-->	|			|
// |------------|		|-----------|		|-----------|

#include <string>
using std::string;
#include <algorithm>
using std::for_each;
#include <iostream>
using std::cout;
using std::endl;

class Student
{
	string name_;
	int id_;
	int score_;
	double classAverage_;

	Student(double avg)
		:classAverage_(avg)
	{}

public:
	static Student & GetSingleton(double avg)
	{
		static Student student_(avg); // necessaire pour obliger les threads a utiliser un seul objet 
		return student_;
	}

	void SetName(const string & name)
	{
		name_ = name;
	}

	void SetID(const int id)
	{
		id_ = id;
	}

	void SetScore(const int score)
	{
		score_ = score;
	}

	const string & GetName() const
	{
		return name_;
	}

	const int & GetId() const
	{ 
		return id_;
	}

	const int & GetScore() const
	{ 
		return score_;
	}

	double GetRanking()
	{
		return ((static_cast<double>(score_)/classAverage_) - 1.0) * 100.0;
	}
};

//Foncteur
struct Cumul
{
private:
	int & cumul_;

public:
	Cumul(int & cumul)
		:cumul_(cumul)
	{}

	void operator()(int data)
	{
		cumul_ += data;
	}
};

int main()
{
	//nos donnees de travail
	enum {NB_STUDENT=3};
	string names[] = {"Ralph", "Alice", "Sam"};
	int ids[] = {1001, 1002, 1003};
	int scores[] = {45, 55, 65};

	int cumul = 0;
	for_each(scores, scores + NB_STUDENT, Cumul(cumul));

	Student & student = Student::GetSingleton(cumul/NB_STUDENT);

	for (int i=0; i<NB_STUDENT; ++i)
	{
		student.SetName(names[i]);
		student.SetID(ids[i]);
		student.SetScore(scores[i]);

		cout 
			<< "name : " << student.GetName() << endl
			<< "ids : " << student.GetId() << endl
			<< "scores : " << student.GetScore() << endl
			<< "ranking : " << student.GetRanking() << endl
			<< endl; 
	}
}