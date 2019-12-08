#pragma once
#include <string>
using namespace std;

class Avatar
{
public:

	string* name=new string,*haslo=new string;
	int* liczbapkt=new int;
	enum poziomTrudn
	{
		latwy,
		sredni,
		trudny
	} *trudnosc=new poziomTrudn;
	
	
	Avatar(void);
	~Avatar();
	friend void wybierz(Avatar *a);
	friend void opcje(Avatar *s);
	void ustawieniepoziomu(int i);


};
