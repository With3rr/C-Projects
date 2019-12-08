#include "Rkwadratowe.h"
#include <iostream>
using namespace std;

void Rkwadratowe::zamien(float aa, float bb, float cc)
{
	if (a == 0)
	{
		cout << "Niepoprawne A!!!!!!";
		this->a = 1;
	}
	else
	{
		this->a = aa;
		this->b = bb;
		this->c = cc;
	}
	oblicz();

}
void Rkwadratowe::oblicz()
{
	this->delta = (b*b) - (4 * a*c);
	if (delta > 0)
	{
		x1 = ((-b) - (sqrt(delta))) / (2 * a);
		x2 = ((-b) + (sqrt(delta))) / (2 * a);
	}
	else if (delta == 0)
	{
		x1 = ((-b) - (sqrt(delta))) / (2 * a);

	}

}
void Rkwadratowe::wypisz_pierwiastki()
{
	if (delta > 0)
	{
		cout << x1 << endl;
		cout << x2 << endl;

	}
	else if (delta == 0)
	{
		cout << x1;
	}
	else if(delta<0)
	{
		cout << "Nie ma rozwiazan zeczywistych";
	}

}
float Rkwadratowe::zwroc_delta(void)
{
	return delta;
}
