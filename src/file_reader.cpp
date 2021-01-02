#include <vector>
#include <string>
#include <sstream>
#include <file_reader.h>

using std::string;

void File_Reader::parse_file() {
    _file.open(_path);
    string file_line;
    if(_file) {
        while(getline(_file, file_line)) {
            std::istringstream streamer(file_line);
            string key, data;
            streamer >> key >> data;
            _file_data.emplace_back(std::move(data));
        }
    } 
}
