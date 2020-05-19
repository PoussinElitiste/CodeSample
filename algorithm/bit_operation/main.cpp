#include <iostream>
using std::cin;
using std::cout;
using std::endl;

const unsigned int MASK = 1;

int CompterBit(unsigned int val)
{
	int cpt = 0;
	while (val)
	{
		//if (val & MASK) ++cpt ;
		cpt += val & MASK;
		val = val >> 1;
	}
	return cpt;
}

int main()
{
	unsigned int val = 1;

	while (val)
	{
		cout << "Entrez une valeur(0 pour quitter) : ";
		cin >> val;

		cout << "nombre de bit : " << CompterBit(val) << endl;
	}
}