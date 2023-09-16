#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <clocale>
#include <sstream>

using namespace std;

struct date {
    int year;
    int month;
    int day;
};

struct FileInfo {
    string name_file;
    date data;
    int file_size;
};

void Object(ifstream& file_name, vector<FileInfo>& file_info);
vector<FileInfo> readData(const string& file_name);
void printFileInfo(const vector<FileInfo>& file_info);
