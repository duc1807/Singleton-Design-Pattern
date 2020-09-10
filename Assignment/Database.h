#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Collection.h"

using namespace std;
class Database
{
private:
	static Database *database;
	Database();
	vector<Collection> collections;
public:
	static Database* getDatabase();
	void showAll();
	void addProduct(const string &type, const string &name, const string &code, const int &price);
	void changePrice(const string &type, const string &code, const int &price);
	void showProInfo(const string &type, const string &code);
	void showCollectionInfo(const string &type);
	void deleteProduct(const string &type,  const int &num);
	bool isEmpty(const string &type);
	int getCollectionSize(const string &type);

	Product getProduct(const string &type, const int &proNum);
	~Database();
};

