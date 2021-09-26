#include <dirent.h>

#include <stdint.h>

#include <string>
#include <vector>

typedef int dir_t;
class DirectoryEntity{
public:
    DirectoryEntity(){};
    ~DirectoryEntity();
    int dir_create(std::string path, mode_t mode){};

    DIR* dir_open(std::string pathName){};

    int dir_close(DIR* dp){};

    int dir_remove(std::string path){};

    std::vector<std::string>  dir_read_files(DIR* dp){};

    std::vector<std::string>  dir_read_subdirs(DIR* dp){};
};