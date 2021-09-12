#include <stdio.h> 
#include <sys/types.h> 
#include <sys/stat.h> 
#include <unistd.h> 
#include <errno.h> 
#include <string.h> 
#include <fcntl.h>

#include <string>

#include "io/file.hpp"

<<<<<<< HEAD
fd_t file_create(char* path, mode_t mode){
    fd_t fd;
    fd = creat(path, mode);
    return fd;
}

=======
>>>>>>> e6688744b97c217468990f8247479cfc721a6dd2
fd_t file_open(char* path, mode_t mode){
    fd_t fd;
    fd = open(path, mode);
    return fd;
}

int file_close(fd_t fd){
    return close(fd);
}

<<<<<<< HEAD
int file_remove(char* path){
    return remove(path);
}

int64_t get_file_size(fd_t fd){
=======
int64_t get_file_stat(fd_t fd){
>>>>>>> e6688744b97c217468990f8247479cfc721a6dd2
    struct stat buffer;
    int result = fstat(fd, &buffer);
    return buffer.st_size;
}

<<<<<<< HEAD
time_file_access get_time_file_access(fd_t fd){
    struct  stat buffer;
    time_file_access time_t;
    int result = fstat(fd, &buffer);
    time_t.last_access = buffer.st_atime;
    time_t.last_change = buffer.st_ctime;
    time_t.last_modification = buffer.st_mtime;
    return time_t;
}
=======
>>>>>>> e6688744b97c217468990f8247479cfc721a6dd2
