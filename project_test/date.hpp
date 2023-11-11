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

    void read(istringstream& file);
    void print() const;
    bool isDateCorrect();
};

// vector<string> splitDatebydot(const string& s); // 12.12.12 12 12 12