#ifndef SHAPETWOD_H
#define SHAPETWOD_H
#include "A2.h"
#include "Vertex.h"
#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
using namespace std;

// All shapes data should be stored in a Shape2D array in the Assn2 driver class. 
// Assume that no more than 100 shapes will be entered into your program at any one time!
class ShapeTwoD
{
	friend ostream& operator<< (ostream&, const ShapeTwoD&);

	public:
		// default constructor
		ShapeTwoD ();
	
		// other constructor
		ShapeTwoD (string, bool);
		
		// destructor
		~ShapeTwoD ();
		
		// copy constructor
		ShapeTwoD (const ShapeTwoD&);
	
		// accessor methods
		string getName ();
	
		bool getContainsWarpSpace ();
		
		bool getSort ();
		
		virtual int getID ();
		
		virtual Vertex getVertex (int);
		
		virtual void getPerimeterPoints ();
		
		virtual void getWithinShapePoints ();
		
		virtual double getArea ();
	
		// operations
		virtual	double computeArea ();
		
		virtual double computePerimeter ();
	
		virtual bool isPointInShape (int, int);
	
		virtual bool isPointOnShape (int, int);
		
		virtual string print () const;
		
		virtual void displayMap ();
	
		// mutator methods
		void setName (string);

		void setContainsWarpSpace (bool);
		
		virtual void setSides ();
		
		virtual void setArea (double);
		
		virtual void setPerimeter (double);
		
		void setSort (bool);
	
	protected:
		
		Vertex * points;
		string name;	
		bool containsWarpSpace;
		bool sort;
		static int id;
	
};

#endif
