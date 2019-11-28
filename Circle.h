#ifndef CIRCLE_H
#define CIRCLE_H
#include "ShapeTwoD.h"
#include "Vertex.h"

class Circle : public ShapeTwoD
{
	friend ostream& operator<< (ostream&, const Circle&);
	
	public:
		// default constructor
		Circle (ShapeTwoD);
		
		// other constructor
		Circle (ShapeTwoD, int, int, int); // values for radius, x and y
		
		// destructor
		~Circle ();
		
		// copy constructor
		Circle (const Circle&);
		
		// accessor methods
		ShapeTwoD getShape ();
		
		Vertex getVertex (int) override;
		
		int getX ();
		
		int getY ();
		
		int getRadius ();
		
		double getPerimeter ();
		
		int getID () override;
		
		void getPerimeterPoints () override;
		
		void getWithinShapePoints () override;
		
		double getArea () override;
		
		// operations
		double computeArea () override;
		
		double computePerimeter () override;
		
		bool isPointInShape (int, int) override;
	
		bool isPointOnShape (int, int) override;
	
		string print () const override;
		
		void displayMap () override;
		
		// mutator methods
		void setShape (ShapeTwoD);
		
		void setX (int);
		
		void setY (int);
		
		void setRadius (int);
		
		void setSides () override;
		
		void setArea (double) override;
		
		void setPerimeter (double) override;
		
		void setVertex (int, int);
		
	private:
	
		ShapeTwoD s;
		Vertex * points;
		Vertex * areapoints;
		int x;
		int y;
		int radius;
		double area;
		double perimeter;
		static int id;
		static int countA;
};

#endif

