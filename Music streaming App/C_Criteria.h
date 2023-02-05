#ifndef C_CRITERIA_H
#define C_CRITERIA_H

#include <iostream>
#include <string>
#include "Criteria.h"

using namespace std;

class C_Criteria: virtual public Criteria{
    public:
        C_Criteria(const string& category);
        virtual bool matches(const Song&) const;
        virtual void print(ostream&) const;
    private:
        string category;
};

#endif