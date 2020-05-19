//
//
// |----------------|	action3	|---------------|
// | STATE 1		|<--------- | STATE 3		|
// |----------------|			|---------------|
//			|action1					^
//			|							|
//			V							|
// |----------------|		action2		|
// | STATE 2		|-------------------|
// |----------------|
//	
//							
// Automat
// |----------------|			|---------------|
// |  				|			| STATE 1		|
// ||-----------|	|			|---------------|
// || STATE		|	| <-------> | STATE 2		|
// || Action1()	|	|			|---------------|
// || Action2()	|	|			| STATE 3		|
// || Action3()	|	|			|---------------|
// ||-----------|	|
// |SetState()		|
// |----------------|			

#include <iostream>
using std::cout;
using std::endl;
#include <string>
using std::string;

#include "Automat.h"
#include "State.h"

int main()
{
	Automat automat;

	//sequence
	automat.Action1();
	automat.Action1();

	automat.Action2();
	automat.Action2();

	automat.Action3();
	automat.Action3();
}
