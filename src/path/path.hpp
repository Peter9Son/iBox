#include <string>
#include "io/directory.hpp"o
#include "io/file.hpp"o

#define DIR_LENGTH 3

class pathstring : public directoryEntity, fileEntity {
public:
    pathstring() : directoryEntity(), fileEntity() {};
    ~pathstring() {};
    std::string getpath(std::string name){};
    std::string setpath (std::string bucket, std::string name) {};
};


