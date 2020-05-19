#ifndef MEDIATOR_H
#define MEDIATOR_H

#include <string>
using std::string;

class Welcome;
class Shop;
class Purchase;
class Exit;

class Mediator
{
	Welcome		* welcome_;
	Shop		* shop_;
	Purchase	* purchase_;
	Exit		* exit_;

public:
	Mediator();
	void Handle(const string & state);

	//start point
	Welcome & GetWelcome() const;
};
#endif

