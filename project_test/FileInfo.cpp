#include "FileInfo.hpp"

inline bool space(char c) {
    return c == ' ';
}

inline bool notspace(char c) {
    return c != ' ';
}

vector<string> splitBySpace(const string& s) {
    typedef string::const_iterator iter;
    vector<string> ret;
    iter i = s.begin();
    while (i != s.end()) {
        i = find_if(i, s.end(), notspace);
        iter j = find_if(i, s.end(), space);
        if (i != s.end()) {
            ret.push_back(string(i, j));
            i = j;
        }
    }
    return ret;
}

void FileInfo::readNameFile(istringstream& file) {
    file >> name_file;

    string forbidden_strs[] = { "/", "\\", "?", ":", "*", "\"", "<", ">", "|"};
    for (auto forbidden_str: forbidden_strs)
    {
        if (name_file.find(forbidden_str) != std::string::npos)
            throw runtime_error("Обнаружен запрещенный символ " + forbidden_str + " в названии файла: " + file.str());
    }
}

void FileInfo::readDate(istringstream& file) {
    date.read(file);
}

void FileInfo::readFileSize(istringstream& file) {
    file >> file_size;
}

void FileInfo::readFileInfoLine(const string& line) {
    vector<string> strs = splitBySpace(line);


//    if (strs.size() != 3)
  //      throw runtime_error("Количество недопустимых аргументов (должно быть 3). Строка: " + line);

    istringstream iss(line);
    readNameFile(iss);
    readDate(iss);
    readFileSize(iss);
}

void FileInfo::printLayoutFileInfo() const {
    cout << "\nНазвание файла: " << name_file;
    cout << "\nДата: ";
    date.print();
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