#include <sys/stat.h>

#include "io/file.hpp"

int64_t get_file_stat(fd_t fd){
    struct stat buffer;
    int result = fstat(fd, &buffer);
    return buffer.st_size;
}