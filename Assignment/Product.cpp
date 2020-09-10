#include "pch.h"
#include "Product.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

Product::Product(string name, string code, int price)
{
	this->name = name;
	this->code = code;
	this->price = price;
}

void Product::print()
{
	cout << "Product Name: " << name << endl;
	cout << "Barcode: " << code << endl;
	cout << "Price: " << price << endl;
}

string Product::getCode()
{
	return code;
}

void Product::changePrice(const int &price)
{
	this->price = price;
	cout << "The price of " << name << " changed to " << price << "." << endl;
}

string Product::getName()
{
	return name;
}

int Product::getPrice() const
{
	return price;
}

/*
void Product::display()
{
	cout << "Product: " << name << endl;
	cout << "Price: " << price << endl;
}
*/




