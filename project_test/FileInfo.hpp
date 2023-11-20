#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include "date.hpp"

using namespace std;

class FileInfo{
private:
    string name_file;
    Date date;
    int file_size;
public:
    vector<string> getArgs(string line);
    void readNameFile(string line);
    void readDate(string line);
    void readFileSize(string line);
    void readFileInfoLine(const string& line);
    void printLayoutFileInfo(std::ostream& out) const;
    string get_name_file();
    Date get_date();
    int get_file_size();
};

vector<FileInfo> readData(istream& input);
void printFileInfo(const vector<FileInfo>& file_info);
