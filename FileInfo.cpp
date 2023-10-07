#include "FileInfo.hpp"

void FileInfo::readNameFile(istringstream& file) {
    file >> name_file;
}

void FileInfo::readDate(istringstream& file) {
    data.read(file);
}

void FileInfo::readFileSize(istringstream& file) {
    file >> file_size;
}

void FileInfo::readFileInfoLine(const string& line) {
    istringstream iss(line);
    char t;
    readNameFile(iss);
    readDate(iss);
    readFileSize(iss);
}

void FileInfo::printLayoutFileInfo() const {
    cout << "\nНазвание файла: " << name_file;
    cout << "\nДата: ";
    data.print();
    cout << "\nРазмер: " << file_size;
    cout << "\n";
}

vector<FileInfo> readData(ifstream& input) {
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