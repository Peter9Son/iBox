#include <string>
#include "io/directory.hpp"
#include "io/file.hpp"

#define DATA_DIR "/var/BOXDATA/"
#define DEFAULT_DIR_NAME "000"
#define DIR_LENGTH 3

class Pathstring : public DirectoryEntity, FileEntity {
public:
    Pathstring() : DirectoryEntity(), FileEntity() {};
    ~Pathstring() {};

    std::string set_bucket (std::string bucket) {};
    std::string get_path(std::string name){};
    std::string set_path (std::string bucket, std::string name) {};
};

