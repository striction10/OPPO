#include "file_info_structs.h"

int main() {
    setlocale(LC_ALL, "");
    string file_name = "test.txt";
    vector<FileInfo> file_info = readData(file_name);
    printFileInfo(file_info);
    return 0;
}
