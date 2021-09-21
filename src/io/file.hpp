#include <stdint.h>

#include <string>

struct time_file_access
{
    time_t last_access;
    time_t last_change;
    time_t last_modification;
};

typedef int fd_t;
class fileEntity {
public:
    fileEntity(){};

    ~fileEntity();

    int file_create(std::string path, std::string name, mode_t mode){};

    int file_open(std::string path, std::string name, mode_t mode){};

    int file_close(int fd){};

    int file_remove(std::string path, std::string name){};

    time_file_access get_file_access(int fd){};

    int get_file_size(int fd){};
};