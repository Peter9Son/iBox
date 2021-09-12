#include <stdio.h> 
#include <sys/types.h> 
#include <sys/stat.h> 
#include <unistd.h> 
#include <errno.h> 
#include <string.h> 
#include <fcntl.h>

#include <string>

#include "io/file.hpp"

fd_t file_open(char* path, mode_t mode){
    fd_t fd;
    fd = open(path, mode);
    return fd;
}

int file_close(fd_t fd){
    return close(fd);
}

int64_t get_file_stat(fd_t fd){
    struct stat buffer;
    int result = fstat(fd, &buffer);
    return buffer.st_size;
}

