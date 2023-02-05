#ifndef CRITERIA_H
#define CRITERIA_H

#include <iostream>
#include <string>
#include "Song.h"

using namespace std;

class Criteria {
    friend ostream& operator<<(ostream& ost, const Criteria& c);
    public:
        virtual bool matches(const Song&) const = 0;
        virtual void print(ostream&) const = 0 ;
};
#endif