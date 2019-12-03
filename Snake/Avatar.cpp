#include "Avatar.h"
using namespace std;

Avatar::Avatar(string aName, int aLiczba, poziomTrudn aPoziom, string ajezyk)
{
	name = new string;
	liczbapkt = new int;
	trudnosc = new poziomTrudn;
	jezyk = new string;
	
	*name = aName;
	*liczbapkt = aLiczba;
	*trudnosc = aPoziom;
	*jezyk = ajezyk;
}
