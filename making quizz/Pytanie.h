#include <iostream>
#pragma once
using namespace std;
class Pytanie
{
public:
	string tresc;
	string a, b, c, d;
	string poprawnaOdp;
	int nr_pytania;
	string odpowiedz;
	int punkt;
	int punkty;

	void wczytaj();
	void zadaj();
	void sprawdz();
	
};

