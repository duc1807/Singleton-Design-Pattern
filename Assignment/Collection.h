#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Product.h"
using namespace std;

class Collection
{
private:
	string name;
public:
	vector<Product> products;
	Collection(string name);
	void addNewProduct(const string &name, const string &code, const int &price);
	void setPrice(const string &code, const int &price);
	void showProInfo(const string &code);
	string getName() const;
	void print();
	void deleteProduct(const int &num);
	bool isEmpty();
	int getSize();

	Product getProduct(const int &proNum);

	~Collection();
};

