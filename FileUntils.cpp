#include "FileUntils.hpp"

void readNameFile(istringstream& file, string& name_file) {
    file >> name_file;
}

void readDate(istringstream& file, Date& data) {
    char t;
    file >> data.year >> t >> data.month >> t >> data.day;
}

void readFileSize(istringstream& file, int& file_size) {
    file >> file_size;
}

FileInfo readFileInfoLine(const string& line) {
    FileInfo file;
    istringstream iss(line);
    char t;
    readNameFile(iss, file.name_file);
    readDate(iss, file.data);
    readFileSize(iss, file.file_size);
    return file;
}

vector<FileInfo> readData(ifstream& input) {
    vector<FileInfo> file_info;
    string line;
    while (getline(input, line)) {
        FileInfo file = readFileInfoLine(line);
        file_info.push_back(file);
    }
    return file_info;
}

void printDate(const Date& data) {
    cout << data.year << "." << data.month << "." << data.day;
}

void printLayoutFileInfo(const FileInfo& file) {
    cout << "\nНазвание файла: " << file.name_file;
    cout << "\nДата: ";
    printDate(file.data);
    cout << "\nРазмер: " << file.file_size;
    cout << "\n";
}

void printFileInfo(const vector<FileInfo>& file_info) {
    for (const FileInfo& file : file_info) {
        printLayoutFileInfo(file);
    }
}