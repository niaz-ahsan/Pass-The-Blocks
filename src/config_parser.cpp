#include <config_parser.h>
#include <file_reader.h>

#include <vector>
#include <string>

using std::vector;
using std::string;

void Config_Parser::parse_and_store_data() {
    File_Reader reader("../config.txt");
    reader.parse_file();
    vector<string> all_data = reader.get_file_data();
    config_data["width"] = all_data[0];
    config_data["length"] = all_data[1];
} 