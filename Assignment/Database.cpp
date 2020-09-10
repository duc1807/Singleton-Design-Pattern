#include "pch.h"
#include "Database.h"
#include "Product.h"
#include "Collection.h"

Database *Database::database = 0;

Database::Database()
{
	Collection milk("milk");
	Collection food("food");
	Collection snack("snack");

	collections.push_back(milk);
	collections.push_back(food);
	collections.push_back(snack);
}


Database* Database::getDatabase()
{
	if (database == 0)
	{
		database = new Database();
	}
	return database;
}

void Database::addProduct(const string &type, const string &name, const string &code, const int &price)
{
	for (int i = 0; i < collections.size(); i++)
	{
		if (type == collections[i].getName())
		{		
			collections[i].addNewProduct(name, code, price);
		}
	}
}

void Database::showAll()
{
	for (int i = 0; i < collections.size(); i++)
	{
		cout << endl;
		cout << "***************| All products of " << collections[i].getName() << " |***************" << endl;
		collections[i].print();
		cout << endl;
	}
}

void Database::changePrice(const string &type, const string &code, const int &price)
{
	for (int i = 0; i < collections.size(); i++)
	{
		if (type == collections[i].getName())
		{
			collections[i].setPrice(code, price);
		}
	}
}

void Database::showProInfo(const string &type, const string &code)
{
	for (int i = 0; i < collections.size(); i++)
	{
		if (type == collections[i].getName())
		{
			collections[i].showProInfo(code);
		}
	}
}

void Database::showCollectionInfo(const string &type)
{
	for (int i = 0; i < collections.size(); i++)
	{
		if (type == collections[i].getName())
		{
			cout << "---------- All products of " << collections[i].getName() << " ----------" << endl;
			collections[i].print();
		}
	}
}

void Database::deleteProduct(const string &type, const int &num)
{
	for (int i = 0; i < collections.size(); i++)
	{
		if (type == collections[i].getName())
		{
			collections[i].deleteProduct(num);
		}
	}
}

Product Database::getProduct(const string &type, const int &proNum)
{
	for (int i = 0; i < collections.size(); i++)
	{
		if (type == collections[i].getName())
		{
			return collections[i].getProduct(proNum);
		}
	}
}

bool Database::isEmpty(const string & type)
{
	bool isFound = false;
	for (int i = 0; i < collections.size(); i++)
	{
		if (type == collections[i].getName())
		{
			return collections[i].isEmpty();
			isFound = true;
		}
	}
	if (isFound == false) cout << "Invalid category!" << endl;
}

int Database::getCollectionSize(const string &type)
{
	for (int i = 0; i < collections.size(); i++)
	{
		if (type == collections[i].getName())
		{
			return collections[i].getSize();
		}
	}
}

Database::~Database()
{
	if (database != 0)
	{
		cout << " deleted " << endl;
		delete database;
	}
}
