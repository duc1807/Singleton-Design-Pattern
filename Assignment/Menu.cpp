#include "pch.h"
#include "Menu.h"
#include "Database.h"
#include "Product.h"
#include "Collection.h"

void Menu::run()
{
	bool running = true;
	while (running)
	{
		showMenu();
		int choice = getChoice();
		action(choice);

		if (choice == 0) running = false;
	}
}


int Menu::getChoice()
{
	int choice;
	cout << "Your selection: "; cin >> choice;
	return choice;
}

//Admin program
void Program::showMenu()
{
	cout << endl;
	cout << "********************************************" << endl;
	cout << "\t Website of Convenient Mart" << endl;
	cout << "1. Add new product" << endl;
	cout << "2. Show all products" << endl;
	cout << "3. Change price of a product" << endl;
	cout << "4. Delete a product" << endl;
	cout << "0. Logout" << endl;
	cout << "---------------------------------------------" << endl;
	cout << endl;
}

void Program::action(const int &choice)
{
	switch (choice)
	{
	case 1:
		addNewProduct();
		break;
	case 2:
		showAll();
		break;
	case 3:
		changePrice();
		break;
	case 4:
		delProduct();
		break;
	case 0:
		break;
	default:
		break;
	}
}

void Program::addNewProduct()
{
	database = Database::getDatabase();
	string type;
	string name;
	string code;
	int price;
	
	cout << "*****Add a new product*****" << endl;
	cout << "(Press 0 to back to main menu)" << endl;
	cout << "Product type(Milk, Snack, Food): ";
	cin >> type;

	if (type == "milk" || type == "snack" || type == "food")
	{
		cout << "Name of " << type << ": ";
		cin >> name;

		cout << "Barcode: ";
		cin >> code;

		cout << "Price: ";
		cin >> price;

		database->addProduct(type, name, code, price);
	}

	else if (type == "0") {}

	else
	{
		cout << endl;
		cout << "								Invalid choice!" << endl;	
	}	
}

void Program::showAll()
{
	database = Database::getDatabase();
	database->showAll();
}

void Program::changePrice()
{
	database = Database::getDatabase();
	cout << "(Press 0 to back to main menu)" << endl;
	cout << "Input the type of product that you want to change price(milk, food, snack): ";
	string type;
	cin >> type;
	cout << endl;

	if (database->isEmpty(type)) cout << endl;	
	else
	{
		cout << "Input the product code: ";
		string proCode;
		cin >> proCode;
		cout << endl;

		cout << "----------Product information-----------" << endl;
		database->showProInfo(type, proCode);
		cout << endl;
		cout << "Input the wanted price: ";
		int newPrice;
		cin >> newPrice;

		database->changePrice(type, proCode, newPrice);
	}
}

void Program::delProduct()
{
	database = Database::getDatabase();
	cout << endl;
	cout << "Enter the type of product: ";
	string type; cin >> type;
	cout << endl;
	if (database->isEmpty(type)) cout << endl;

	else
	{
		database->showCollectionInfo(type);

		cout << endl;

		cout << "Enter the number of product to delete: ";
		int num;
		cin >> num;

		database->deleteProduct(type, num);
	}
}

////////////////// Customer program
void CustomerProgram::showMenu()
{
	database = Database::getDatabase();
	cout << endl;
	cout << "*************************************" << endl;
	cout << "\t Website of F&Food" << endl;
	cout << "1. View all product" << endl;
	cout << "2. Buy products" << endl;
	cout << "3. View Cart" << endl;
	cout << "4. Remove a product from cart" << endl;
	cout << "5. Print receipt" << endl;
	cout << "0. Logout" << endl;
	cout << "--------------------------------------" << endl;
	cout << endl;
}



///////// Customer menu
void CustomerProgram::action(const int &choice)
{
	switch (choice)
	{
	case 1:
		viewAll();
		break;
	case 2:
		buy();
		break;
	case 3:
		showCart();
		break;
	case 4:
		removeProduct();
		break;
	case 5:
		confirmBill();
		break;
	default:
		break;
	}
}

void CustomerProgram::viewAll() const
{
	database->showAll();
}

void CustomerProgram::buy()
{
	database = Database::getDatabase();
	cout << "Type of product you want to buy(milk, food, snack): ";
	string type;
	cin >> type;
	cout << endl;
	int size = database->getCollectionSize(type);
	cout << size << endl;

	if (type == "milk" || type == "food" || type == "snack")
	{
		if (database->isEmpty(type)) cout << endl;
		else
		{
			database->showCollectionInfo(type);

			int proNum = 0;
			cout << "Add product to cart (number of product): ";
			cin >> proNum;

			int size;
			size = database->getCollectionSize(type);

			if (proNum - 1 >= size)
			{
				cout << "Invalid!!!" << endl;
				cout << endl;
			}
			else
			{
				Product prod = database->getProduct(type, proNum);
				cusCart.addProduct(prod);
			}
		}
	}
	else cout << "Invalid choice!" << endl;
}

void CustomerProgram::showCart()
{
	cusCart.display();
}

void CustomerProgram::removeProduct()
{
	cusCart.display();
	if (cusCart.isEmpty())
	{
		cout << endl;
		cout << "Empty!!!" << endl;
	}
	else
	{
		cout << "Remove product No: ";
		int num; cin >> num;
		cusCart.removeProduct(num);
	}
}

void CustomerProgram::confirmBill()
{
	cusCart.display();
	
	cout << "Total: " << cusCart.getTotal() << endl;
}