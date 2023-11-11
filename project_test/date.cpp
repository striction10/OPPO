#include "date.hpp"
#include <vector>

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
        i = find_if(i, s.end(), notdot); // 1277.
        iter j = find_if(i, s.end(), dot);
        if (i != s.end()) {
            ret.push_back(string(i, j));
            i = j;
        }
    }
    return ret;
}

bool Date::isDateCorrect() {
	if (year < 1 || month < 1 || month > 12 || day < 1 || day > 31)
		return false;

	if (day > 31 && (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12))
        return false;

	if (day > 30 && (month == 4 || month == 6 || month == 9 || month == 11))
		return false;

    if (day > 29 && (month == 2 && year % 4 == 0 && year % 100 != 0))
        return false;

    if (day > 28 && (month == 2 && year % 4 == 0 && year % 100 != 0))
        return false;

	return true;
}

void Date::read(istringstream& iss) {
    string buf;
    iss >> buf;
    if (buf.empty())
        throw runtime_error("Строка даты пуста");

    vector<string> splitted = splitDate(buf);
    if (splitted.size() != 3)
        throw runtime_error("Строка " + buf + " не соответствует формату даты");

    try
    {
        day = stoi(splitted[0]);
        month = stoi(splitted[1]);
        year = stoi(splitted[2]);
    }
    catch (std::invalid_argument)
    {
        throw runtime_error("Строка " + buf + " имеет неправильный формат");
    }

    if (!isDateCorrect())
        throw runtime_error("Заданная дата " + buf + " не существует");
}

void Date::print() const {
    cout << year << "." << month << "." << day;
}