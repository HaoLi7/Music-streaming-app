#ifndef AORC_CRITERIA_H
#define AORC_CRITERIA_H

#include <iostream>
#include <string>
#include "A_Criteria.h"
#include "C_Criteria.h"

using namespace std;

class AorC_Criteria: public A_Criteria, public C_Criteria{
    public:
        AorC_Criteria(const string& artist, const string& category);
        bool matches(const Song&) const;
        void print(ostream&) const;
};

#endif