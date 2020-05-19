#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <string>
using std::string;

#include <assert.h>
#include "static_assert.h"

#include <ctime>
using std::clock;
using std::clock_t;

void f()
{
	int val = 0;

	for(int i = 0; i<100; ++i)
	{
		++val; 
	}

}

int main()
{
	char chr = 'G';
	int val = 6;
	int val2 = 8;
	string text = "Hello";
	
	struct Test
	{
		int val_;
		long lng_;
	};

	int vals[] = {2,6,3,5};
	string txts[] = {"Hello", "World", "everybody"};

	cout << "char : " << sizeof(chr) << endl;
	cout << "int : " << sizeof(val) << endl;
	cout << "string : " << sizeof(text) << endl;
	cout << "struct : " << sizeof(Test) << endl;
	cout << "long : " << sizeof(long) << endl;
	cout << "short : " << sizeof(short) << endl;
	cout << "array : " << sizeof(vals) << endl;
	cout << "nb elem : " << sizeof(vals)/sizeof(int) << endl;
	cout << "nb elem : " << sizeof(txts)/sizeof(string) << endl;

	//assert(val<5);
	static_assert<(sizeof(short)<sizeof(int))> not_authorized;

	//calcul Time
	const int NB_TESTS = 100000; // choisi avec soin (!)
	int Cpt = 0;
	clock_t TempsTotal = 0,
		TempsMin   = 0,
		TempsMax   = 0;
	while (Cpt < NB_TESTS)
	{
		clock_t avant = clock();
		f();
		clock_t apres = clock();
		clock_t temps = apres - avant;
		if (temps >= 0)
		{
			TempsTotal += temps;
			if (!Cpt)
				TempsMin = TempsMax = temps;
			else
			{
				if (temps < TempsMin)
					TempsMin = temps;
				if (temps > TempsMax)
					TempsMax = temps;
			}
			++Cpt;
		}
	}

	double moyenne = TempsTotal / static_cast<double>(NB_TESTS);
	cout << "[ Statistiques pour un appel à f() ]" << endl
		<< "Temps minimal: " << TempsMin << ' ' << CLOCKS_PER_SEC << "iemes de seconde" << endl
		<< "Temps maximal: " << TempsMax << ' ' << CLOCKS_PER_SEC << "iemes de seconde" << endl
		<< "Temps moyen: "   << moyenne  << ' ' << CLOCKS_PER_SEC << "iemes de seconde" << endl;
}