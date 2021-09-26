#include <string>
#include <unistd.h>

#include "path/path.hpp"

std::string set_bucket (std::string bucket) {
    if (bucket.empty()){
        perror("string empty");
        return NULL;
    } else {
       DirectoryEntity dir;
       if (dir.dir_open(bucket) == NULL){
           if (dir.dir_create(bucket, 0777) < 0) {
                perror("faile in dir creation");
                return NULL;
           }
            return bucket;
       }
    }
}


std::string get_path(std::string bucket, std::string name){
    if (name.empty()){
        perror("string empty");
        return NULL;
    } else {
        if (file_name_lengh(name) <= DIR_LENGTH){
            return bucket + "/" + DEFAULT_DIR_NAME + "/" + name;
        } else{
            return bucket + "/" + name.substr(0,DIR_LENGTH) + "/" + name;
        }
    }
}

std::string set__path (std::string bucket, std::string name) {
    if (name.empty()){
        perror("file name string empty");
        return NULL;
    } else {
        DirectoryEntity dir;
        if (dir.dir_open(bucket) == NULL){
            perror("bucket string empty");
            return NULL;
        }
        if (file_name_lengh(name) <= DIR_LENGTH){
            if (dir.dir_open(bucket + "/" + DEFAULT_DIR_NAME) == NULL){
                chdir((bucket + "/" ).c_str());
                if (dir.dir_create(DEFAULT_DIR_NAME, 0777) < 0) {
                    perror("faile in dir creation");
                    return NULL;
                }
            }
            return  bucket + "/" + DEFAULT_DIR_NAME + "/" + name;
        } else{
            if (dir.dir_open(bucket + "/" + name) == NULL){
                chdir((bucket + "/" ).c_str());
                if (dir.dir_create(name.substr(0,DIR_LENGTH), 0777) < 0) {
                    perror("faile in dir creation");
                    return NULL;
                }
            }
            return bucket + "/" + name.substr(0,DIR_LENGTH) + "/" + name;
        }
    }
}


int file_name_lengh (std::string name){
    if (name.empty())
        return 0;
    else if (name.find(".") > 0)
        return name.find(".");
    else
        return name.size();
}