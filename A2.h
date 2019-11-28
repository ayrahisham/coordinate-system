#ifndef A2_H
#define A2_H
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <algorithm>
using namespace std;

const int CROSSVER = 12;
const int VERTICES = 4;
const int SIZE = 100;
const double PI = 3.14;

// describes a sample interaction between the main menu and ‘Input sensor data’ sub-menu
int displayMenuOptions ();

// check validity of menu option only 1 to 5
int checkValidOption (int);

// convert string to all lowercase
char to_lowercase (char);

// getting input for shape and type
string getShape ();
string getType ();

// checking x and y ordinates from user is integer
//bool isInteger (char [], int);

// display menu to sort classes by user's preferences
char displaySortOptions ();

// check validity of sort menu option only a to c or q
char checkValidSortOption (char);

// sort area in ascending order
bool sortAsc (double, double);

// sort area in descending order
bool sortDesc (double, double);

#endif
