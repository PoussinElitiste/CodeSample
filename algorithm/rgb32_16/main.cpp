#include <iostream>
using std::cout;
using std::endl;

long RGBA_To_Long(char r, char g, char b, char a = 0)
{
	long rgb32 = (r << 24) | (g << 16) | (b << 8) | a;
	return rgb32;
}

short convert_RGB32_to_16(const long rgb)
{
	char r = (rgb >> 24)& 0x1F;
	char g = (rgb >> 16)& 0x3F;
	char b = (rgb >> 8)& 0x1F;

	cout << " r : " << short(r) << " g : " << short(g) << " b : " << short(b) << endl;
	return (r << 11) | (g << 5) | (b);
}

int main()
{
	cout << "sizeof(char)" << sizeof(char) << endl; 
	cout << "sizeof(char)" << sizeof(long) << endl;
	cout << "sizeof(char)" << sizeof(int) << endl;
	cout << "sizeof(char)" << sizeof(short) << endl; 

	long rgb32 = RGBA_To_Long(31, 63, 31);
	short rgb16 = convert_RGB32_to_16(rgb32);

	short r = (rgb16 >> 11) & 0x1F;
	short g = (rgb16 >> 5) & 0x3F;
	short b = (rgb16) & 0x1F;

	cout << " r : " << r << " g : " << g << " b : " << b << endl;

}