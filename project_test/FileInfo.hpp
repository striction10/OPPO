#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include "date.hpp"

using namespace std;

class FileInfo{
public:
    string name_file;
    Date date;
    int file_size;

    void readNameFile(istringstream& file);
    void readDate(istringstream& file);
    void readFileSize(istringstream& file);
    void readFileInfoLine(const string& line);
    void printLayoutFileInfo() const;
};

vector<FileInfo> readData(ifstream& input);
void printFileInfo(const vector<FileInfo>& file_info);