#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <sstream>;
using std::stringstream;
#include <string>;
using std::string;

string CompressChars(const string & text)
{
	stringstream result;
	const char * start = text.c_str();
	const int len = text.length();
	const char * p, * head = start;

	for ( p = start; p != start+len; ++p )
	{
		if (*p != *head)
		{
			result << p-head << *head;
			head = p;
		}
	}
	result << p-head << *head;

	return result.str();
}


int main()
{
	//string resultat;
	string text;

	while(text != "q")
	{
		cout << "entrez une chaine de caractere : ";
		cin >> text;

		cout << CompressChars(text) << endl;
	}
}
