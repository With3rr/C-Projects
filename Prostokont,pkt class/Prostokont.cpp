#include "Prostokont.h"
#include <iostream>
using namespace std;

Prostokont::Prostokont(string n, float xx, float yy, float szer, float wys)
{
	nazwa = n;
	x = xx;
	y = yy;
	szerokosc = szer;
	wysokosc = wys;

}
void Prostokont::wczytaj()
{
	cout << "Podaj nazwe pkt: ";
	cin >> nazwa;
	cout << "Podaj x: ";
	cin >> x;
	cout << "Podaj y";
	cin >> y;
	cout << "Podaj szerokosc: ";
	cin >> szerokosc;
	cout << "Podaj wysokosc: ";
	cin >> wysokosc;
	
}
