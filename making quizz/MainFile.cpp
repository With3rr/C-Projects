#include "Pytanie.h"
#include <iostream>
using namespace std;

int main()
{
	Pytanie p[5];
	int suma=0;
	for (int i = 0; i <= 4; i++)
	{
		p[i].nr_pytania = i+1;
		p[i].wczytaj();
		p[i].zadaj();
		p[i].sprawdz();
		suma += p->punkt;

	}
	


	cout << "Koniec quizu! punkty =" << suma;


	return 0;
}
