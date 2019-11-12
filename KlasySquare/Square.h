#pragma once
#include <iostream>
#include <cstdlib>
#include<windows.h>
using namespace std;
class Square
{
private:
	double side;
	double area;
	
public:
	Square(double);
	void set_side(double);
	void print();
	
};

