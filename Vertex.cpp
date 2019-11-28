#include "Vertex.h"

int Vertex::index = 0;

// Vertex class definition
ostream& operator<< (ostream& os, const Vertex& points)
{
	os << points.display ();
	return os;
}

Vertex::Vertex ()
{
	this->x = 0;
	this->y = 0;
	this->found = false;
	this->index = index;
	++this->index;
}

Vertex::Vertex (int x, int y)
{
	this->x = x;
	this->y = y;
	this->found = false;
	this->index = index;
	++this->index;
}

Vertex::~Vertex () 
{
	// let compiler do it
}

Vertex::Vertex (const Vertex& points)
{
	this->x = points.x;
	this->y = points.y;
	this->found = false;
}


int Vertex::getX ()
{
	return x;
}

int Vertex::getY ()
{
	return y;
}

bool Vertex::getFound ()
{
	return found;
}
		
void Vertex::setX (int x)
{
	this->x = x;
}

void Vertex::setY (int y)
{
	this->y = y;
}

void Vertex::setFound (bool found)
{
	this->found = found;
}

string Vertex::display () const
{
	stringstream oss;
	oss << "Vertices     : ";
	 
	return (oss.str ());
}
