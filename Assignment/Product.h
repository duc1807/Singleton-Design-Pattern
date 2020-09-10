#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Product
{
private:
	string name;
	string code;
	int price;
public:
	Product(string name, string code, int price);
	void changePrice(const int &price);
	void print();
	string getCode();
	string getName();
	int getPrice() const;
};

