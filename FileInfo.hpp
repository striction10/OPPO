#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include "date.hpp"

using namespace std;

struct FileInfo {
    string name_file;
    Date data;
    int file_size;

    void readNameFile(istringstream& file);
    void readDate(istringstream& file);
    void readFileSize(istringstream& file);
    void readFileInfoLine(const string& line);
    void printLayoutFileInfo() const;
};

vector<FileInfo> readData(ifstream& input);
void printFileInfo(const vector<FileInfo>& file_info);
