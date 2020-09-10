#include "pch.h"
#include "Collection.h"


Collection::Collection(string name)
{
	this->name = name;
}

void Collection::addNewProduct(const string &name, const string &code, const int &price)
{
	Product pd(name, code, price);
	products.push_back(pd);
	cout << "Product " << name << " added to the category " << Collection::name << endl;
}

string Collection::getName() const
{
	return name;
}

void Collection::print()
{
	for (int i = 0; i < products.size(); i++)
	{
		cout << endl;
		cout << "Product " << i + 1 << ": " << endl;
		products[i].print();
		cout << endl;
	}
}

void Collection::setPrice(const string &code, const int &price)
{
	for (int i = 0; i < products.size(); i++)
	{
		if (code == products[i].getCode())
		{
			products[i].changePrice(price);
		}
	}
}

void Collection::showProInfo(const string &code)
{
	for (int i = 0; i < products.size(); i++)
	{
		if (code == products[i].getCode())
		{
			products[i].print();
		}
	}
}

void Collection::deleteProduct(const int &num)
{
	cout << "Product " << num << " deleted!" << endl;
	products.erase(products.begin() + (num - 1));
}

Product Collection::getProduct(const int &proNum)
{
	return products[proNum - 1];
}

bool Collection::isEmpty()
{
	if (products.size() == 0)
	{
		cout << "Empty!!!" << endl;
		return true;
	}
	else return false;
}

int Collection::getSize()
{
	int size;
	size = products.size();
	return size;
}


Collection::~Collection()
{
}
