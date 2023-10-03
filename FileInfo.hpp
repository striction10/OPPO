#pragma once
#include <iostream>
#include <string>
#include "date.hpp"

using namespace std;

struct FileInfo {
    string name_file;
    Date data;
    int file_size;
};

void printLayoutFileInfo(const FileInfo& file);
void printFileInfo(const vector<FileInfo>& fileinfo);
