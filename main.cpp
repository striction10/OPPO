#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <clocale>
#include <sstream>

using namespace std;

struct FileInfo{
    string name_file;
    string data;
    uintmax_t file_size;
};


int main(){
    setlocale(LC_ALL, "");
    fstream in("test.txt");

    if (!in.is_open()){
        cout << "Не удалось открыть файл" << endl;
        return 0;
    }
    vector<FileInfo> file_info;
    string line;
    while(getline(in, line)){
        FileInfo file;
        istringstream inf(line);
        inf >> file.name_file >> file.data >> file.file_size;
        file_info.push_back(file);
    }
    for (const FileInfo& file : file_info){
        cout << "\nНазвание файла: " << file.name_file;
        cout << "\nДата: " << file.data;
        cout << "\nРазмер: " << file.file_size;
        cout << "\n";
    }

    in.close();
    return 0;
}
