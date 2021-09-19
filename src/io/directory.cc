#include <stdio.h> 
#include <sys/types.h> 
#include <sys/stat.h> 
#include <unistd.h> 
#include <errno.h> 
#include <string.h> 
#include <fcntl.h>

#include "io/directory.hpp"

dir_t dir_create(std::string path, mode_t mode){
    return mkdir(path.c_str(), mode);
}

DIR* dir_open(std::string pathName){
    return opendir(pathName.c_str());
}

int dir_close(DIR* dp){
    return closedir(dp);
}

int dir_remove(std::string path){
    return remove(path.c_str());
}

std::vector<std::string>  dir_read_files(DIR* dp){
    std::vector<std::string> s;
    struct dirent *dirEntry;
    struct stat inode;
    while ((dirEntry=readdir(dp)) != 0) {
      lstat (dirEntry->d_name, &inode);
      if (S_ISREG(inode.st_mode))
        s.push_back(dirEntry->d_name);
    }
    return s;
}

std::vector<std::string>  dir_read_subdirs(DIR* dp){
    std::vector<std::string> s;
    struct dirent *dirEntry;
    struct stat inode;
    while ((dirEntry=readdir(dp)) != 0) {
      lstat (dirEntry->d_name, &inode);
      if (S_ISDIR(inode.st_mode))
        s.push_back(dirEntry->d_name);
    }
    return s;
}