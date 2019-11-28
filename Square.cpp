#include "Square.h"

int Square::id = 0;
int Square::count = 0;
int Square::countA = 0;

// Square class definition
ostream& operator<< (ostream& os, const Square& sq)
{
	os << sq.print ();
	return os;
}
	
Square::Square (ShapeTwoD s)
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
	
	this->side1 = 0;
	this->side2 = 0;
	this->side3 = 0;
	this->side4 = 0;
	this->area = 0;
	this->perimeter = 0;
	this->id = id;
	++this->id;
}

Square::Square (ShapeTwoD s, Vertex * points)
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
	
	this->side1 = 0;
	this->side2 = 0;
	this->side3 = 0;
	this->side4 = 0;
	this->area = 0;
	this->perimeter = 0;
	this->id = id;
	++this->id;
}
Square::~Square ()
{
	// let compiler do it
	delete [] points;
	delete [] peripoints;
	delete [] areapoints;
}

Square::Square (const Square& sq)
{
	this->s = sq.s;
	points = new Vertex [VERTICES];
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
	
	this->side1 = sq.side1;
	this->side2 = sq.side2;
	this->side3 = sq.side3;
	this->side4 = sq.side4;
	this->area = sq.area;
	this->perimeter = sq.perimeter;
	this->id = sq.id;
}

ShapeTwoD Square::getShape ()
{
	return s;
}

Vertex Square::getVertex (int id)
{
	return points[id];
}

double Square::getArea ()
{
	return area;
}

double Square::getPerimeter ()
{
	return perimeter;
}

int Square::getID ()
{
	return id;
}

double Square::computeArea ()
{
	// all sides are same is square
	if ((this->side1 == this->side2) &&
	   (this->side2 == this->side3) &&
	   (this->side3 == this->side4) &&
	   (this->side4 == this->side1))
	{
		return pow (this->side1, 2);
	}
	
	return -1;
}

void Square::getPerimeterPoints ()
{
	// getting the lowest point
	int minX = points[0].getX ();
	int minY = points[0].getY ();
	
	// getting the highest point
	int maxX = points[0].getX ();
	int maxY = points[0].getY ();
	
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
	
	for (int i = 0; i < VERTICES; i++)
	{
		if ((minX == points[i].getX ()) && (minY == points[i].getY ()))
		{
			// maneuver around the perimeter from lowest & highest points
			for (int j = 1; j < side1; j++)
			{
				if (isPointOnShape (minX, minY+j))
				{
					cout << "(" << minX << "," << minY+j << "), ";
					peripoints[count].setX (minX);
					peripoints[count].setY (minY+j);
					++count;
				}
				
				if (isPointOnShape (minX+j, minY))
				{
					cout << "(" << minX+j << "," << minY << "), ";
					peripoints[count].setX (minX+j);
					peripoints[count].setY (minY);
					++count;
				}
			}
		}
		if ((maxX == points[i].getX ()) && (maxY == points[i].getY ()))
		{
			for (int j = 1; j < side1; j++)
			{
				if (isPointOnShape (maxX, maxY-j))
				{
					cout << "(" << maxX << "," << maxY-j << "), ";
					peripoints[count].setX (maxX);
					peripoints[count].setY (maxY-j);
					++count;
				}
				if (isPointOnShape (maxX-j, maxY))
				{
					cout << "(" << maxX-j << "," << maxY << "), ";
					peripoints[count].setX (maxX-j);
					peripoints[count].setY (maxY);
					++count;
				}
			}
		}
	}
	
	cout << endl << endl;			
}

void Square::getWithinShapePoints ()
{
	int minX = points[0].getX ();
	int minY = points[0].getY ();
	
	cout << "Points within shape : ";
	
	for (int i = 1; i < VERTICES; i++)
	{
		if (points[i].getX () <= minX)
		{
			minX = points[i].getX ();
		}
		
		if (points[i].getY () <= minY)
		{
			minY = points[i].getY ();
		}
	}
	
	for (int i = 0; i < VERTICES; i++)
	{
		if ((minX == points[i].getX ()) && (minY == points[i].getY ()))
		{
			for (int j = 1; j < side1; j++) // diagonal points inside
			{
				for (int k = 1; k < side1; k++) // to access using 2 loops
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

double Square::computePerimeter ()
{
	// all sides are same is square
	if ((this->side1 == this->side2) &&
	   (this->side2 == this->side3) &&
	   (this->side3 == this->side4) &&
	   (this->side4 == this->side1))
	{
		return this->side1 * VERTICES;
	}
	
	return 0;
}

bool Square::isPointOnShape (int x, int y) 
{
	int minX = points[0].getX ();
	int minY = points[0].getY ();
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
	
	for (int i = 0; i < VERTICES; i++)
	{
		if ((minX == points[i].getX ()) && (minY = points[i].getY ()))
		{
			for (int j = 1; j < side1; j++)
			{
				if ((minX == x) && (minY+j == y))
				{
					return true;
				}
				else if ((minX+j == x) && (minY == y))
				{
					return true;
				}
			}
		}
		if ((maxX == points[i].getX ()) && (maxY == points[i].getY ()))
		{
			for (int j = 1; j < side1; j++)
			{
				if ((maxX == x) && (maxY-j == y))
				{
					return true;
				}
				else if ((maxX-j == x) && (minY == y))
				{
					return true;
				}
			}
		}
	}
	
	return false;
}
	
bool Square::isPointInShape (int x, int y)
{
	int minX = points[0].getX ();
	int minY = points[0].getY ();
	
	for (int i = 1; i < VERTICES; i++)
	{
		if (points[i].getX () <= minX)
		{
			minX = points[i].getX ();
		}
		
		if (points[i].getY () <= minY)
		{
			minY = points[i].getY ();
		}
	}
	
	for (int i = 0; i < VERTICES; i++)
	{
		if ((minX == points[i].getX ()) && (minY = points[i].getY ()))
		{
			for (int j = 1; j < side1; j++)
			{
				for (int k = 1; k < side1; k++)
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

void Square::displayMap ()
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
		cout << "Display square map:"
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
			   << "\t \"x\" - points of square" << endl
			   << "\t \"?\" - area points" << endl;

		cout << endl << endl;
	}
}

string Square::print () const
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

void Square::setShape (ShapeTwoD s)
{
	this->s = s;
}

void Square::setVertexX (int index, int value)
{
	points[index].setX (value);
}

void Square::setVertexY (int index, int value)
{
	points[index].setY (value);
}

void Square::setSides ()
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

void Square::setArea (double area)
{
	this->area = area;
}

void Square::setPerimeter (double perimeter)
{
	this->perimeter = perimeter;
}
