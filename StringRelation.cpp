#include "StringRelation.h"
#include <unistd.h>

/*
 * Assign SetMembers.
 */
void StringRelation::setInput(SetOfStrings *s)
{
	SetMembers=s;
}

/*
 * It splits a pair "a,b" into a vector of strings "a", "b".
 * Returns the string vector.
 */
vector<string> StringRelation::makeTokens(string pair){
	vector<string> out;
	vector<string>::iterator p;
	char *a = new char [pair.length()+1];
	strcpy(a,pair.c_str());
	char* token = strtok(a,",");
			int index=0;
				while (token != NULL) {
					out.push_back(token);
					token = strtok(NULL, ",");
					index++;
				}
	return out;
}

/*
 * Returns the equivalence class as a set object.
 */
SetOfStrings *StringRelation::computeEquivalenceClass(string element){
	//If something is equivalant then find the equivalant classes
	SetOfStrings *out = new SetOfStrings();
	vector<string> pair;

	/* Check first element of pair is equal to element then grab each instance where this element is the first element
		of pair and put the second element into the output */
	if (this->isEquivalence() == true)
	{
		for (size_t i = 0; i < (unsigned) this->size(); i++)
		{
			pair = makeTokens(this->elements[i]);

			if (pair[0] == element && out->isMember(pair[1]) == false/*check for double up*/)
			{
				out->insertElement(pair[1]);;
			}
		}
	}
	
	return out;
}

/*
 * Returns true if the relation is reflexive.
 * Otherwise, returns false.
 */
bool StringRelation::isReflexive(){
	//Every element of the set is related to itself

	string memberCheck = "";

	for (size_t i = 0; i < (unsigned) SetMembers->size(); i++)
	{
		memberCheck = SetMembers->getElements()[i] + "," + SetMembers->getElements()[i];
		if (this->isMember(memberCheck) == false || this->verifyRelation() == false)
		{
			return false;
		}
	}
	
	return true;
}

/*
 * Returns true if the relation is symmetric.
 * Otherwise, returns false.
 */
bool StringRelation::isSymmetric(){
	//For every (x,y) a (y,x) must exist

	vector<string> pair;
	string swapPair = "";

	for (size_t i = 0; i < (unsigned) this->size(); i++)
	{
		vector<string> pair = makeTokens(this->elements[i]);
		swapPair = pair[1] + "," + pair[0];

		if (this->isMember(swapPair) == false || this->verifyRelation() == false)
		{
			return false;
		}
	}

	return true;
}

/*
 * Returns true if the relation is transitive.
 * Otherwise, returns false.
 */
bool StringRelation::isTransitive(){
	//Whenever (x,y) and (y,z) then there must be (x,z)
	//If no (x,y) or (y,z) then transitive

	string x = "";
	string y1 = "";
	string y2 = "";
	string z = "";
	string pair = "";

	/* search for y in 2nd pair then check x and z for both pairs and try find valid relationship */
	for (size_t i = 0; i < (unsigned) this->size(); i++)
	{
		x = makeTokens(this->elements[i])[0];
		y1 = makeTokens(this->elements[i])[1];
		for (size_t j = 0; j < (unsigned) this->size(); j++)
		{
			y2 = makeTokens(this->elements[j])[0];
			z = makeTokens(this->elements[j])[1];
			if (y1 == y2 && y1 != "")
			{
				pair = x + "," + z;
				if (this->isMember(pair) == false || this->verifyRelation() == false)
				{
					return false;
				}
			}
		}
	}

	return true;
}

/*
 * Returns true if the relation is the equivalence relation.
 * Otherwise, returns false.
 */
bool StringRelation::isEquivalence(){
	//Reflexive, Symmetric and Transitive must all be true

	if (this->isReflexive() == true && this->isSymmetric() == true && this->isTransitive() == true)
	{
		return true;
	}
	
	return false;
}

/*
 * Returns true if the relation is vaild.
 * Otherwise, returns false.
 */
const bool StringRelation::verifyRelation(){
	vector<string> pair;

	//Check if relationship is valid
	for (size_t i = 0; i < (unsigned) this->size(); i++)
	{
		pair = makeTokens(this->elements[i]);
		if (SetMembers->isMember(pair[0]) == false || SetMembers->isMember(pair[1]) == false)
		{
			return false;			
		}
	}

	return true;
}