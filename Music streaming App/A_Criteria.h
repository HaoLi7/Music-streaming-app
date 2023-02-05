#ifndef A_CRITERIA_H
#define A_CRITERIA_H

#include <iostream>
#include <string>
#include "Criteria.h"

using namespace std;

class A_Criteria: virtual public Criteria{
    public:
        A_Criteria(const string& artist);
        virtual bool matches(const Song&) const;
        virtual void print(ostream&) const;
    private:
        string artist;
};

#endif