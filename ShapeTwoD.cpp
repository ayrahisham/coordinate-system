#include "ShapeTwoD.h"

int ShapeTwoD::id = 0;

// ShapeTwoD class definition
ostream& operator<< (ostream& os, const ShapeTwoD& s)
{
	os << s.print ();
	return os;
}

ShapeTwoD::ShapeTwoD ()
{
	this->name = "";
	this->containsWarpSpace = false;
	this->sort = false;
}

ShapeTwoD::ShapeTwoD (string name, bool containsWarpSpace)
{
	this->name = name;
	this->containsWarpSpace = containsWarpSpace;
	this->sort = false;
	this->id = id;
	++this->id;
}

ShapeTwoD::~ShapeTwoD ()
{
// let compiler do it
}

ShapeTwoD::ShapeTwoD (const ShapeTwoD& s)
{
	this->name = s.name;
	this->containsWarpSpace = s.containsWarpSpace;
	this->sort = s.sort;
	this->id = s.id;
}

string ShapeTwoD::getName ()
{
	return name;
}

bool ShapeTwoD::getContainsWarpSpace ()
{
	return containsWarpSpace;
}

bool ShapeTwoD::getSort ()
{
	return sort;
}

int ShapeTwoD::getID ()
{
	return id;
}

Vertex ShapeTwoD::getVertex (int id)
{
	return points [id];
}

void ShapeTwoD::getPerimeterPoints () 
{
	cout << "Points on perimeter : ";
}

void ShapeTwoD::getWithinShapePoints ()
{
	cout << "Points within shape : ";
}

double ShapeTwoD::getArea ()
{
	double area;
	
	return area;
}
	
double ShapeTwoD::computeArea ()
{
	double area = 0;
	
	return area;
}
	
double ShapeTwoD::computePerimeter ()
{
	double perimeter;
	
	return perimeter;
}

bool ShapeTwoD::isPointInShape (int x, int y)
{
	return false;
}
	
void ShapeTwoD::displayMap ()
{

}

bool ShapeTwoD::isPointOnShape (int x, int y) 
{
	return false;
}

string ShapeTwoD::print () const
{
	stringstream oss;
	oss << "Name         : " << name << endl
	    << "Special Type : ";
	    
	if (containsWarpSpace)
	{
		oss << "WS";
	}
	else
	{
		oss << "NS";
	}
	
	return (oss.str());
}
	
void ShapeTwoD::setName (string name)
{
	this->name = name;
}

void ShapeTwoD::setContainsWarpSpace (bool containsWarpSpace)
{
	this->containsWarpSpace = containsWarpSpace;
}

void ShapeTwoD::setSides ()
{
	
}

void ShapeTwoD::setArea (double)
{
	
}

void ShapeTwoD::setPerimeter (double)
{

}

void ShapeTwoD::setSort (bool sort)
{
	this->sort = sort;
}

