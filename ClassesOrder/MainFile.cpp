#include <iostream>
#include <cstdlib>
#include "ShopItemOrder.h"
using namespace std;

int main()
{
	ShopItemOrder s1("souce", 2, 20);
	cout<<s1.getprice()<<endl;
	s1.print();
	return 0;
}
