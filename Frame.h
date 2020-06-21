#pragma once
#include <string>
#include <iostream>

using namespace std;


class Frame
{
	string mod;
	string function;
	string value;
	string wyswietl;

public:
	//Frame(string _mod, string _function, string _value);
	void getFrame(string _wyswietl);
};

