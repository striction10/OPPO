#pragma once
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

struct Date {
    int year;
    int month;
    int day;

    void read(istringstream& file);
    void print() const;
};
