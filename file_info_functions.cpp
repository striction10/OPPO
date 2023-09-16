#include "file_info_structs.h"

void Object(ifstream& file_name, vector<FileInfo>& file_info) {
    string line;
    while (getline(file_name, line)) {
        FileInfo file;
        char t;
        istringstream inf(line);
        inf >> file.name_file >> file.data.year >> t >> file.data.month >> t >> file.data.day >> file.file_size;
        file_info.push_back(file);
    }
}

vector<FileInfo> readData(const string& file_name) {
    vector<FileInfo> file_info;
    ifstream file(file_name);
    string line;
    Object(file, file_info);
    file.close();
    return file_info;
}

void printFileInfo(const vector<FileInfo>& file_info) {
    for (const FileInfo& file : file_info) {
        cout << "\nНазвание файла: " << file.name_file;
        cout << "\nДата: " << file.data.year << "." << file.data.month << "." << file.data.day;
        cout << "\nРазмер: " << file.file_size;
        cout << "\n";
    }
}
