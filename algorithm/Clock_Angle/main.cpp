#include <iostream>
using std::cout;
using std::cin;
using std::endl;

// minute_deg = minute * 360 / 60 = minute * 6; 
// The hour hand will make a complete revolution every hour, so its formula is: 
// hour_deg = hour * 360 / 12 = hour * 30; 

int ClockAngle(int hr, int min) 
{ 
	int angle = hr * 30 - min * 6; 

	if(angle > 180) 
		angle = 360 - angle; 

	return(angle); 
}

int main()
{
	int hour, min;
	
	char loop = 'y';
	
	while ( loop != 'n')
	{
		cin >> hour;
		cin >> min;
		cout << "time	: " << hour << " hr " << min << " min" << endl;
		cout << "angle	: " << ClockAngle(hour, min) << " degree" << endl;

		cout << "continue (Y/N) ? ";
		cin >> loop;	
	}

	return 0;
}
