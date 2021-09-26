#include <string>
#include "io/directory.hpp"o
#include "io/file.hpp"o

#define DIR_LENGTH 3

class Pathstring : public DirectoryEntity, FileEntity {
public:
    Pathstring() : DirectoryEntity(), FileEntity() {};
    ~Pathstring() {};
    std::string getpath(std::string name){};
    std::string setpath (std::string bucket, std::string name) {};
};


int file_name_lengh (std::string name){
    if (name.empty())
        return 0;
    else if (name.find(".") > 0)
    {
        return name.find(".");
    } else {
        return name.size();
    }
}
