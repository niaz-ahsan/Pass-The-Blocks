#ifndef FILE_READER_H
#define FILE_READER_H

#include <fstream>
#include <string>
#include <vector>

#include <reader.h>

using std::string;
using std::vector;

class File_Reader : public Reader {
public:
    template<typename type>
    File_Reader(const type &path) : _path(path) {}
    void parse_file() override;
    vector<string> get_file_data() { return _file_data; }
private:
    std::ifstream _file;        
    string _path;
    vector<string> _file_data;
};

#endif