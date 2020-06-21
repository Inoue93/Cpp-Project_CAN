#pragma once
#include <string>
#include <iostream>
#include <stdlib.h>
#include "cansim.h"
#include <cstdlib>
#include "Frame.h"

using namespace std;

int main()
{

	for (int i = 0; i < 100; i++)
	{
		//cout << " Prêdkoœæ |Aktualny bieg | ABS | HVAC | Temperatura | Modu³ samochodu | Nawigacja | " << endl;
		//cout << " ------------------------------------------------ " << endl;
		//cout << engine() << "|" << comfort() << "|" << abs() << "|" << hvac() << "|" << steeringWheel() << "|" << navi() << "|" << radio() << "|" << centralLock() << "|" << endl;
		Frame CAN;
		CAN.getFrame(readCANNetwork());

		
		system("cls");

	}

	//while (true)
	//{
	//	cout << readCANNetwork() << endl;
	//}

	int a = 0;

	cin >> a;

	return 0;
}