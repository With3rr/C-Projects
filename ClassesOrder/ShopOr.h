#pragma once
#include <iostream>
#include <cstdlib>
using namespace std;
class ShopItemOrder
{
private:
	string name;
	int price;
	int num;
public:
	ShopItemOrder(string, int, int);
	int getprice();
	void print();
};

