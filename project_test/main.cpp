#include <iostream>
#include <fstream>
#include "FileInfo.hpp"

int main() {
    setlocale(LC_ALL, "en_US.UTF8");
    ifstream input("test.txt");
    if (!input) {
        cout << "Can't open file." << endl;
        return 0;
    }

    try
    {
        vector<FileInfo> file_info = readData(input);
        printFileInfo(file_info);
    }
    catch (exception& exc)
    {
        cerr << exc.what() << endl;
    }
    input.close();
    return 0;
}
