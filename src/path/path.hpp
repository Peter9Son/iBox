#include <string>
#include "io/directory.hpp"o

#define DIR_LENGTH 3

class pathstring : public directoryEntity {
public:
    pathstring() : directoryEntity() {};
    ~pathstring() {};
    std::string getpath(std::string name){};
    std::string setpath (std::string bucket, std::string name) {};
};


