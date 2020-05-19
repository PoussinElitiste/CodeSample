#include <iostream>
using std::cout;
using std::endl;

struct X
{
	virtual ~X() = 0;
};

X::~X()
{
	cout << "class X" << endl;
};

struct Y : X
{
  ~Y() 
  {
	  cout << "class Y" << endl;
  } // Ok, Y n'est pas abstrait
};

struct W : X {}; // W est abstrait, à cause de X::~X()

int main()
{
  X *x = new Y;
  //Y *y = new Y;
  
  delete x; // boum!

  x = new W;
  delete x;
}