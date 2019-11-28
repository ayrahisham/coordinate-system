#include "A2.h"

int displayMenuOptions ()
{
	int choice;
	
	cout << endl << "Student ID   : 5841549" << endl
	     << "Student Name : Nur Suhaira Bte Badrul Hisham" << endl
	     << "--------------------------------------------" << endl
	     << "Welcome to Assn2 Program" 
	     << endl << endl
	     << "1) \t Input sensor data" << endl
	     << "2) \t Compute area & perimeter (for all records)" << endl
	     << "3) \t Print shapes report" << endl
	     << "4) \t Sort shape data" << endl
	     << "5) \t Quit" << endl
	     << endl << "Please enter your choice: ";
	cin >> choice;
	
	return choice;
}

int checkValidOption (int option)
{
	switch (option)
	{
		case 1:
		case 2:
		case 3:
		case 4:
		case 5: return option; 
		default: do
			 {
			 	cout << endl << "You have entered an invalid menu option. Please re-enter..."
			          	     << endl;
				option = displayMenuOptions ();
				
			 } while ((option != 1) || (option != 2) || (option != 3) ||
			          (option != 4) || (option != 5));
	}
	
	return option;
}

char to_lowercase (char c)
{
	if (c >= 'A' && c <= 'Z')
		return c + 32;

	return c;
}

string getShape ()
{
	bool ok;
	string shape;
	do
	{
		ok = false;
				
		cout << "Please enter name of shape: ";
		cin >> shape;
		for (char &c: shape) 
		{
			c = to_lowercase(c);
		}
		if ((shape.find ("square") != string::npos) 
		|| (shape.find ("rectangle") != string::npos) 
		|| (shape.find ("circle") != string::npos) 
		|| (shape.find ("cross") != string::npos))
		{
			ok = true;
		}
		cin.clear ();
	} while (ok == false);
	
	return shape;
}

char to_uppercase (char c)
{
	if (c >= 'a' && c <= 'z')
		return c - 32;

	return c;
}

string getType ()
{
	bool ok;
	string type;
	
	do
	{
		ok = false;
		cout << "Please enter special type (WS / NS): ";
		cin >> type;
		for (char &c: type) 
		{
			c = to_uppercase(c);
		}
		if ((type.compare ("NS") == 0) || (type.compare ("WS") == 0))
		{
			ok = true;
		}
		cin.clear ();			
	} while (ok == false);
	
	return type;
}

/*
bool isInteger (char value [], int size)
{
	for (int i = 0; i < size; i++)
	{
		if (!isdigit (int (value[i])))
		{	
			cout << "Hi" << endl;
			// do not have to loop to the end of str, just return false
			return false;
		}
	}
	
	return true;
}
*/

char displaySortOptions ()
{
	char choice;
	
	cout << endl 
	     << "\t a) \t Sort by area (ascending)" << endl
	     << "\t b) \t Sort by area (descending)" << endl
	     << "\t c) \t Sort by special type and area" << endl
	     << endl 
	     << "Please select sort option (‘q’ to go main menu) : ";
	cin >> choice;
	
	return choice;
}

char checkValidSortOption (char option)
{
	if (option >= 'A' && option <= 'Z')
	{
		option = option + 32;
	}
	
	if ((option == 'a') || (option == 'b') || (option == 'c') || (option == 'q'))
	{
		return option;
	}
	else
	{
		do
		{
			cout << endl << "You have entered an invalid sort menu option. Please re-enter..." 
			     << endl;
			option = displaySortOptions ();
				
			if (option >= 'A' && option <= 'Z')
			{
				option = option + 32;
			}
				
		} while ((option != 'a') || (option != 'b') || (option != 'c') ||
			 (option != 'q'));
	}
	
	return option;
}

bool sortAsc (double i, double j) 
{ 
	return i < j; 
}

bool sortDesc (double i, double j) 
{ 
	return i > j; 
}
