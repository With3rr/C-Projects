#pragma once
#include <string>
using namespace std;

class Avatar
{
private:

	string *name;
	int *liczbapkt;
	enum poziomTrudn
	{
		latwy,
		sredni,
		trudny
	} *trudnosc;
	string *jezyk;
	Avatar(string, int, poziomTrudn, string);
	~Avatar();


};

