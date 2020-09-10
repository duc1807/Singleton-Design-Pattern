#include "pch.h"
#include "Cart.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void Cart::addProduct(Product product)
{
	cart.push_back(product);
}

void Cart::display()
{
	cout << endl;
	cout << "************** Your Cart **************" << endl;
	cout << "No.	 Product Name		Price" << endl;
	cout << endl;
	for (int i = 0; i < cart.size(); i++)
	{
		cout << i + 1 << ".	 " << cart[i].getName() << "		 " << cart[i].getPrice() << endl;
	}
	cout << endl;
}

void Cart::removeProduct(const int &num)
{
	if (num - 1 >= cart.size())
	{
		cout << "Invalid!!!";
		cout << endl;
	}
	else
	{
		cart.erase(cart.begin() + (num - 1));
		cout << "Product no." << num << " is removed from your cart." << endl;
	}
}

int Cart::getTotal() const
{
	int total = 0;
	for (int i = 0; i < cart.size(); i++)
	{
		total += cart[i].getPrice();
	}
	return total;
}

bool Cart::isEmpty()
{
	for (int i = 0; i < cart.size(); i++)
	{
		size++;
	}
	if (size == 0) return true;
	else return false;
}

Cart::~Cart()
{
}
