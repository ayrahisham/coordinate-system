#include "Cross.h"

int Cross::id = 0;
int Cross::count = 0;
int Cross::countA = 0;

// Cross class definition
ostream& operator<< (ostream& os, const Cross& cr)
{
	os << cr.print ();
	return os;
}
	
Cross::Cross (ShapeTwoD s)
{
	this->s = s;
	points = new Vertex [CROSSVER];
	for (int i = 0; i < CROSSVER; i++)
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
	this->side5 = 0;
	this->side6 = 0;
	this->side7 = 0;
	this->side8 = 0;
	this->side9 = 0;
	this->side10 = 0;
	this->side11 = 0;
	this->side12 = 0;
	this->area = 0;
	this->perimeter = 0;
	this->id = id;
	++this->id;
}

Cross::Cross (ShapeTwoD s, Vertex* points)
{
	this->s = s;
	points = new Vertex [CROSSVER];
	for (int i = 0; i < CROSSVER; i++)
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
	this->side5 = 0;
	this->side6 = 0;
	this->side7 = 0;
	this->side8 = 0;
	this->side9 = 0;
	this->side10 = 0;
	this->side11 = 0;
	this->side12 = 0;
	this->area = 0;
	this->perimeter = 0;
	this->id = id;
	++this->id;
}

Cross::~Cross ()
{
	// let compiler do it
	delete [] points;
	delete [] peripoints;
	delete [] areapoints;
}

Cross::Cross (const Cross& cr)
{
	this->s = cr.s;
	points = new Vertex [CROSSVER];
	for (int i = 0; i < CROSSVER; i++)
	{
		this->points[i].setX (points[i].getX ());
		this->points[i].setY (points[i].getY ());
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
	this->side5 = 0;
	this->side6 = 0;
	this->side7 = 0;
	this->side8 = 0;
	this->side9 = 0;
	this->side10 = 0;
	this->side11 = 0;
	this->side12 = 0;
	this->area = cr.area;
	this->perimeter = cr.perimeter;
	this->id = cr.id;
}

ShapeTwoD Cross::getShape ()
{
	return s;
}

Vertex Cross::getVertex (int id)
{
	return points[id];
}

double Cross::getArea ()
{
	return area;
}

double Cross::getPerimeter ()
{
	return perimeter;
}

int Cross::getID ()
{
	return id;
}

double Cross::computeArea ()
{
	double area1 = 0;
	double area2 = 0;
	double area3 = 0;
	
	// breaking the cross into 3 squares/rectangles
	if ((side1 == side3) && (side2 == side4) && (side5 == side9) && (side7 == side11))
	{
		area1 = side1 * (side2 + side5 + side7);
		if ((side2 == side4) && (side6 == side8))
		{
			area2 = side2 * side6;
			if ((side4 == side2) && (side10 == side12))
			{
				area3 = side4 * side12;
				return area1 + area2 + area3;
			}
		}
	}
	
	return - 1;
}

void Cross::getPerimeterPoints ()
{
	int minX = points[0].getX (); // left side of cross
	int minY = points[0].getY (); // bottom side of cross
	int maxX = points[0].getX (); // right side of cross
	int maxY = points[0].getY (); // top side of cross
	
	cout << "Points on perimeter : ";
	
	for (int i = 1; i < CROSSVER; i++)
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
	
	for (int i = 0; i < CROSSVER; i++)
	{
		// side 1 perimeter
		if (points[i].getX () == minX)
		{
			for (int j = 0; j < CROSSVER; j++)
			{
				if ((points[i].getX () == points[j].getX ()) && (i != j))
				{
					if (points[i].getY() < points[j].getY ())
					{
						// maneuver around the perimeter
						for (int a = 1; a < side1; a++)
						{
							if (isPointOnShape (minX, points[i].getY ()+a))
							{
								cout << "(" << minX << "," << points[i].getY ()+a << "), ";
								peripoints[count].setX (minX);
								peripoints[count].setY (points[i].getY ()+a);
								++count;
							}
						}
					}
				}
			}
		}
		
		// side 2 perimeter
		if (points[i].getY () == minY)
		{
			for (int j = 0; j < CROSSVER; j++)
			{
				if ((points[i].getY () == points[j].getY ()) && (i != j))
				{
					if (points[i].getX() < points[j].getX ())
					{
						// maneuver around the perimeter
						for (int b = 1; b < side2; b++)
						{
							if (isPointOnShape (points[i].getX ()+b, minY))
							{
								cout << "(" << points[i].getX ()+b << "," << minY << "), ";
								peripoints[count].setX (points[i].getX() + b);
								peripoints[count].setY (minY);
								++count;
							}
						}
					}
				}
			}
		}
		
		// side 3 perimeter
		if (points[i].getX () == maxX)
		{
			for (int j = 0; j < CROSSVER; j++)
			{
				if ((points[i].getX () == points[j].getX ()) && (i != j))
				{
					if (points[i].getY() < points[j].getY ())
					{
						// maneuver around the perimeter
						for (int c = 1; c < side3; c++)
						{
							if (isPointOnShape (maxX, points[i].getY ()+c))
							{
								cout << "(" << maxX << "," << points[i].getY ()+c << "), ";
								peripoints[count].setX (maxX);
								peripoints[count].setY (points[i].getY ()+c);
								++count;
							}
						}
					}
				}
			}
		}
		
		// side 4 perimeter
		if (points[i].getY () == maxY)
		{
			for (int j = 0; j < CROSSVER; j++)
			{
				if ((points[i].getY () == points[j].getY ()) && (i != j))
				{
					if (points[i].getX() < points[j].getX ())
					{
						// maneuver around the perimeter
						for (int d = 1; d < side4; d++)
						{
							if (isPointOnShape (points[i].getX ()+d, maxY))
							{
								cout << "(" << points[i].getX ()+d << "," << maxY << "), ";
								peripoints[count].setX (points[i].getX () +d);
								peripoints[count].setY (maxY);
								++count;
							}
						}
					}
				}
			}	
		}
		
		// side5 perimeter
		if (points[i].getX () == minX)
		{
			for (int j = 0; j < CROSSVER; j++)
			{
				if ((points[i].getX () == points[j].getX ()) && (i != j))
				{
					if (points[i].getY() < points[j].getY ())
					{
						// maneuver around the perimeter
						for (int e = 1; e < side5; e++)
						{
							if (isPointOnShape (minX+e, points[i].getY ()))
							{
								cout << "(" << minX+e << "," << points[i].getY () << "), ";
							}
						}
					}
				}
			}
		}
		
		//side6 perimeter
		if (points[i].getY () == minY)
		{
			for (int j = 0; j < CROSSVER; j++)
			{
				if ((points[i].getY () == points[j].getY ()) && (i != j))
				{
					if (points[i].getX() < points[j].getX ())
					{
						// maneuver around the perimeter
						for (int f = 1; f < side6; f++)
						{
							if (isPointOnShape (points[i].getX (), points[i].getY ()+f))
							{
								cout << "(" << points[i].getX () << "," << points[i].getY ()+f << "), ";
								peripoints[count].setX (points[i].getX ());
								peripoints[count].setY (points[i].getY ()+f);
								++count;
							}
						}
					}
				}
			}
		}
		
		// side7 perimeter
		if (points[i].getX () == maxX)
		{
			for (int j = 0; j < CROSSVER; j++)
			{
				if ((points[i].getX () == points[j].getX ()) && (i != j))
				{
					if (points[i].getY() < points[j].getY ())
					{
						// maneuver around the perimeter
						for (int g = 1; g < side7; g++)
						{
							if (isPointOnShape (maxX-g, points[i].getY ()))
							{
								cout << "(" << maxX-g << "," << points[i].getY () << "), ";
								peripoints[count].setX (maxX -g);
								peripoints[count].setY (points[i].getY ());
								++count;
							}
						}
					}
				}
			}
		}
		
		//side8 perimeter
		if (points[i].getY () == minY)
		{
			for (int j = 0; j < CROSSVER; j++)
			{
				if ((points[i].getY () == points[j].getY ()) && (i != j))
				{
					if (points[i].getX() > points[j].getX ())
					{
						// maneuver around the perimeter
						for (int h = 1; h < side8; h++)
						{
							if (isPointOnShape (points[i].getX (), points[i].getY ()+h))
							{
								cout << "(" << points[i].getX () << "," << points[i].getY ()+h << "), ";
								peripoints[count].setX (points[i].getX ());
								peripoints[count].setY (points[i].getY ()+h);
								++count;
							}
						}
					}
				}
			}
		}
		
		// side9 perimeter
		if (points[i].getX () == minX)
		{
			for (int j = 0; j < CROSSVER; j++)
			{
				if ((points[i].getX () == points[j].getX ()) && (i != j))
				{
					if (points[i].getY() > points[j].getY ())
					{
						// maneuver around the perimeter
						for (int k = 1; k < side9; k++)
						{
							if (isPointOnShape (minX+k, points[i].getY ()))
							{
								cout << "(" << minX+k << "," << points[i].getY () << "), ";
								peripoints[count].setX (minX +k);
								peripoints[count].setY (points[i].getY ());
								++count;
							}
						}
					}
				}
			}
		}
		
		//side10 perimeter
		if (points[i].getY () == maxY)
		{
			for (int j = 0; j < CROSSVER; j++)
			{
				if ((points[i].getY () == points[j].getY ()) && (i != j))
				{
					if (points[i].getX() < points[j].getX ())
					{
						// maneuver around the perimeter
						for (int l = 1; l < side10; l++)
						{
							if (isPointOnShape (points[i].getX (), maxY-l))
							{
								cout << "(" << points[i].getX () << "," << maxY-l << "), ";
								peripoints[count].setX (points[i].getX ());
								peripoints[count].setY (maxY -l);
								++count;
							}
						}
					}
				}
			}
		}
		
		// side11 perimeter
		if (points[i].getX () == maxX)
		{
			for (int j = 0; j < CROSSVER; j++)
			{
				if ((points[i].getX () == points[j].getX ()) && (i != j))
				{
					if (points[i].getY() > points[j].getY ())
					{
						// maneuver around the perimeter
						for (int m = 1; m < side11; m++)
						{
							if (isPointOnShape (maxX-m, points[i].getY ()))
							{
								cout << "(" << maxX-m << "," << points[i].getY () << "), ";
								peripoints[count].setX (maxX -m);
								peripoints[count].setY (points[i].getY ());
								++count;
							}
						}
					}
				}
			}
		}
		
		//side12 perimeter
		if (points[i].getY () == maxY)
		{
			for (int j = 0; j < CROSSVER; j++)
			{
				if ((points[i].getY () == points[j].getY ()) && (i != j))
				{
					if (points[i].getX() > points[j].getX ())
					{
						// maneuver around the perimeter
						for (int n = 1; n < side12; n++)
						{
							if (isPointOnShape (points[i].getX (), maxY-n))
							{
								cout << "(" << points[i].getX () << "," << maxY-n << "), ";
								peripoints[count].setX (points[i].getX ());
								peripoints[count].setY (maxY -n);
								++count;
							}
						}
					}
				}
			}
		}
		
	}
	
	cout << endl << endl;
}

void Cross::getWithinShapePoints ()
{	
	int minX = points[0].getX (); // left side of cross
	int minY = points[0].getY (); // bottom side of cross
	int maxX = points[0].getX (); // right side of cross
	int maxY = points[0].getY (); // top side of cross
	
	cout << "Points within shape : ";
	
	for (int i = 1; i < CROSSVER; i++)
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
	
	for (int i = 0; i < CROSSVER; i++)
	{
		// left side of cross
		if (points[i].getX () == minX)
		{
			for (int j = 0; j < CROSSVER; j++)
			{
				if ((points[i].getX () == points[j].getX ()) && (i != j))
				{
					if (points[i].getY() < points[j].getY ())
					{	
						// maneuver up side 1
						for (int a = 1; a < side1; a++)
						{
							// maneuver right side 5 (inside)
							for (int b = 1; b <= side5; b++)
							{
								if (isPointInShape (minX+b, points[i].getY ()+a))
								{
									cout << "(" << minX+b << "," << points[i].getY ()+a << "), ";
									areapoints[countA].setX (minX+b);
									areapoints[countA].setY (points[i].getY () +a);
									++countA;
								}
							}
						}
					}
				}
			}
		}
		
		// bottom side of cross
		if (points[i].getY () == minY)
		{
			for (int j = 0; j < CROSSVER; j++)
			{
				if ((points[i].getY () == points[j].getY ()) && (i != j))
				{
					if (points[i].getX() < points[j].getX ())
					{	
						// maneuver right side 2
						for (int a = 1; a < side2; a++)
						{
							// maneuver up side 6 (inside)
							for (int b = 1; b <= side6; b++)
							{
								if (isPointInShape (points[i].getX () -a, minY+b))
								{
									cout << "(" << points[i].getX () -a << "," << minY+b << "), ";
									areapoints[countA].setX (points[i].getX ()-a);
									areapoints[countA].setY (minY+b);
									++countA;
								}
							}
						}
					}
				}
			}
		}
		
		// right side of cross
		if (points[i].getX () == maxX)
		{
			for (int j = 0; j < CROSSVER; j++)
			{
				if ((points[i].getX () == points[j].getX ()) && (i != j))
				{
					if (points[i].getY() < points[j].getY ())
					{	
						// maneuver up side 3
						for (int a = 1; a < side3; a++)
						{
							// maneuver left side 7 (inside)
							for (int b = 1; b <= side7; b++)
							{
								if (isPointInShape (maxX-a, points[i].getY ()+b))
								{
									cout << "(" << maxX-a << "," << points[i].getY ()+b << "), ";
									areapoints[countA].setX (maxX-a);
									areapoints[countA].setY (points[i].getY ()+b);
									++countA;
								}
							}
						}
					}
				}
			}
		}
		
		// top side of cross
		if (points[i].getY () == maxY)
		{
			for (int j = 0; j < CROSSVER; j++)
			{
				if ((points[i].getY () == points[j].getY ()) && (i != j))
				{
					if (points[i].getX() < points[j].getX ())
					{	
						// maneuver right side 4
						for (int a = 1; a < side4; a++)
						{
							// maneuver down side 10 (inside)
							for (int b = 1; b <= side10; b++)
							{
								if (isPointInShape (points[i].getX () +b, maxY-a))
								{
									cout << "(" << points[i].getX () +b << "," << maxY-a << "), ";
									areapoints[countA].setX (points[i].getX () +b);
									areapoints[countA].setY (maxY-a);
									++countA;
								}
							}
						}
					}
				}
			}
		}
		
	}
	
	cout << endl << endl;
}

double Cross::computePerimeter ()
{
	return this->side1 + this->side2 + this->side3 + this->side4 + 
	       this->side5 + this->side6 + this->side7 + this->side8 +
	       this->side9 + this->side10 + this->side11 + this->side12;
}

void Cross::displayMap ()
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
		cout << "Display cross map:"
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
			   << "\t \"x\" - points of cross" << endl
			   << "\t \"?\" - area points" << endl;

		cout << endl << endl;
	}
}


string Cross::print () const
{
	stringstream oss;
	oss << s << endl
	    << setprecision (0) << fixed
	    << "Area         : " << round (area) << " units square" << endl
	    << "Perimeter    : " << round (perimeter) << " units" << endl
	    << *points << endl;
	    for (int i = 0; i < CROSSVER; i++)
	    {
	    	oss << "Points [" << i << "]   : (" << points[i].getX() << ", " << points[i].getY() << ")" << endl;
	    }
	
	return (oss.str());
}

bool Cross::isPointInShape (int x, int y)
{
	int minX = points[0].getX (); // left side of cross
	int minY = points[0].getY (); // bottom side of cross
	int maxX = points[0].getX (); // right side of cross
	int maxY = points[0].getY (); // top side of cross
	
	for (int i = 1; i < CROSSVER; i++)
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
	
	for (int i = 0; i < CROSSVER; i++)
	{
		// left side of cross
		if (points[i].getX () == minX)
		{
			for (int j = 0; j < CROSSVER; j++)
			{
				if ((points[i].getX () == points[j].getX ()) && (i != j))
				{
					if (points[i].getY() < points[j].getY ())
					{
						// maneuver up side 1
						for (int a = 1; a < side1; a++)
						{
							// maneuver right side 5 (inside)
							for (int b = 1; b <= side5; b++)
							{
								if ((minX+b == x) && (points[i].getY ()+a == y))
								{
									return true;
								}
							}
						}
					}
				}
			}
		}	
		
		// bottom side of cross
		if (points[i].getY () == minY)
		{
			for (int j = 0; j < CROSSVER; j++)
			{
				if ((points[i].getY () == points[j].getY ()) && (i != j))
				{
					if (points[i].getX() < points[j].getX ())
					{	
						// maneuver right side 2
						for (int a = 1; a < side2; a++)
						{
							// maneuver up side 6 (inside)
							for (int b = 1; b <= side6; b++)
							{
								if ((points[i].getX () +a == x) && (minY+b == y))
								{
									return true;
								}
							}
						}
					}
				}
			}
		}
		
		// right side of cross
		if (points[i].getX () == maxX)
		{
			for (int j = 0; j < CROSSVER; j++)
			{
				if ((points[i].getX () == points[j].getX ()) && (i != j))
				{
					if (points[i].getY() < points[j].getY ())
					{	
						// maneuver up side 3
						for (int a = 1; a < side3; a++)
						{
							// maneuver left side 7 (inside)
							for (int b = 1; b <= side7; b++)
							{
								if ((maxX-a == x) && (points[i].getY ()+b == y))
								{
									return true;
								}
							}
						}
					}
				}
			}
		}
		
		// top side of cross
		if (points[i].getY () == maxY)
		{
			for (int j = 0; j < CROSSVER; j++)
			{
				if ((points[i].getY () == points[j].getY ()) && (i != j))
				{
					if (points[i].getX() < points[j].getX ())
					{	
						// maneuver right side 4
						for (int a = 1; a < side4; a++)
						{
							// maneuver down side 10 (inside)
							for (int b = 1; b <= side10; b++)
							{
								if ((points[i].getX () +b == x) && (maxY-a == y))
								{
									return true;
								}
							}
						}
					}
				}
			}
		}
		
	}
	
	return false;
}
	
bool Cross::isPointOnShape (int x, int y)
{
	int minX = points[0].getX (); // left side of cross
	int minY = points[0].getY (); // bottom side of cross
	int maxX = points[0].getX (); // right side of cross
	int maxY = points[0].getY (); // top side of cross
	
	for (int i = 1; i < CROSSVER; i++)
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
	
	for (int i = 0; i < CROSSVER; i++)
	{
		// side1 perimeter
		if (points[i].getX () == minX)
		{
			for (int j = 0; j < CROSSVER; j++)
			{
				if ((points[i].getX () == points[j].getX ()) && (i != j))
				{
					if (points[i].getY() < points[j].getY ())
					{
						// maneuver around the perimeter
						for (int a = 1; a < side1; a++)
						{
							if ((minX == x) && (points[i].getY ()+a == y))
							{
								return true;
							}
						}
					}
				}
			}
		}
		
		//side2 perimeter
		if (points[i].getY () == minY)
		{
			for (int j = 0; j < CROSSVER; j++)
			{
				if ((points[i].getY () == points[j].getY ()) && (i != j))
				{
					if (points[i].getX() < points[j].getX ())
					{
						// maneuver around the perimeter
						for (int b = 1; b < side2; b++)
						{
							if ((points[i].getX ()+b == x) && (minY == y))
							{
								return true;
							}
						}
					}
				}
			}
		}
		
		//side3 perimeter
		if (points[i].getX () == maxX)
		{
			for (int j = 0; j < CROSSVER; j++)
			{
				if ((points[i].getX () == points[j].getX ()) && (i != j))
				{
					if (points[i].getY() < points[j].getY ())
					{
						// maneuver around the perimeter
						for (int c = 1; c < side3; c++)
						{
							if ((maxX == x) && (points[i].getY ()+c == y))
							{
								return true;
							}
						}
					}
				}
			}
		}
		
		//side4 perimeter
		if (points[i].getY () == maxY)
		{
			for (int j = 0; j < CROSSVER; j++)
			{
				if ((points[i].getY () == points[j].getY ()) && (i != j))
				{
					if (points[i].getX() < points[j].getX ())
					{
						// maneuver around the perimeter
						for (int d = 1; d < side4; d++)
						{
							if ((points[i].getX ()+d == x) && (minY == y))
							{
								return true;
							}
						}
					}
				}
			}
		}
		
		// side5 perimeter
		if (points[i].getX () == minX)
		{
			for (int j = 0; j < CROSSVER; j++)
			{
				if ((points[i].getX () == points[j].getX ()) && (i != j))
				{
					if (points[i].getY() < points[j].getY ())
					{
						// maneuver around the perimeter
						for (int e = 1; e < side5; e++)
						{
							if ((minX+e == x) && (points[i].getY () == y))
							{
								return true;
							}
						}
					}
				}
			}
		}
		
		//side6 perimeter
		if (points[i].getY () == minY)
		{
			for (int j = 0; j < CROSSVER; j++)
			{
				if ((points[i].getY () == points[j].getY ()) && (i != j))
				{
					if (points[i].getX() < points[j].getX ())
					{
						// maneuver around the perimeter
						for (int f = 1; f < side6; f++)
						{
							if ((points[i].getX () == x) && (points[i].getY ()+f == y))
							{
								return true;
							}
						}
					}
				}
			}
		}
		
		// side7 perimeter
		if (points[i].getX () == maxX)
		{
			for (int j = 0; j < CROSSVER; j++)
			{
				if ((points[i].getX () == points[j].getX ()) && (i != j))
				{
					if (points[i].getY() < points[j].getY ())
					{
						// maneuver around the perimeter
						for (int g = 1; g < side7; g++)
						{
							if ((maxX-g == x) && (points[i].getY () == y))
							{
								return true;
							}
						}
					}
				}
			}
		}
		
		//side8 perimeter
		if (points[i].getY () == minY)
		{
			for (int j = 0; j < CROSSVER; j++)
			{
				if ((points[i].getY () == points[j].getY ()) && (i != j))
				{
					if (points[i].getX() > points[j].getX ())
					{
						// maneuver around the perimeter
						for (int h = 1; h < side8; h++)
						{
							if ((points[i].getX () == x) && (points[i].getY ()+h == y))
							{
								return true;
							}
						}
					}
				}
			}
		}
		
		// side9 perimeter
		if (points[i].getX () == minX)
		{
			for (int j = 0; j < CROSSVER; j++)
			{
				if ((points[i].getX () == points[j].getX ()) && (i != j))
				{
					if (points[i].getY() > points[j].getY ())
					{
						// maneuver around the perimeter
						for (int k = 1; k < side9; k++)
						{
							if ((minX+k == x) && (points[i].getY () == y))
							{
								return true;
							}
						}
					}
				}
			}
		}
		
		//side10 perimeter
		if (points[i].getY () == maxY)
		{
			for (int j = 0; j < CROSSVER; j++)
			{
				if ((points[i].getY () == points[j].getY ()) && (i != j))
				{
					if (points[i].getX() < points[j].getX ())
					{
						// maneuver around the perimeter
						for (int l = 1; l < side10; l++)
						{
							if ((points[i].getX () == x) && (maxY-l == y))
							{
								return true;
							}
						}
					}
				}
			}
		}
		
		// side11 perimeter
		if (points[i].getX () == maxX)
		{
			for (int j = 0; j < CROSSVER; j++)
			{
				if ((points[i].getX () == points[j].getX ()) && (i != j))
				{
					if (points[i].getY() > points[j].getY ())
					{
						// maneuver around the perimeter
						for (int m = 1; m < side11; m++)
						{
							if ((maxX-m == x) && (points[i].getY () == y))
							{
								return true;
							}
						}
					}
				}
			}
		}
		
		//side12 perimeter
		if (points[i].getY () == maxY)
		{
			for (int j = 0; j < CROSSVER; j++)
			{
				if ((points[i].getY () == points[j].getY ()) && (i != j))
				{
					if (points[i].getX() > points[j].getX ())
					{
						// maneuver around the perimeter
						for (int n = 1; n < side12; n++)
						{
							if ((points[i].getX () == x) && (maxY-n == y))
							{
								return true;
							}
						}
					}
				}
			}
		}
	}
	
	return false;
}

void Cross::setShape (ShapeTwoD s)
{
	this->s = s;
}

void Cross::setVertexX (int index, int value)
{
	points[index].setX (value);
}

void Cross::setVertexY (int index, int value)
{
	points[index].setY (value);
}

void Cross::setSides ()
{
	int side1 = 0;
	int side2 = 0;
	int side3 = 0;
	int side4 = 0;
	int side5 = 0;
	int side6 = 0;
	int side7 = 0;
	int side8 = 0;
	int side9 = 0;
	int side10 = 0;
	int side11 = 0;
	int side12 = 0;
	int min;
	int max;
	
/*	
7
6   x x
5   x x
4 x x x x 
3 x x x x
2 x x x x 
1   x x
0   x x 
  0 1 2 3 4 5 6 7 8

// length
(0, 2) - (3, 2)
(0, 4) - (3, 4)

// square1/rectangle1
(1, 6) - (2, 6)
(1, 4) - (2, 4)

// square2/rectangle2
(1, 0) - (1, 2)
(2, 0) - (2, 2)
*/

	int minX = points[0].getX (); // left side of cross
	int minY = points[0].getY (); // bottom side of cross
	int maxX = points[0].getX (); // right side of cross
	int maxY = points[0].getY (); // top side of cross
	
	for (int i = 1; i < CROSSVER; i++)
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
	
	for (int i = 0; i < CROSSVER; i++)
	{
		// left side of cross
		if (points[i].getX () == minX)
		{
			for (int j = 0; j < CROSSVER; j++)
			{
				if ((points[i].getX () == points[j].getX ()) && (i != j))
				{
					if (points[i].getY() > points[j].getY ())
					{
						this->side1 = points[i].getY () - points[j].getY ();
					}
					else if (points[i].getY () < points[j].getY ())
					{
						this->side1 = points[j].getY () - points[i].getY ();
					}
					else
					{
						this->side1 = side1;
					}
				}
			}
		}
	
		// bottom side of cross
		if (points[i].getY () == minY)
		{
			for (int j = 0; j < CROSSVER; j++)
			{
				if ((points[i].getY () == points[j].getY ()) && (i != j))
				{
					if (points[i].getX() > points[j].getX ())
					{
						this->side2 = points[i].getX () - points[j].getX ();
					}
					else if (points[i].getY () < points[j].getY ())
					{
						this->side2 = points[j].getX () - points[i].getX ();
					}
					else
					{
						this->side2 = side2;
					}
				}
			}
		}
	
		// right side of cross
		if (points[i].getX () == maxX)
		{
			for (int j = 0; j < CROSSVER; j++)
			{
				if ((points[i].getX () == points[j].getX ()) && (i != j))
				{
					if (points[i].getY() > points[j].getY ())
					{
						this->side3 = points[i].getY () - points[j].getY ();
					}
					else if (points[i].getY () < points[j].getY ())
					{
						this->side3 = points[j].getY () - points[i].getY ();
					}
				}
			}
		}
	
		// top side of cross
		if (points[i].getY () == maxY)
		{
			for (int j = 0; j < CROSSVER; j++)
			{
				if ((points[i].getY () == points[j].getY ()) && (i != j))
				{
					if (points[i].getX() > points[j].getX ())
					{
						this->side4 = points[i].getX () - points[j].getX ();
					}
					else if (points[i].getY () < points[j].getY ())
					{
						this->side4 = points[j].getX () - points[i].getX ();
					}
				}
			}
		}
	
		min = maxX;
		// left-bottom side of cross
		if (points[i].getX () == minX)
		{
			for (int j = 0; j < CROSSVER; j++)
			{
				if ((points[i].getX () == points[j].getX ()) && (i != j))
				{
					if (points[i].getY () < points[j].getY ()) // getting the lower grid of left side
					{
						for (int k = 0; k < CROSSVER; k++)
						{
							if ((points[k].getY () == points[i].getY ()) && (i != k)) // inner grid Y
							{
								if (points[k].getX () < min)
								{
									min = points[k].getX (); // inner grid X
								}
							}
							
							this->side5 = min - minX;
							this->side6 = points[k].getY () - minY;
						}
					}
				}
			}
		}
		
		max = minX;
		// right-bottom side of cross
		if (points[i].getX () == maxX)
		{
			for (int j = 0; j < CROSSVER; j++)
			{
				if ((points[i].getX () == points[j].getX ()) && (i != j))
				{
					if (points[i].getY () < points[j].getY ()) // getting the lower grid of left side
					{
						for (int k = 0; k < CROSSVER; k++)
						{
							if ((points[k].getY () == points[i].getY ()) && (i != k)) // inner grid Y
							{
								if (points[k].getX () > max)
								{
									max = points[k].getX (); // inner grid X
								}
							}
							
							this->side7 = maxX - max;
							this->side8 = points[k].getY () - minY;
						}
					}
				}
			}
		}
	}
	
	// subtracting the balance length sides using from the calculated sides above
	// left-top side of cross
	this->side9 = maxX - this->side4 - this->side7;
	this->side10 = maxY - this->side1 - this->side6;
	
	// right-top side of cross
	this->side11 = maxX - this->side2 - this->side9;
	this->side12 = maxY - this->side3 - this->side8;
}

void Cross::setArea (double area)
{
	this->area = area;
}

void Cross::setPerimeter (double perimeter)
{
	this->perimeter = perimeter;
}
