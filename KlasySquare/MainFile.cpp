#include <iostream>
#include <cstdlib>
#include<windows.h>
#include "Square.h"
using namespace std;



int main()
{
	Square s1(5);
	s1.set_side(3);
	s1.print();
	return 0;
}
