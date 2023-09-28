#include "FileUntils.hpp"

int main() {
    setlocale(LC_ALL, "");
    string file_name = "test.txt";
    ifstream input(file_name);
    if (!input.is_open()) {
        cout << "Не удалось открыть файл" << endl;
    }
    vector<FileInfo> file_info = readData(input);
    printFileInfo(file_info);
    return 0;
}
