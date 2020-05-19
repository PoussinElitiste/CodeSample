// decision machine: all State comunicate only with mediator
// |----------------|			|---------------|
// |	Welcome		|			|	Shop		|
// |		Go()	|			|		Go()	|
// |----------------|			|---------------|
//			A							A
//			|							|
//			V							V
//		|-----------------------------------|
//		|			Mediator				|
//		|				Handle()			|
//		|-----------------------------------|
//			A							A
//			|							|
//			V							V
// |----------------|			|---------------|
// |	Purchase	|			|	Goodbye		|
// |		Go()	|			|		Go()	|
// |----------------|			|---------------|

#include <iostream>
using std::cout;
using std::cin;
using std::cerr;
using std::endl;
#include <string>
using std::string;

#include "State.h"
#include "Mediator.h"

int main()
{
	Mediator mediator;
	mediator.GetWelcome().Go();
}