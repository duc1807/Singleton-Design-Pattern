#pragma once
#include<iostream>
#include<string>
#include <vector>
using namespace std;
#include "Database.h"
#include "Collection.h"
#include "Cart.h"

class Menu
{
protected:
	const int END = 0;
private:
	Database *database;
public:
	void run();
	int getChoice();
	virtual void action(const int &choice) = 0;
	virtual void showMenu() = 0;
};

class Program : public Menu
{
private:
	Database *database;
public:
	void showMenu();
	void action(const int &choice);
private:
	void addNewProduct();
	void showAll();
	void delProduct();
	void changePrice();
};

class CustomerProgram : public Menu
{
private:
	Database *database;
	void showMenu();
	void action(const int &choice);
public:
	Cart cusCart;
	void viewAll() const;
	void buy();
	void showCart();
	void removeProduct();
	void confirmBill();
};

