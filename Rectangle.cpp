#include "Rectangle.h"

int Rectangle::id = 0;
int Rectangle::count = 0;
int Rectangle::countA = 0;

// Square class definition
ostream& operator<< (ostream& os, const Rectangle& r)
{
	os << r.print ();
	return os;
}
	
Rectangle::Rectangle (ShapeTwoD s)
{
	this->s = s;
	points = new Vertex [VERTICES];
	for (int i = 0; i < VERTICES; i++)
	{
		this->points[i].setX (0);
		this->points[i].setY (0);
	}
	peripoints = new Vertex [SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		this->peripoints[i].setX (0);
		this->peripoints[i].setY (0);
	}
	areapoints = new Vertex [SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		this->areapoints[i].setX (0);
		this->areapoints[i].setY (0);
	}
	
	this->area = 0;
	this->perimeter = 0;
	this->id = id;
	++this->id;
}

Rectangle::Rectangle (ShapeTwoD s, Vertex* points)
{
	this->s = s;
	points = new Vertex [VERTICES];
	for (int i = 0; i < VERTICES; i++)
	{
		this->points[i].setX (0);
		this->points[i].setY (0);
	}
	peripoints = new Vertex [SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		this->peripoints[i].setX (0);
		this->peripoints[i].setY (0);
	}
	areapoints = new Vertex [SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		this->areapoints[i].setX (0);
		this->areapoints[i].setY (0);
	}
	
	this->area = 0;
	this->perimeter = 0;
	this->id = id;
	++this->id;
}

Rectangle::~Rectangle ()
{
	// let compiler do it
	delete [] points;
	delete [] peripoints;
	delete [] areapoints;
}

Rectangle::Rectangle (const Rectangle& r)
{
	this->s = r.s;
	points = new Vertex [CROSSVER];
	for (int i = 0; i < VERTICES; i++)
	{
		this->points[i].setX (points[i].getX());
		this->points[i].setY (points[i].getY());
	}
	peripoints = new Vertex [SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		this->peripoints[i].setX (0);
		this->peripoints[i].setY (0);
	}
	areapoints = new Vertex [SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		this->areapoints[i].setX (0);
		this->areapoints[i].setY (0);
	}
	
	this->area = r.area;
	this->perimeter = r.perimeter;
	this->id = r.id;
}

ShapeTwoD Rectangle::getShape ()
{
	return s;
}

Vertex Rectangle::getVertex (int id)
{
	return points[id];
}

double Rectangle::getArea ()
{
	return area;
}

double Rectangle::getPerimeter ()
{
	return perimeter;
}

int Rectangle::getID ()
{
	return id;
}

double Rectangle::computeArea ()
{
	// same length
	if (this->side1 == this->side2)
	{
		// same width
		if (this->side3 == this->side4)
		{
			return this->side1 * this->side3;
		}
	}
	else if (this->side1 == this->side3)
	{
		if (this->side2 == this->side4)
		{
			return this->side1 * this->side2;
		}
	}
	else if (this->side1 == this->side4)
	{
		if (this->side2 == this->side3)
		{
			return this->side1 * this->side2;
		}
	}
	
	return -1;
}

void Rectangle::getPerimeterPoints ()
{
	// getting the lowest point
	int minX = points[0].getX ();
	int minY = points[0].getY ();
	
	// getting the highest point
	int maxX = points[0].getX ();
	int maxY = points[0].getY ();
	
	int sideX;
	int sideY;
	
	cout << "Points on perimeter : ";
	
	for (int i = 1; i < VERTICES; i++)
	{
		if (points[i].getX () <= minX)
		{
			minX = points[i].getX ();
		}
		else
		{
			maxX = points[i].getX ();
		}
		
		if (points[i].getY () <= minY)
		{
			minY = points[i].getY ();
		}
		else 
		{
			maxY = points[i].getY ();
		}	
	}
	
	sideX = maxX - minX;
	sideY = maxY - minY;
	
	for (int i = 0; i < VERTICES; i++)
	{
		if ((minX == points[i].getX ()) && (minY == points[i].getY ()))
		{
			// maneuver around the perimeter from lowest & highest points
			for (int j = 1; j < sideX; j++)
			{
				if (isPointOnShape (minX+j, minY))
				{
					cout << "(" << minX+j << "," << minY << "), ";
					peripoints[count].setX (minX+j);
					peripoints[count].setY (minY);
					++count;
				}
			}
			
			for (int k = 1; k < sideY; k++)
			{
				if (isPointOnShape (minX, minY+k))
				{
					cout << "(" << minX << "," << minY+k << "), ";
					peripoints[count].setX (minX);
					peripoints[count].setY (minY+k);
					++count;
				}
			}
		}
		if ((maxX == points[i].getX ()) && (maxY == points[i].getY ()))
		{
			for (int j = 1; j < sideX; j++)
			{
				if (isPointOnShape (maxX-j, maxY))
				{
					cout << "(" << maxX-j << "," << maxY << "), ";
					peripoints[count].setX (maxX-j);
					peripoints[count].setY (maxY);
					++count;
				}
			}
			
			for (int k = 1; k < sideY; k++)
			{
				if (isPointOnShape (maxX, maxY-k))
				{
					cout << "(" << maxX << "," << maxY-k << "), ";
					peripoints[count].setX (maxX);
					peripoints[count].setY (maxY-k);
					++count;
				}
			}
		}
	}
	
	cout << endl << endl;
}

void Rectangle::getWithinShapePoints ()
{
	int minX = points[0].getX ();
	int minY = points[0].getY ();
	
	// getting the highest point
	int maxX = points[0].getX ();
	int maxY = points[0].getY ();
	
	int sideX;
	int sideY;
	
	cout << "Points within shape : ";
	
	for (int i = 1; i < VERTICES; i++)
	{
		if (points[i].getX () <= minX)
		{
			minX = points[i].getX ();
		}
		else
		{
			maxX = points[i].getX ();
		}
		
		if (points[i].getY () <= minY)
		{
			minY = points[i].getY ();
		}
		else 
		{
			maxY = points[i].getY ();
		}	
	}
	
	sideX = maxX - minX;
	sideY = maxY - minY;
	
	for (int i = 0; i < VERTICES; i++)
	{
		if ((minX == points[i].getX ()) && (minY == points[i].getY ()))
		{
			for (int j = 1; j < sideX; j++) // diagonal points inside
			{
				for (int k = 1; k < sideY; k++) // to access using 2 loops
				{
					if (isPointInShape (minX+j, minY+k))
					{
						cout << "(" << minX+j << "," << minY+k << "), ";
						areapoints[countA].setX (minX+j);
						areapoints[countA].setY (minY+k);
						++countA;
					}
				}
			}
		}
	}
	
	cout << endl << endl;
}

void Rectangle::displayMap ()
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
		cout << "Display rectangle map:"
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
							for (int i = 0; i < VERTICES; i++)
							{
								// x-1 as x in map starts with 0
								if ((points[i].getX () == x-1) && (points[i].getY () == valueY)) // compare with valueY as it matches the value in map
								{
									cout << "x "; // printing shape point with a space
									display = true;
								}
							}
						
							for (int j = 0; j < count; j++)
							{
								// x-1 as x in map starts with 0
								if ((peripoints[j].getX () == x-1) && (peripoints[j].getY () == valueY)) // compare with valueY as it matches the value in map
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
			   << "\t \"x\" - points of rectangle" << endl
			   << "\t \"?\" - area points" << endl;

		cout << endl << endl;
	}
}

double Rectangle::computePerimeter ()
{
	return this->side1 + this->side2 + this->side3 + this->side4;
}

string Rectangle::print () const
{
	stringstream oss;
	oss << s << endl
	    << setprecision (0) << fixed
	    << "Area         : " << round (area) << " units square" << endl
	    << "Perimeter    : " << round (perimeter) << " units" << endl
	    << *points << endl;
	    for (int i = 0; i < VERTICES; i++)
	    {
	    	oss << "Points [" << i << "]   : (" << points[i].getX() << ", " << points[i].getY() << ")" << endl;
	    }
	
	return (oss.str());
}

bool Rectangle::isPointOnShape (int x, int y) 
{
	int minX = points[0].getX ();
	int minY = points[0].getY ();
	int maxX = points[0].getX ();
	int maxY = points[0].getY ();
	
	int sideX;
	int sideY;
	
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
	
	sideX = maxX - minX;
	sideY = maxY - minY;
	
	for (int i = 0; i < VERTICES; i++)
	{
		if ((minX == points[i].getX ()) && (minY == points[i].getY ()))
		{
			// maneuver around the perimeter from lowest & highest points
			for (int j = 1; j < sideX; j++)
			{
				if ((minX+j == x) && (minY == y))
				{
					return true;
				}
			}
			
			for (int k = 1; k < sideY; k++)
			{	
				
				if ((minX == x) && (minY+k == y))
				{
					return true;
				}
			}
		}
		if ((maxX == points[i].getX ()) && (maxY == points[i].getY ()))
		{
			for (int j = 1; j < sideX; j++)
			{
				if ((maxX-j == x) && (maxY == y))
				{
					return true;
				}
			}
			
			for (int k = 1; k < sideY; k++)
			{
				if ((maxX == x) && (maxY-k == y))
				{
					return true;
				}
			}
		}
	}
	
	return false;
}
	
bool Rectangle::isPointInShape (int x, int y)
{
	int minX = points[0].getX ();
	int minY = points[0].getY ();
	
	// getting the highest point
	int maxX = points[0].getX ();
	int maxY = points[0].getY ();
	
	int sideX;
	int sideY;
	
	for (int i = 1; i < VERTICES; i++)
	{
		if (points[i].getX () <= minX)
		{
			minX = points[i].getX ();
		}
		else
		{
			maxX = points[i].getX ();
		}
		
		if (points[i].getY () <= minY)
		{
			minY = points[i].getY ();
		}
		else 
		{
			maxY = points[i].getY ();
		}	
	}
	
	sideX = maxX - minX;
	sideY = maxY - minY;
	
	for (int i = 0; i < VERTICES; i++)
	{
		if ((minX == points[i].getX ()) && (minY = points[i].getY ()))
		{
			for (int j = 1; j < sideX; j++)
			{
				for (int k = 1; k < sideY; k++)
				{
					if ((minX+j == x) && (minY+k == y))
					{
						return true;
					}
				}
			}
		}
	}
	
	return false;
}

void Rectangle::setShape (ShapeTwoD s)
{
	this->s = s;
}

void Rectangle::setVertexX (int index, int value)
{
	points[index].setX (value);
}

void Rectangle::setVertexY (int index, int value)
{
	points[index].setY (value);
}

void Rectangle::setSides ()
{
	int side1 = 0;
	int side2 = 0;
	int side3 = 0;
	int side4 = 0;
	
	//e.g. (8, 7), (8, 9), (10,7), (10,9)
	for (int i = 0; i < VERTICES; i++)
	{
		for (int j = 0; j < VERTICES; j++)
		{
			// vertical line 1
			if ((side1 == 0) && (i != j)) // not comparing same array index
			{	
				if (points[i].getX () == points[j].getX ())
				{
					if (points[i].getY () > points [j].getY ())
					{
						side1 = points[i].getY () - points[j].getY ();
						this->side1 = side1;
					}
					else if (points[j].getY () > points [i].getY ())
					{
						side1 = points[j].getY () - points[i].getY ();
						this->side1 = side1;
					}
					else // no difference
					{
						this->side1 = side1;
					}
					
				}
			}
			
			// horizontal line 1
			else if ((side2 == 0) && (i != j)) // not comparing same array index
			{
				if (points[i].getY () == points[j].getY ())
				{
					if (points[i].getX () > points [j].getX ())
					{
						side2 = points[i].getX () - points[j].getX ();
						this->side2 = side2;
					}
					else if (points[j].getX () > points [i].getX ())
					{
						side2 = points[j].getX () - points[i].getX ();
						this->side2 = side2;
					}
					else // no difference
					{
						this->side2 = side2;
					}
					
				}
			}
			
			// vertical line 2
			else if ((side3 == 0) && (i != j)) // not comparing same array index
			{
				if (points[i].getX () == points[j].getX ())
				{
					if (points[i].getY () > points [j].getY ())
					{
						side3 = points[i].getY () - points[j].getY ();
						this->side3 = side3;
					}
					else if (points[j].getY () > points [i].getY ())
					{
						side3 = points[j].getY () - points[i].getY ();
						this->side3 = side3;
					}
					else // no difference
					{
						this->side3 = side3;
					}
					
				}
			}
			
			// horizontal line 2
			else if ((side4 == 0) && (i != j)) // not comparing same array index
			{
				if (points[i].getY () == points[j].getY ())
				{
					if (points[i].getX () > points [j].getX ())
					{
						side4 = points[i].getX () - points[j].getX ();
						this->side4 = side4;
					}
					else if (points[j].getX () > points [i].getX ())
					{
						side4 = points[j].getX () - points[i].getX ();
						this->side4 = side4;
					}
					else // no difference
					{
						this->side4 = side4;
					}
					
				}
			}
		}
	}
}

void Rectangle::setArea (double area)
{
	this->area = area;
}

void Rectangle::setPerimeter (double perimeter)
{
	this->perimeter = perimeter;
}
