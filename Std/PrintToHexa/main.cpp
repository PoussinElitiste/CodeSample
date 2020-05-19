#include <iostream>
using std::cout;
using std::cin;
using std::endl;

const long MASK = 1;
const char LOW = 0x00FF;
const char HIGH = 0xFF00;

const char * hexValue = "0123456789ABCDEF";

char ConvertToHex(long value)
{
	return hexValue[value & 0x0F];	
}


int main()
{
	long value = -32;
	cout << "size_t " << sizeof(size_t) << endl;
	cout << "char " << sizeof(char) << endl;
	cout << "short " << sizeof(short) << endl;
	cout << "int " << sizeof(int) << endl;
	cout << "long " << sizeof(value) << endl;
	cout << std::hex << value << endl; 

	if (value < 0){
		value = ~value + 1;
		cout << "-";
	}

	size_t lng = sizeof(value)<<1;
	long quartet;

	for(int i=lng; i>0; --i)
	{
		quartet = (value >> ((i-1) << 2) ) & 0x0F;
		cout << hexValue[quartet];
	}
}