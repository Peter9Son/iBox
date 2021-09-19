#include <stdio.h> 
#include <sys/types.h> 
#include <sys/stat.h> 
#include <unistd.h> 
#include <errno.h> 
#include <string.h> 
#include <fcntl.h>

#include <string>

#include "io/file.hpp"

fd_t file_create(std::string path, std::string name, mode_t mode){
    fd_t fd;
    std::string pathName = path + name;
    fd = creat(pathName.c_str(), mode);
    return fd;
}

fd_t file_open(std::string path, std::string name, mode_t mode){
    fd_t fd;
    std::string pathName = path + name;
    fd = open(pathName.c_str(), mode);
    return fd;
}

int file_close(fd_t fd){
    return close(fd);
}

int file_remove(std::string path, std::string name){
    std::string pathName = path + name;
    return remove(pathName.c_str());
}

time_file_access get_file_access(fd_t fd){
    struct stat buffer;
    time_file_access time_t;
    int result = fstat(fd, &buffer);
    time_t.last_access = buffer.st_atime;
    time_t.last_change = buffer.st_ctime;
    time_t.last_modification = buffer.st_mtime;
    return time_t;
}

int get_file_size(fd_t fd){
    struct stat buffer;
    int result = fstat(fd, &buffer);
    return buffer.st_size;
}