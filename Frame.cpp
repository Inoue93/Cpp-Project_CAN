#include <string>
#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

using namespace std;
#include "Frame.h"

//Frame::Frame(string _mod, string _function, string _value)
void Frame:: getFrame(string _wyswietl)
{
	wyswietl = _wyswietl;
	string str1 = wyswietl.substr(0, 2);
	string str2 = wyswietl.substr(2, 3);
	string str3 = wyswietl.substr(5, 7);
	

	if (str1 == "01")
	{
		if (str2 == "001" )
		
		{
			str2 == "Prêdkoœæ:  ";
		}
		else if (str2 == "020")
		{
			str2 == "Bieg:  ";
		}
	}
	
	if (str1 == "46")
	{
		str1 = "Komfort:  ";
	}

	if (str1 == "03")
	{
		str1 = "ABS:  ";
		if (str3 == "000001")
		{
			str3 == "W³¹czone";
		}
		else if (str3 == "000000")
		{
			str3 == "Wy³¹czone";
		}
	}

	if (str1 == "08")
	{
		str1 = "HVAC:  ";
	}

	if (str1 == "16")
	{
		str1 = "Kierownica:  ";
	}

	if (str1 == "37")
	{
		str1 = "Nawigacja:  ";
		if (str3 == "00001")
		{
			str3 == "W³¹czona";
		}
		else if (str3 == "00000")
		{
			str3 == "Wy³¹czona";
		}
	}

	if (str1 == "56")
	{
		str1 = "Radio:  ";
		if (str3 == "00001")
		{
			str3 == "W³¹czona";
		}
		else if (str3 == "00000")
		{
			str3 == "Wy³¹czona";
		}
	}

	if (str1 == "35")
	{
		str1 = "Zamek centralny:  ";
		if (str3 == "00001")
		{
			str3 == "W³¹czona";
		}
		else if (str3 == "00000")
		{
			str3 == "Wy³¹czona";
		}
	}


	cout << str1 << " " << str2 << " " << str3 << " :: " << endl;
}
