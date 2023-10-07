#include "date.hpp"

void Date::read(istringstream& file) {
    char t;
    file >> year >> t >> month >> t >> day;
}

void Date::print() const {
    cout << year << "." << month << "." << day;
}