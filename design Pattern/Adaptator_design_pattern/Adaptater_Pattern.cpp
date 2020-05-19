//-----------------------------------------------
//|				|	Adaptator	|				|	
//| existing	----			----	new		|
//|	Interface	 *	|			 :	| interface	|
//|					|			----			|
//|				----			|				|
//|				|				|				|
//-----------------------------------------------

#include <string>
using std::string;
#include <iostream>
using std::cout;
using std::endl;

//interface existente
class ExistingInterface
{
public:
	virtual void SetName(const string & name) = 0; 
	virtual const string & GetName() const = 0; 
};

class ExistingClass
	:public ExistingInterface
{
	string name_;

public:
	void SetName(const string & name)
	{
		name_ = name;	
	}

	const string & GetName() const
	{
		return name_;
	}

};

//nouvelle interface
class NewInterface
{
public:
	virtual void SetFirstName(const string & name) = 0; 
	virtual void SetLastName(const string & name) = 0; 
	virtual const string & GetFirstName() const = 0;
	virtual const string & GetLastName() const = 0; 
};

//Adaptator
class Adaptator
	:public NewInterface
{
	ExistingClass * existingObject_;

	string firstName_;
	string lastName_;

public:
	Adaptator(ExistingClass * object)
		:existingObject_(object)
	{
		const string & name = existingObject_->GetName(); // on considere que l'interface existente se charge du format du nom
		size_t pos = name.find(" "); //si pas trouve retourne string::npos == fin de la chaine pour la class string
		firstName_ = name.substr(0,pos);
		lastName_ = name.substr(pos+1,string::npos);
	}

	void SetFirstName(const string & name)
	{
		firstName_ = name;
	}

	void SetLastName(const string & name)
	{
		lastName_ = name;
	}

	const string & GetFirstName() const
	{
		return firstName_;
	}

	const string & GetLastName() const
	{
		return lastName_;
	}
};

int main()
{
	ExistingClass existingObject;
	existingObject.SetName("Jesus Christ");

	cout << "existing Object : " << existingObject.GetName() << endl;

	Adaptator adaptator(&existingObject);
	cout << "first name: " << adaptator.GetFirstName() << endl << "last name: " << adaptator.GetLastName() << endl;
}