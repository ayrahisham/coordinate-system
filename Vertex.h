#ifndef VERTEX_H
#define VERTEX_H
#include <sstream>
#include <string>
using namespace std;

class Vertex
{
	friend ostream& operator<< (ostream&, const Vertex&);

	public:
		// default constructor
		Vertex ();
		
		// other constructor
		Vertex (int, int); // values for x and y
		
		// destructor
		~Vertex ();
		
		// copy constructor
		Vertex (const Vertex&);
		
		// accessor methods
		int getX ();
		int getY ();
		bool getFound ();
		
		// mutator methods
		void setX (int);
		void setY (int);
		void setFound (bool);
		
		// operations
		string display () const;
		
	private:
		int x;
		int y;
		bool found;
		static int index;
};

#endif
