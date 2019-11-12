#include "Punkt.h"
#include <iostream>
using namespace std;


Punkt::Punkt(string n, float xx, float yy)
{
	nazwa = n;
	x = xx;
	y = yy;

}
void Punkt::wczytaj()
{
	cout << "Podaj nazwe pkt: ";
	cin >> nazwa;
	cout << "Podaj x: ";
	cin >> x;
	cout << "Podaj y";
	cin >> y;
	

}
