#include "date.hpp"
#include <vector>
#include <vld.h>

inline bool dot(char c) {
    return c == '.';
}

inline bool notdot(char c) {
    return c != '.';
}

vector<string> splitDate(const string& s) {
    typedef string::const_iterator iter;
    vector<string> ret;
    iter i = s.begin();
    while (i != s.end()) {
        i = find_if(i, s.end(), notdot);
        iter j = find_if(i, s.end(), dot);
        if (i != s.end()) {
            ret.push_back(string(i, j));
            i = j;
        }
    }
    return ret;
}

bool Date::isDateCorrect() {
    if (year < 1 || month < 1 || month > 12 || day < 1)
        return false;

    if (month == 4 || month == 6 || month == 9 || month == 11) {
        return day <= 30;
    }
    else if (month == 2) {
        if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
            return day <= 29;
        }
        else {
            return day <= 28;
        }
    }
    else {
        return day <= 31;
    }
}
void Date::read(const string& line) {
    if (line.empty())
        throw runtime_error("Заданная строка пуста");

    vector<string> splitted = splitDate(line);
    if (splitted.size() != 3)
        throw runtime_error("Строка " + line + " не соответствует формату даты");

    try
    {
        day = stoi(splitted[0]);
        month = stoi(splitted[1]);
        year = stoi(splitted[2]);
    }
    catch (std::invalid_argument)
    {
        throw runtime_error("Строка " + line + " имеет неправильный формат");
    }

    if (!isDateCorrect())
        throw runtime_error("Заданная дата " + line + " не существует");
}

void Date::print() const {
    cout << year << "." << month << "." << day;
}
