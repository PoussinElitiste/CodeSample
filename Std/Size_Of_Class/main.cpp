#include <stdio.h>
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

class A
{
	virtual void fct() = 0;
};

class C: A
{
	int i;
	double k;

public:
	C():i(1), k(2.5){}
	void fct(){
		int i=2;
	}
};

int main(void)
{
	size_t size = (size_t)(static_cast<C *>(0) + 1);

	C * obj = new C();
	memset((void *)obj, 0, size);

	cout << "size of:" << size << endl;

	return 0;
}