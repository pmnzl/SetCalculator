#ifndef STRINGRELATION_H_
#define STRINGRELATION_H_

#include "SetOfStrings.h"
#include <vector>
#include <stdio.h>

using namespace std;

class StringRelation : public SetOfStrings{
private:
    SetOfStrings *SetMembers; // stores the members of the set, which the relation is created on.
    vector<string> makeTokens(string input); // split a string into tokens

public:
    void setInput(SetOfStrings *s); 
    bool isReflexive();
    bool isSymmetric();
    bool isTransitive();
    bool isEquivalence();
    SetOfStrings *computeEquivalenceClass(string element);
    
    //Helper Functions
    const bool verifyRelation();
};
#endif
