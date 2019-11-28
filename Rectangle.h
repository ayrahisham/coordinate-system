#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "ShapeTwoD.h"
#include "Vertex.h"

class Rectangle : public ShapeTwoD
{
	friend ostream& operator<< (ostream&, const Rectangle&);
	
	public:
		// default constructor
		Rectangle (ShapeTwoD);
		
		// other constructor
		Rectangle (ShapeTwoD, Vertex*); // contain values for x and y
		
		// destructor
		~Rectangle ();
		
		// copy constructor
		Rectangle (const Rectangle&);
		
		// accessor methods
		ShapeTwoD getShape ();
		
		Vertex getVertex (int) override;
		
		double getPerimeter ();
		
		int getID () override;
		
		void getPerimeterPoints () override;
		
		void getWithinShapePoints () override;
		
		double getArea () override;
		
		// operations
		string print () const override;
		
		double computeArea () override;
		
		double computePerimeter () override;
		
		bool isPointInShape (int, int) override;
	
		bool isPointOnShape (int, int) override;
		
		void displayMap () override;
		
		// mutator methods
		void setShape (ShapeTwoD);
		
		void setVertexX (int, int);
		
		void setVertexY (int, int);
		
		void setSides () override;
		
		void setArea (double) override;
		
		void setPerimeter (double) override;
		
	private:
		ShapeTwoD s;
		Vertex * points;
		Vertex * peripoints;
		Vertex * areapoints;
		double area;
		int side1;
		int side2;
		int side3;
		int side4;
		double perimeter;
		static int id;
		static int count;
		static int countA;
};

#endif
