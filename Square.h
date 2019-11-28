#ifndef SQUARE_H
#define SQUARE_H
#include "ShapeTwoD.h"
#include "Vertex.h"

class Square : public ShapeTwoD
{
	friend ostream& operator<< (ostream&, const Square&);
	
	public:
		// default constructor
		Square (ShapeTwoD);
		
		// other constructor
		Square (ShapeTwoD, Vertex*); // contain values for x and y
		
		// destructor
		~Square ();
		
		// copy constructor
		Square (const Square&);
		
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
