#include <iostream>
#include <fstream>
#include "FileInfo.hpp"

int main() {
    setlocale(LC_ALL, "");
    ifstream input("test.txt");
    if (!input) {
        cout << "Не удалось открыть файл" << endl;
        return 0;
    }
    vector<FileInfo> file_info = readData(input);
    printFileInfo(file_info);
    input.close();
    return 0;
}
