#ifndef SetOfStrings_SetOfStrings_h
#define SetOfStrings_SetOfStrings_h

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <stdio.h>

using namespace std;

class SetOfStrings{
	
protected:
    vector<string> elements;
    
public:
	int size();
	bool isMember(string s);
	void insertElement(string s);
	string returnElement(int index);

	 // Gets the elements of the object
	vector<string> getElements();
};

#endif


