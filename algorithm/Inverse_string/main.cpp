#include <iostream>
using std::cout;
using std::endl;
#include <string.h>

// v1
char * InverseString(const char * str1)
{
	size_t ln = strlen(str1);
	char * p2, * str2 = new char[ln];
	const char * p1;

	p1 = str1 + ln - 1;
	p2 = str2;

	while(p1 >= str1)
		*p2++ = *p1--;

	*p2 = '\0';
	return str2;
}

// v2
void InverseString(char * str)
{
	size_t ln = strlen(str); 
	int loop =  ln >> 1;
	char * p1 = str + ln - 1;

	for (int i=0; i < loop; ++i)
	{
		*str ^= *p1;
		*p1 ^= *str;
		*str++ ^= *p1--;
	}
}

int main(void)
{
	const char * str1 = "Pointers are fun and hard to use";
	char * str2 = InverseString(str1);

	cout << str1 << endl << str2 << endl;

	char str3[] = "Hello World";
	cout << str3 << endl;
	InverseString(str3);
	cout << str3 << endl;

	return 0;
}