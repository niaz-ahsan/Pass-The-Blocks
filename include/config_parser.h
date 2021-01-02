#ifndef CONFIG_PARSER_H
#define CONFIG_PARSER_H

#include <unordered_map>
#include <string>

class Config_Parser {
public:
    void parse_and_store_data();    
    std::unordered_map<std::string, std::string> config_data;
};

#endif