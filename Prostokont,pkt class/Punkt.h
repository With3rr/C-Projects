#pragma once
#include <iostream>
using namespace std;
class Prostokont;
class Punkt
{
	string nazwa;
	float x, y;
public:
	Punkt(string = "A", float = 0, float = 0);
	void wczytaj();
	friend void sedzia (Punkt& pkt, Prostokont& p);
};
