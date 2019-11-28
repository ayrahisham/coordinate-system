#include "A2.h"
#include "ShapeTwoD.cpp"
#include "Cross.cpp"
#include "Square.cpp"
#include "Rectangle.cpp"
#include "Circle.cpp"
#include "Vertex.cpp"

int main()
{
	int choice;
	char option;
	string shape;
	char * shapeC;
	string type;
	ShapeTwoD * s [SIZE];
	Cross * cr [SIZE];
	Square * sq [SIZE];
	Rectangle * r [SIZE];
	Circle * c [SIZE];
	// keep track of shape array index & total no. of shapes
	static int counter = 0; 
	static int crSize = 0; // total no. of crosses
	static int sqSize = 0; // total no. of squares
	static int rSize = 0; // total no. of rectangles
	static int cSize = 0; // total no. of circles
	double * areaArr; // creating array of pointers to store all shapes' area
	
	do
	{
		// return valid option after displaying main menu to user
		choice = checkValidOption (displayMenuOptions());
		
		switch (choice)
		{
			case 1: cout << endl
			             << "[ Input sensor data ]" 
			             << endl << endl;
			             
			        // retrieve shape data from user
				shape = getShape ();
				// create same memory space as user's shape input
				shapeC = new char [shape.length() + 1];
				// copy user input to new char pointer
				strcpy (shapeC, shape.c_str());
				
				// get type from user
				type = getType ();
				
				// storing data in shapes
				// if type input = ws means true for warp space
				cout << endl;
				
				// splitting the shapes into individual classes
				if (shape.find ("cross") != string::npos)
				{	
					// re-using same const value for char array size
					int x [CROSSVER]; 
					int y [CROSSVER];
					bool ok;
					
					do
					{
						ok = false;
						for (int i = 0; i < CROSSVER; i++)
						{
							// entering x coordinates for cross shape
							do
							{
								cout << "Please enter x-ordinate of pt. " << i+1 << " : ";
								cin >> x[i];
								if (cin.good ())
								{
									ok = true;
								}
							}
							while (ok == false);
					
						  ok = false;
							// entering y coordinates for cross shape
							do
							{
								cout << "Please enter y-ordinate of pt. " << i+1 << " : ";
								cin >> y[i];
								if (cin.good ())
								{
									ok = true;
								}
							}
							while (ok == false);
							
							cout << endl;
						}
						
						cout << endl;
					
						ok = false;
						// checking for non-duplicated grids
						for (int i = 0; i < CROSSVER; i++)
						{
							for (int j = 0; j < CROSSVER; j++)
							{
								if ((i != j) && (x[i] != x[j]) && (y[i] != y[j]))
								{
									ok = true;
								}
							}
						}	
					} while (ok == false);
					
					if (type.compare ("WS") == 0)
					{
						s[counter] = new ShapeTwoD (shapeC, true);
						cr[crSize] = new Cross (*s[counter]);
					}
					else
					{
						s[counter] = new ShapeTwoD (shapeC, false);
						cr[crSize] = new Cross (*s[counter]);
					}
					
					// once all data are correct then set in cross class
					for (int i = 0; i < CROSSVER; i++)
					{
						cr[crSize]->setVertexX (i, x[i]);
						cr[crSize]->setVertexY (i, y[i]);
					}
					
					s[counter] = cr[crSize];
					if (type.compare ("WS") == 0)
					{
						s[counter]->setContainsWarpSpace (true);
					}
					++crSize;
				}
				else if (shape.find ("square") != string::npos)
				{
					// re-using same const value for char array size
					int x [VERTICES]; 
					int y [VERTICES];
					bool ok;
					
					do
					{
						ok = false;
						for (int i = 0; i < VERTICES; i++)
						{
							// entering x coordinates for cross shape
							do
							{
								cout << "Please enter x-ordinate of pt. " << i+1 << " : ";
								cin >> x[i];
								if (cin.good ())
								{
									ok = true;
								}
							}
							while (ok == false);
					
						  ok = false;
							// entering y coordinates for cross shape
							do
							{
								cout << "Please enter y-ordinate of pt. " << i+1 << " : ";
								cin >> y[i];
								if (cin.good ())
								{
									ok = true;
								}
							}
							while (ok == false);
							
							cout << endl;
						}
						cout << endl;
					
						ok = false;
						// checking for non-duplicated grids
						for (int i = 0; i < VERTICES; i++)
						{
							for (int j = 0; j < VERTICES; j++)
							{
								if ((i != j) && (x[i] != x[j]) && (y[i] != y[j]))
								{
									ok = true;
								}
							}
						}	
						
					} while (ok == false);
					
					if (type.compare ("WS") == 0)
					{
						s[counter] = new ShapeTwoD (shapeC, true);
						sq[sqSize] = new Square (*s[counter]);
					}
					else
					{
						s[counter] = new ShapeTwoD (shapeC, false);
						sq[sqSize] = new Square (*s[counter]);
					}
					
					// once all data are correct then set in cross class
					for (int i = 0; i < VERTICES; i++)
					{
						sq[sqSize]->setVertexX (i, x[i]);
						sq[sqSize]->setVertexY (i, y[i]);
					}
					
					s[counter] = sq[sqSize];
					if (type.compare ("WS") == 0)
					{
						s[counter]->setContainsWarpSpace (true);
					}
					++sqSize;	
				}
				else if (shape.find ("rectangle") != string::npos)
				{
					// re-using same const value for char array size
					int x [VERTICES]; 
					int y [VERTICES];
					bool ok;
					
					do
					{
						ok = false;
						for (int i = 0; i < VERTICES; i++)
						{
							// entering x coordinates for cross shape
							do
							{
								cout << "Please enter x-ordinate of pt. " << i+1 << " : ";
								cin >> x[i];
								if (cin.good ())
								{
									ok = true;
								}
							}
							while (ok == false);
					
						  ok = false;
							// entering y coordinates for cross shape
							do
							{
								cout << "Please enter y-ordinate of pt. " << i+1 << " : ";
								cin >> y[i];
								if (cin.good ())
								{
									ok = true;
								}
							}
							while (ok == false);
							
							cout << endl;
						}
						cout << endl;
					
						ok = false;
						// checking for non-duplicated grids
						for (int i = 0; i < VERTICES; i++)
						{
							for (int j = 0; j < VERTICES; j++)
							{
								if ((i != j) && (x[i] != x[j]) && (y[i] != y[j]))
								{
									ok = true;
								}
							}
						}	
					} while (ok == false);
					
					if (type.compare ("WS") == 0)
					{
						s[counter] = new ShapeTwoD (shapeC, true);
						r[rSize] = new Rectangle (*s[counter]);
					}
					else
					{
						s[counter] = new ShapeTwoD (shapeC, false);
						r[rSize] = new Rectangle (*s[counter]);
					}
					
					// once all data are correct then set in cross class
					for (int i = 0; i < VERTICES; i++)
					{
						r[rSize]->setVertexX (i, x[i]);
						r[rSize]->setVertexY (i, y[i]);
					}
					
					s[counter] = r[rSize];
					if (type.compare ("WS") == 0)
					{
						s[counter]->setContainsWarpSpace (true);
					}
					++rSize;
				}
				else if (shape.find ("circle") != string::npos)
				{
					int x;
					int y;
					int radius;
					bool ok;
								
					if (type.compare ("WS") == 0)
					{
						s[counter] = new ShapeTwoD (shapeC, true);
						c[cSize] = new Circle (*s[counter]);
					}
					else
					{
						s[counter] = new ShapeTwoD (shapeC, false);
						c[cSize] = new Circle (*s[counter]);
					}
					
					// entering x coordinate for circle shape
					do
					{
						ok = false;
						cout << "Please enter x-ordinate of center : ";
						cin >> x;
						if (cin.good ())
						{
							ok = true;
							c[cSize]->setX (x);
						}
					}
					while (ok == false);
					
					// entering y coordinate for circle shape
					do
					{
						ok = false;
						cout << "Please enter y-ordinate of center : ";
						cin >> y;
						if (cin.good ())
						{
							ok = true;
							c[cSize]->setY (y);
						}
					}
					while (ok == false);
					
					// entering radius for circle shape
					do
					{
						ok = false;
						cout << "Please enter radius (units) : ";
						cin >> radius;
						if ((cin.good ()) && (radius > 0))
						{
							ok = true;
							c[cSize]->setRadius (radius);
						}
					}
					while (ok == false);
					
					cout << endl;
					
					s[counter] = c[cSize];
					if (type.compare ("WS") == 0)
					{
						s[counter]->setContainsWarpSpace (true);
					}
					++cSize;
				}
				cout << endl
				     << "Record successfully stored. Going back to main menu..."
				     << endl;
				++counter;
				delete [] shapeC;
				break;
			case 2: cout << endl
			             << "[ Compute area & perimeter (for all records) ]" 
			             << endl << endl;
				
				// at least 1 shape created hence
				if (counter > 0)
				{	
					// do a check that size matches the total no. of shapes created
					if (counter == cSize + rSize + sqSize + crSize)
					{
						// computing circle area
						// computing cross area
						// computing square area
						// computing rectangle area
						
						double area;
						double peri;
						for (int i = 0; i < counter; i++)
						{
							s[i]->setSides ();
							area = s[i]->computeArea ();
							s[i]->setArea (area);
							peri = s[i]->computePerimeter ();
							s[i]->setPerimeter (peri);
						}
					}
					
					cout << "Computation completed! " << endl;
				}
				else
				{
					cout << endl
			         << "There is no record to display..." << endl
			         << "\t Enter option 1 to input sensor data"
			         << endl << endl;
				}
				cout << "("
				     << counter
				     << " record(s) were updated!)"
				     << endl;
				break;
			case 3: cout << endl
				     << "[ Print Shape Report ]" 
			             << endl << endl
					     << "Total no. of records available = "
							 << counter << endl;
				
				// there are shape(s) stored
				if (counter > 0)
				{
					
					for (int i = 0; i < counter; i++)
					{
						cout << endl
						     << "Shape [" << i << "]" << endl;
						
						cout << *s[i] << endl;
						s[i]->getPerimeterPoints ();
						s[i]->getWithinShapePoints ();
						s[i]->displayMap ();
					}
			   }
			   else
			   {
			   	cout << endl
			         << "There is no record to display..." << endl
			         << "\t Enter option 1 to input sensor data"
			         << endl << endl;
			   }
				break;
			case 4: option = checkValidSortOption (displaySortOptions());
				if (option == 'q')
				{
					break;
				}
				else 
				{
					// if there is at least a shape
					if (counter > 0)
					{
						bool ok = true;
						areaArr= new double [counter];
						
						// check all areas of shapes are computed
						// e.g. circle, cross, square, rectangle
						for (int i = 0; i < counter; i++)
						{
							if (s[i]->getArea () == 0)
							{
								ok = false;
							}
						}
						
						if (ok) // all shapes' area are computed
						{
							// check counter is the total number of shapes created
							// to avoid tangling pointers
							int total = cSize + sqSize + crSize + rSize;
							if (total == counter)
							{
								// loop the array with the sizes of shapes
								for (int i = 0; i < counter; i++)
								{
									areaArr[i] = s[i]->getArea ();
								}
							}
						}
						
						if (option == 'a')
						{	
							cout << endl
							     << "Sort by area (smallest to largest)"
							     << endl;
							     					
							if (ok)
							{	
									// check that sPtr is not a nullptr
									bool sPtrOK = true;
									for (int i = 0; i < counter; i++)
									{
										if (s[i] == nullptr)
										{
											sPtrOK = false;
										}
									}
									
									// can compare shapes area to display
									if (sPtrOK)
									{
										// reset sort to false
										for (int i = 0; i < counter; i++)
										{
											s[i]->setSort (false);
										}
										
										//Now we call the sort function
    								sort (areaArr, areaArr + counter, sortAsc);
    								
										// comparing the array size for the min. area
										for (int i = 0; i < counter; i++)
										{
											for (int j = 0; j < counter; j++)
											{
												if ((areaArr[i] == s[j]->getArea ()) && (s[j]->getSort() == false))
												{
													s[j]->setSort (true);
													cout << endl
						     							 << "Shape [" << j << "]" << endl
														   << *s[j] << endl;
												}
											}
										}
									}
									else
									{
										cout << endl
			        	     << "Records have not been processed for reporting..." << endl
			        	     << "\t Enter option 3 to process data for report printing"
			        	     << endl << endl;
									}
							}		
							else
							{
								cout << endl
								     << "Not all areas of shapes is computed..." << endl
								     << "\t Enter option 2 to compute area data"
								     << endl << endl;
							}
						}
						else if (option == 'b')
						{
							cout << endl
							     << "Sort by area (largest to smallest)"
							     << endl;
							     
							if (ok)
							{	
									// check that sPtr is not a nullptr
									bool sPtrOK = true;
									for (int i = 0; i < counter; i++)
									{
										if (s[i] == nullptr)
										{
											sPtrOK = false;
										}
									}
									
									// can compare shapes area to display
									if (sPtrOK)
									{
										// reset sort to false
										for (int i = 0; i < counter; i++)
										{
											s[i]->setSort (false);
										}
										
										//Now we call the sort function
    								sort (areaArr, areaArr + counter, sortDesc);
    								
										// comparing the array size for the max. area
										for (int i = 0; i < counter; i++)
										{
											for (int j = 0; j < counter; j++)
											{
												if ((areaArr[i] == s[j]->getArea ()) && (s[j]->getSort() == false))
												{
													s[j]->setSort (true);
													cout << endl
						     							 << "Shape [" << j << "]" << endl
														   << *s[j] << endl;
												}
											}
										}
									}
									else
									{
										cout << endl
			        	     << "Records have not been processed for reporting..." << endl
			        	     << "\t Enter option 3 to process data for report printing"
			        	     << endl << endl;
									}
							}		
							else
							{
								cout << endl
								     << "Not all areas of shapes is computed..." << endl
								     << "\t Enter option 2 to compute area data"
								     << endl << endl;
							}
						}
						else if (option == 'c')
						{
							cout << endl
							     << "Sort by special type and area"
							     << endl;
							
							if (ok)
							{	
									// check that sPtr is not a nullptr
									bool sPtrOK = true;
									for (int i = 0; i < counter; i++)
									{
										if (s[i] == nullptr)
										{
											sPtrOK = false;
										}
									}
									
									// can compare shapes area to display
									if (sPtrOK)
									{
										// reset sort to false
										for (int i = 0; i < counter; i++)
										{
											s[i]->setSort (false);
										}
										
										//Now we call the sort function
    								sort (areaArr, areaArr + counter, sortDesc);
    								
										// comparing the array size for the max. area based on special type
										// type "WS" first (true value)
										for (int i = 0; i < counter; i++)
										{
											for (int j = 0; j < counter; j++)
											{
												if ((areaArr[i] == s[j]->getArea ()) && (s[j]->getSort() == false))
												{
													if (s[j]->getContainsWarpSpace())
													{
														s[j]->setSort (true);
														cout << endl
								   							 << "Shape [" << j << "]" << endl
																 << *s[j] << endl;
													}
												}
											}
										}
										
										// type "NS" second, (false value)
										for (int i = 0; i < counter; i++)
										{
											for (int j = 0; j < counter; j++)
											{
												if ((areaArr[i] == s[j]->getArea ()) && (s[j]->getSort() == false))
												{
													if (s[j]->getContainsWarpSpace() == false)
													{
														s[j]->setSort (true);
														cout << endl
								   							 << "Shape [" << j << "]" << endl
																 << *s[j] << endl;
													}
												}
											}
										}
									}
									else
									{
										cout << endl
			        	     << "Records have not been processed for reporting..." << endl
			        	     << "\t Enter option 3 to process data for report printing"
			        	     << endl << endl;
									}
							}		
							else
							{
								cout << endl
								     << "Not all areas of shapes is computed..." << endl
								     << "\t Enter option 2 to compute area data"
								     << endl << endl;
							}     		
						}
						
						delete [] areaArr;
					}
					else
					{
						cout << endl
					 	     << "There is no record to display..." << endl
						     << "\t Enter option 1 to input sensor data"
						     << endl << endl;
					}
				} 
				break;
			case 5: // deallocating memory of array pointers used for base and derived classes
							for (int i = 0; i < SIZE; i++) 
							{
								if (cr[i] != nullptr)
								{
    							cr[i] = nullptr;
    						}
							}
							// delete [] cr;
							for (int i = 0; i < SIZE; i++)
							{
								if (sq[i] != nullptr)
								{
									sq[i] = nullptr;
								}
							}
							// delete [] sq
							for (int i = 0; i < rSize; i++)
							{
								if (r[i] != nullptr)
								{
									r[i] = nullptr;
								}
							}
							// delete [] r;
							for (int i = 0; i < cSize; i++)
							{
								if (c[i] != nullptr)
								{
									c[i] = nullptr;
								}
							}
							// delete [] c;
							for (int i = 0; i < counter; i++)
							{
								if (s[i] != nullptr)
								{
									s[i] = nullptr;
								}
							}
							// delete [] s;
				cout << "Thank you for using Enterprise-2D-StarFleet (2DSF) coordinate system!" << endl;
		}
		
	} while (choice != 5);
	
	return 0;
}

