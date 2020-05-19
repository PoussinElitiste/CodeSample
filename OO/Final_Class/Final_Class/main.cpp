#include <iostream>
using std::cout;
using std::cin;
using std::endl;

class A
{
	A(){}

public:
	static A * GetA()
	{
		return new A();
	}
};

class B: public A
{
	int i;
};

int main()
{
	A * p = A::GetA();
	A * p1 = A::GetA();
}