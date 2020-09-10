#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Product.h"
using namespace std;

class Cart
{
	vector<Product> cart;
	int size;
public:
	void addProduct(Product product);
	void display();
	void removeProduct(const int &num);
	int getTotal() const;
	bool isEmpty();
	~Cart();
};

