#include <stdio.h> 
#include <sys/types.h> 
#include <sys/stat.h> 
#include <unistd.h> 
#include <errno.h> 
#include <string.h> 
#include <fcntl.h>

#include <string>

#include "io/directory.hpp"

int directory_create(std::string path, mode_t mode){
    return mkdir(path.c_str(), mode);
}

dir_t dir_open(std::string path, mode_t mode){
    dir_t dir_fd;
    dir_fd = open(path.c_str(), mode);
    return dir_fd;
}