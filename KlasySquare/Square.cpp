#include "Square.h"
#include <iostream>
#include <cstdlib>
#include<windows.h>
using namespace std;


Square::Square(double side)
{
	this->side = side;
	this->area = side * side;
}
void Square::set_side(double x)
{
	if (x > 0)
	{
		side = x;
		area = x * x;
	}

}
void Square::print()
{
	cout<<"Square: side="<<side<< " area="<<area << endl;
}

