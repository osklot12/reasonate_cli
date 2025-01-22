//
// Created by osklot12 on 10/23/24.
//

#ifndef FILEUTIL_H
#define FILEUTIL_H

#include <fstream>
#include <sstream>
#include <string>

class FileUtil {
public:
    static std::string read_file(const std::string &path) {
        std::ifstream file(path);
        if (!file.is_open()) {
            throw std::runtime_error("Failed to open file: " + path);
        }
        std::stringstream buffer;
        buffer << file.rdbuf();
        return buffer.str();
    }
};

#endif //FILEUTIL_H
