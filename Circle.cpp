#include "Circle.h"

int Circle::id = 0; 
int Circle::countA = 0;

// Circle class definition
ostream& operator<< (ostream& os, const Circle& c)
{
	os << c.print ();
	return os;
}

Circle::Circle (ShapeTwoD s)
{
	this->s = s;
	points = new Vertex [VERTICES];
	for (int i = 0; i < VERTICES; i++)
	{
		this->points[i].setX (0);
		this->points[i].setY (0);
	}
	areapoints = new Vertex [SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		this->areapoints[i].setX (0);
		this->areapoints[i].setY (0);
	}
	
	this->x = 0;
	this->y = 0;
	this->radius = 0;
	this->area = 0;
	this->perimeter = 0;
	this->id = id;
	++this->id;
}

Circle::Circle (ShapeTwoD s, int x, int y, int radius)
{
	this->s = s;
	points = new Vertex [VERTICES];
	for (int i = 0; i < VERTICES; i++)
	{
		this->points[i].setX (0);
		this->points[i].setY (0);
	}
	areapoints = new Vertex [SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		this->areapoints[i].setX (0);
		this->areapoints[i].setY (0);
	}
	
	this->x = 0;
	this->y = 0;
	this->radius = radius;
	this->area = 0;
	this->perimeter = 0;
	this->id = id;
	++this->id;
}

Circle::~Circle () 
{
	// let compiler do it
	delete [] points;
	delete [] areapoints;
}

Circle::Circle (const Circle& c)
{
	this->s = c.s;
	points = new Vertex [VERTICES];
	for (int i = 0; i < VERTICES; i++)
	{
		this->points[i].setX (points[i].getX ());
		this->points[i].setY (points[i].getY ());
	}
	areapoints = new Vertex [SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		this->areapoints[i].setX (0);
		this->areapoints[i].setY (0);
	}
	
	this->x = c.x;
	this->y = c.x;
	this->radius = c.radius;
	this->area = c.area;
	this->perimeter = c.perimeter;
	this->id = c.id;
}

ShapeTwoD Circle::getShape ()
{
	return s;
}

Vertex Circle::getVertex (int id)
{
	return points[id];
}

int Circle::getX ()
{
	return x;
}

int Circle::getY ()
{
	return y;
}

int Circle::getRadius ()
{
	return radius;
}

double Circle::getArea ()
{
	return area;
}

double Circle::getPerimeter ()
{
	return perimeter;
}

int Circle::getID ()
{
	return id;
}

double Circle::computeArea ()
{
	if (getRadius() > 0)
	{
		return PI * pow (getRadius(), 2);
	}
	
	return -1;
}

void Circle::getPerimeterPoints ()
{
	int count = 0;
	cout << "Points on perimeter : ";
	if (isPointOnShape (getX(), getY() + getRadius()))
	{
		cout << "(" << getX () << "," << getY () + getRadius () << "), ";
		points[count].setX (getX());
		points[count].setY (getY() + getRadius());
		++count;
	}
	
	if (isPointOnShape (getX () + getRadius (), getY ()))
	{
		cout << "(" << getX () + getRadius () << "," << getY () << "), ";
		points[count].setX (getX () + getRadius ());
		points[count].setY (getY ());
		++count;
	}
	
	if (isPointOnShape (getX (), getY () - getRadius ()))
	{
		cout << "(" << getX () << "," << getY () - getRadius () << "), ";
		points[count].setX (getX());
		points[count].setY (getY() - getRadius());
		++count;
	}
	
	if (isPointOnShape (getX () - getRadius (), getY ()))
	{
		cout << "(" << getX () - getRadius () << "," << getY () << ")";
		points[count].setX (getX () - getRadius());
		points[count].setY (getY());
		++count;
	}
	
	cout << endl << endl;
}

void Circle::getWithinShapePoints ()
{
	cout << "Points within shape : ";
	
	for (int i = 1; i < getRadius (); i++)
	{
		// top of point 
		if (isPointInShape (getX (), getY ()+i))
		{
			cout << "(" << getX () << "," << getY ()+i << "), ";
			areapoints[countA].setX (getX());
			areapoints[countA].setY (getY() +i);
			++countA;
		}
	
		// top right of point 
		if (isPointInShape (getX ()+i, getY ()+i))
		{
			cout << "(" << getX ()+i << "," << getY ()+i << "), ";
			areapoints[countA].setX (getX() +i);
			areapoints[countA].setY (getY() +i);
			++countA;
		}
	
		// right of point 
		if (isPointInShape (getX ()+i, getY ()))
		{
			cout << "(" << getX ()+i << "," << getY () << "), ";
			areapoints[countA].setX (getX() +i);
			areapoints[countA].setY (getY());
			++countA;
		}
	
		// bottom right of point 
		if (isPointInShape (getX ()+i, getY ()-i))
		{
			cout << "(" << getX ()+i << "," << getY ()-i << "), ";
			areapoints[countA].setX (getX() +i);
			areapoints[countA].setY (getY() -i);
			++countA;
		}
	
		// bottom of point 
		if (isPointInShape (getX (), getY ()-i))
		{
			cout << "(" << getX () << "," << getY ()-i << "), ";
			areapoints[countA].setX (getX ());
			areapoints[countA].setY (getY () -i);
			++countA;
		}
	
		// bottom left of point 
		if (isPointInShape (getX ()-i, getY ()-i))
		{
			cout << "(" << getX ()-i << "," << getY ()-i << "), ";
			areapoints[countA].setX (getX () -i);
			areapoints[countA].setY (getY () -i);
			++countA;
		}
	
		// left of point 
		if (isPointInShape (getX ()-i, getY ()))
		{
			cout << "(" << getX ()-i << "," << getY () << "), ";
			areapoints[countA].setX (getX () -i);
			areapoints[countA].setY (getY ());
			++countA;
		}
	
		// top left of point 
		if (isPointInShape (getX ()-i, getY ()+i))
		{
			cout << "(" << getX ()-i << "," << getY ()+i << "), ";
			areapoints[countA].setX (getX () -i);
			areapoints[countA].setY (getY () +i);
			++countA;
		}
	}
	
	cout << endl << endl;
}

double Circle::computePerimeter ()
{
	return 2 * PI * getRadius();
}

bool Circle::isPointInShape (int x, int y)
{
	for (int i = 1; i < getRadius (); i++)
	{
		// top of point
		if ((x == getX ()) && (y == getY ()+i))
		{
			return true;
		}
		// top right of point 
		else if ((x == getX ()+i) && (y == getY ()+i))
		{
			return true;
		}
	
		// right of point 
		if ((x == getX ()+i) && (y == getY ()))
		{
			return true;
		}
	
		// bottom right of point 
		if ((x == getX ()+i) && (y == getY ()-i))
		{
			return true;
		}
	
		// bottom of point 
		if ((x == getX ()) && (y == getY ()-i))
		{
			return true;
		}
	
		// bottom left of point 
		if ((x == getX ()-i) && (y == getY ()-i))
		{
			return true;
		}
	
		// left of point 
		if ((x == getX ()-i) && (y == getY ()))
		{
			return true;
		}
	
		// top left of point 
		if ((x == getX ()-i) && (y == getY ()+i))
		{
			return true;
		}
	}
	
	return false;
}
	
bool Circle::isPointOnShape (int x, int y)
{
	for (int i = 0; i < VERTICES; i++)
	{
		if ((x == points[i].getX ()) && (y == points[i].getY ()))
		{
			return true;
		}
		
	}
	
	return false;
}

void Circle::displayMap ()
{
	// display the shape map
	// getting the lowest point
	int minX = points[0].getX ();
	int minY = points[0].getY ();
	
	// getting the highest point
	int maxX = points[0].getX ();
	int maxY = points[0].getY ();
	
	for (int i = 1; i < VERTICES; i++)
	{
		if (points[i].getX () <= minX)
		{
			minX = points[i].getX ();
		}
		else if (points[i].getX () > maxX)
		{
			maxX = points[i].getX ();
		}
		
		if (points[i].getY () <= minY)
		{
			minY = points[i].getY ();
		}
		else if (points[i].getY () > maxY)
		{
			maxY = points[i].getY ();
		}
	}
	
	string hex = "# ";
	int valueY = maxY + 5;
	int valueX = 0;
	static bool display = false;
	
	// only display if x and y min index > 0
	if ((minX > 0) && (minY > 0))
	{
		cout << "Display circle map:"
			   << endl << endl;
			   
		// add 10 for 5 levels below and 5 levels upper
		for (int y = 0; y < maxY+5+5; y++)
		{
			if ((y == 0) || (y == maxY+5+5-1)) // if y is in first and last row print a line of #
			{
				cout << "   "; // 3 empty spaces to cater grid till 99 from negate numbers
				for (int z = 0; z < maxY+5+5; z++)
				{
					cout << hex;
				}
				cout << endl; // move on to next line
			}
			else // if x is not in first and last row do this
			{
				// displaying indices not on first and last rows
				if ((valueY > 9) || (valueY < 0))
				{
					cout << valueY << " ";
				}
				else
				{
					cout << " " << valueY << " ";
				}
			
				for (int x = 0; x < maxX+5+5; x++) // columns
				{
					if ((y != 0) || (y != maxY+5+5-1)) // if x is not in y first and last row print #
					{
						if ((x == 0) || (x == maxX+5+5-1)) // if x in the edge of the map then print # and a spacing
						{
							cout << hex;
						}
						else // within the empty spaces of the map
						{
							// x-1 as x in map starts with 0
							if ((getX () == x-1) && (getY () == valueY)) // compare with valueY as it matches the value in map
							{
								cout << "x "; // printing shape point with a space
								display = true;
							}
						
							for (int j = 0; j < VERTICES; j++)
							{
								// x-1 as x in map starts with 0
								if ((points[j].getX () == x-1) && (points[j].getY () == valueY)) // compare with valueY as it matches the value in map
								{
									cout << "/ "; // printing shape perimeter with a space
									display = true;
								}
							}
						
							for (int k = 0; k < countA; k++)
							{
								// x-1 as x in map starts with 0
								if ((areapoints[k].getX () == x-1) && (areapoints[k].getY () == valueY)) // compare with valueY as it matches the value in map
								{
									cout << "? "; // printing shape area with a space
									display = true;
								}
							}
						
							if (display == false)
							{
								cout << "  "; // shape print 2 spaces
							}
						
							display = false; // set back to false again to move on to next row
						}
					}
				}
			
				cout << endl; // once x is done with the printing on 1 line move on to next line
				--valueY; // decrement of y indices after every row
			}
		}
	
		cout << "    "; // to start indexing x indices from 4 spaces onwards
		// due to y indices and 2 spacing
		for (int z = 0; z < maxX+8; z++) // 5 + 5 - 2 spaces due to hex at the edges
		{
			cout << " " << valueX;
			++valueX; // increment of y indices after every row
		}
	
		cout << endl << endl
			   << "\t Legend" << endl
			   << "\t ------" << endl
			   << "\t \"\\\" - perimeter points" << endl
			   << "\t \"x\" - points of circle" << endl
			   << "\t \"?\" - area points" << endl;

		cout << endl << endl;
	}
}

string Circle::print () const
{
	stringstream oss;
	
	oss << s << endl
	    << setprecision (0) << fixed
	    << "Area         : " << round (area) << " units square" << endl
	    << "Perimeter    : " << round (perimeter) << " units" << endl
	    << *points << endl
	    << "Points [0]   : (" << x << ", " << y << ")" << endl
	    << "Radius       : (" << radius << ")" << endl;
	    
	return (oss.str());
}

void Circle::setShape (ShapeTwoD s)
{
	this->s = s;
}

void Circle::setX (int x)
{
	this->x = x;
}

void Circle::setY (int y)
{
	this->y = y;
}

void Circle::setRadius (int radius)
{
	this->radius = radius;
}

void Circle::setSides ()
{
	//e.g. x = 5, y = 7, radius = 2	
	// top of circle (x = 5, y = 7+2)
	this->points[0].setX (getX ());
	this->points[0].setY (getY () + getRadius ());
	
	// right of circle (x = 5+2, y = 7)
	this->points[1].setX (getX () + getRadius());
	this->points[1].setY (getY());
	
	// bottom of circle (x = 5, y = 7-2)
	this->points[2].setX (getX ());
	this->points[2].setY (getY() - getRadius ());
	
	// left of circle (x = 5-2, y = 7)
	this->points[3].setX (getX () - getRadius());
	this->points[3].setY (getY());
}

void Circle::setArea (double area)
{
	this->area = area;
}

void Circle::setPerimeter (double perimeter)
{
	this->perimeter = perimeter;
}

void Circle::setVertex (int index, int value)
{
	points[index].setX (value);
}

