#include "FileInfo.hpp"
#include <algorithm>
#include <vld.h>

void FileInfo::readNameFile(const string& line) {
    name_file = line;

    const string forbidden_strs[] = { "/", "\\", "?", ":", "*", "\"", "<", ">", "|" };
    auto found_forbidden = std::find_if(std::begin(forbidden_strs), std::end(forbidden_strs),
        [this](const string& forbidden_str) {
            return name_file.find(forbidden_str) != std::string::npos;
        });

    if (found_forbidden != std::end(forbidden_strs)) {
        throw std::runtime_error("Found forbidden char " + *found_forbidden + " of file name in line: " + line);
    }
}

void FileInfo::readDate(const string& line) {
    date.read(line);
}

void FileInfo::readFileSize(string line) {
    for (char const& c : line)
    {   
        int count = 0;
        const string digit = "0123456789";
        for (int i = 0; i < 10; i++) {
            char temp = digit[i];
            if (c == temp) {
                count++;
            }
        }
        if (count == 0) {
            throw runtime_error("File size format is wrong! Should be integer.");
        }
    }
    file_size = stoi(line);
    if (file_size < 0)
        throw runtime_error("File size could not be negative!");
}

vector<string> FileInfo::getArgs(string line) {
    if (line.empty())
        throw runtime_error("Line is empty!");

    vector<string> args;
    char quote = '\"';
    if (line[0] != quote)
        throw runtime_error("File name format is wrong! It should be in double quotes.");

    int nextQuoteIndex = line.substr(1, line.size() - 2).find(quote) + 1;
    if (nextQuoteIndex == string::npos)
        throw runtime_error("File name format is wrong! Couldn't find second double quote.");

    string file_name = line.substr(1, nextQuoteIndex - 1);
    args.push_back(file_name);

    int dateStartIndex = nextQuoteIndex + 2;
    int nextSpaceIndex = line.substr(dateStartIndex, line.size() - dateStartIndex).find(' ');
    if (nextSpaceIndex == string::npos)
        throw runtime_error("File name format is wrong! Couldn't find space.");

    string date_temp = line.substr(dateStartIndex, 10);

    int sizeStartIndex = dateStartIndex + 11;
    if (sizeStartIndex >= line.size())
        throw runtime_error("File name format is wrong! Couldn't find size arg.");

     string size = line.substr(sizeStartIndex, line.size() - sizeStartIndex);

    args.push_back(date_temp);
    args.push_back(size);

    return args;
}

void FileInfo::readFileInfoLine(const string& line) {
    vector<string> args = getArgs(line);

    istringstream iss(line);
    readNameFile(args[0]);
    readDate(args[1]);
    readFileSize(args[2]);
}

void FileInfo::printLayoutFileInfo(std::ostream& out = std::cout) const {
    out << "\nFile name: " << name_file;
    out << "\nDate: " << date.year << "." << date.month << "." << date.day;
    out << "\nWeight: " << file_size;
    out << "\n";
}

string FileInfo::get_name_file() {
    return name_file;
}

int FileInfo::get_file_size() {
    return file_size;
}

Date FileInfo::get_date() {
    return date;
}

vector<FileInfo> readData(istream& input) {
    vector<FileInfo> file_info;
    string line;
    while (getline(input, line)) {
        FileInfo file;
        file.readFileInfoLine(line);
        file_info.push_back(file);
    }
    return file_info;
}

void printFileInfo(const vector<FileInfo>& file_info) {
    for (const FileInfo& file : file_info) {
        file.printLayoutFileInfo();
    }
}
