#include "ShopItemOrder.h"
#include <iostream>
#include <cstdlib>
using namespace std;
ShopItemOrder::ShopItemOrder(string name, int price , int num)
{
	this->name = name;
	this->price = price;
	this->num = num;
}

int ShopItemOrder::getprice()
{
	return price * num;
}
void  ShopItemOrder::print()
{
	
	cout << "You bought" << num << "x   " << name << " " << price << "$ each";
}
