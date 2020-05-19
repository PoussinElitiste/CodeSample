#ifndef TEST_TEMPLATE
#define TEST_TEMPLATE

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

template<class T>
class MyPair
{
private:
	T a_, b_;
public:
	MyPair(T a, T b);
	T GetMAx();
};

template<class T>
MyPair<T>::MyPair(T a, T b)
:a_(a), b_(b)
{
}

template<class T>
T MyPair<T>::GetMAx()
{
	return a_>b_?a_:b_;
}

int main()
{
	int a, b;

	volatile bool loop=true;

	while (loop)
	{
		cout << "A: ";
		cin >> a;

		cout << "B: ";
		cin >> b;
		MyPair<int> pairValue(a, b);
		cout << "Max value : " << pairValue.GetMAx() << endl;
	}
}

#endif