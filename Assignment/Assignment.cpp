

#include "pch.h"
#include <iostream>
#include<iostream>
#include<string>
#include <vector>
using namespace std;

#include "Menu.h"

int main()
{
	bool running = true;
	string username; string password;
	while (running)
	{
		cout << endl;
		cout << "*****************************************************" << endl;
		cout << "		   Website of Convenient Mart" << endl;
		cout << "	Login to start 		 (Input 0 if you want to exit)" << endl;
		cout << "Username: "; cin >> username; 
		if (username == "0")
		{
			running = false;
			break;
		}

		cout << endl;
		cout << "Password: "; cin >> password;
		cout << endl;
		cout << "*****************************************************" << endl;
		cout << endl;

		if (username == "admin" && password == "admin")
		{
			cout << "\t ** Login as administrator" << endl;
			Program admin;
			admin.run();
		}
		if (username == "customer" && password == "customer")
		{
			cout << "\t ** Login as Customer" << endl;
			CustomerProgram customer;
			customer.run();
		}
		
		else
		{
			cout << "Invalid account!!! Please login again!" << endl;
			cout << endl;
		}
	}

	return 0;
	
}
