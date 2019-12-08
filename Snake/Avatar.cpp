#include "Avatar.h"
using namespace std;
Avatar::Avatar(void)
{

}
Avatar::~Avatar()
{
	delete name;
	delete liczbapkt;
	delete trudnosc;
	
}
void Avatar::ustawieniepoziomu(int i)
{
	if (i == 1)
	{
		*trudnosc = latwy;
	}
	else if (i == 2)
	{
		*trudnosc = sredni;
	}
	else if (i == 3)
	{
		*trudnosc = trudny;
	}

}
