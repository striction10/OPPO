#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <clocale>
#include <sstream>
#include "FileInfo.hpp"

using namespace std;

void readNameFile(istringstream& file, string& name_file);
void readDate(istringstream& file, Date& data);
void readFileSize(istringstream& file, int& file_size);
FileInfo readFileInfoLine(const string& line);
vector<FileInfo> readData(ifstream& input);
