#pragma once
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Date {
public:
    int year;
    int month;
    int day;

    void read(const string& line);
    void print() const;
    bool isDateCorrect();
};
