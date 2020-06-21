#include <string>
#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

using namespace std;

int SPEED = 50;
float LONGITUDE = 14.552;
float LATITUDE = 53.428;
int HEIGHT = 25;
int ITER = 0;
int GEAR = 0;


/*template <typename T>
std::string NumberToString(T Number)
{
	std::ostringstream ss;
	ss << Number;
	return ss.str();
}*/




string engine()
{
	string st = "01";
	st += "001";

	int randSpeed = rand() % 10 + -4;
	SPEED = SPEED + randSpeed;
	//st += "\n" + NumberToString(SPEED);

	if (SPEED > 120)
	{
		SPEED = SPEED - 20;
	}
	else if (SPEED < 20)
	{
		SPEED = SPEED + 10;
	}
	else
	{
		SPEED = SPEED + randSpeed;
	}

	st += "0000" + to_string(SPEED);
	return st;
}

string gear_indicator()
{
	string st = "01";
	st += "020";

	if (SPEED <= 10)
	{
		GEAR = 1;
	}
	else if (SPEED <= 30)
	{
		GEAR = 2;
	}
	else if (SPEED <= 45)
	{
		GEAR = 3;
	}
	else if (SPEED <= 65)
	{
		GEAR = 4;
	}
	else if (SPEED <= 121)
	{
		GEAR = 5;
	}
	else
	{
		GEAR = 0;
	}

	st += "00000" + to_string(GEAR);
	return st;
}

string comfort()
{
	string st = "46";
	st += "010";

	int randComf = rand() % 30;
	if (randComf == 1)
	{
		st += "000001";
	}
	else
	{
		st += "000000";
	}

	return st;
}

string abs()
{
	string st = "03";
	st += "001";

	int randAbs = rand() % 100;
	if (randAbs == 1)
	{
		st += "000001";
	}
	else
	{
		st += "000000";
	}

	return st;
}

string hvac()
{
	string st = "08";
	st += "001";

	int randTemp = rand() % 24 + 18;


	st += "0000" + to_string(randTemp);

	return st;
	
}

string steeringWheel()
{
	string st = "16";
	st += "010";
	int randWheel = rand() % 20;

	st += "0000" + to_string(randWheel) + "°";


	return st;
}

string navi()
{
	string st = "37";
	st += "001";
	//st += "0000" + NumberToString(HEIGHT);
	int randNavi = rand() % 20;
	if (randNavi < 10)
	{
		st += "00001";
	}
	else
	{
		st += "00000";
	}
	return st;

}

string radio()
{
	string st = "56";

	st += "010";
	st += "000001";
	int randRadio = rand() % 10;
	if (randRadio < 9)
	{
		st += "000001";
	}
	else
	{
		st += "000000";
	}


	return st;
}

string centralLock()
{
	string st = "35";
	st += "001";
	if (SPEED < 16)
	{
		st += "000000";
	}
	else
	{
		st += "000001";
	}

	return st;
}

string readCANNetwork()
{
	string res = "";

	switch (ITER)
	{
	case 0:
		res = engine();
		break;
	case 1:
		res = comfort();
		break;
	case 2:
		res = abs();
		break;
	case 3:
		res = hvac();
		break;
	case 4:
		res = steeringWheel();
		break;
	case 5:
		res = navi();
		break;
	case 6:
		res = radio();
		break;
	case 7:
		res = centralLock();
		break;

	default:
		break;

	}

	if (ITER < 7)
	{
		ITER++;
	}
	else
	{
		ITER = 0;
	}


	return res;
}

/*
dummy CAN FRAME SPECIFICATION
2 bits - MODULE
4 bits - Function
6 bits - value

|----|-------|-------------|
|2   | 3     | 6           |
|1 1 | 1 1 1 | 1 1 1 1 1 1 |
|Mod | Funct.| Value       |
|----|-------|-------------|
'''
'''
01 ENGINE
*Functionality:
010 - speed
020 - gear indicator
*Value
according to selected functionality

46 COMFORT
010 - Windows
100 - Mirrors

03 ABS (module)
001 ABS
010 ESP
100 TC

08 HVAC
001 - Temp
010 - Fan speed
100 - Zone

16 STEERING
001 - Rotation (degree)
010 - Mode (Race, Comfort, Auto)

37 NAVIGATION
001 - Height above see level
010 - Latitude
020 - Longitude
100 - number of satelites

56 RADIO
010 - Band (AM/FM)
050 - Current Frequency
100 - RDS

35 CENTRAL LOCK
001 - door lock status
*/