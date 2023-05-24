#include "SetOfStrings.h"

using namespace std;

/*
 * Returns the total number of elements in the set.
 */
int SetOfStrings::size(){
    return (int) elements.size();
}

/*
 * Inserts an element into the set.
 */
void SetOfStrings::insertElement(string s)
{
    if(!isMember(s)){
        elements.push_back(s);
    }
}

/*
 * Returns a specific element from the set.
 * Returns "" if nothing to return.
 */
string SetOfStrings::returnElement(int index)
{
	if(index > size() || index < 0) return "";
	return elements.at(index);
}

/*
 * Finds a specific element.
 * Returns true if exist, otherwise false.
 */
bool SetOfStrings::isMember(string s)
{
	if (find(elements.begin(), elements.end(), s) != elements.end()){
		return true;
	}
	else{
		return false;
	}
}

/*
 * Gets the elements of the object
 */
vector<string> SetOfStrings::getElements()
{
	return this->elements;
}

