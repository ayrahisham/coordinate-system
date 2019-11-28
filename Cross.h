#ifndef CROSS_H
#define CROSS_H
#include "ShapeTwoD.h"
#include "Vertex.h"

class Cross : public ShapeTwoD
{
	friend ostream& operator<< (ostream&, const Cross&);;
	
	public:
		// default constructor
		Cross (ShapeTwoD);
		
		// other constructor
		Cross (ShapeTwoD, Vertex*); // contain values for x and y
		
		// destructor
		~Cross ();
		
		// copy constructor
		Cross (const Cross&);
		
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
		int side5;
		int side6;
		int side7;
		int side8;
		int side9;
		int side10;
		int side11;
		int side12;
		double perimeter;
		static int id;
		static int count;
		static int countA;
};

#endif
