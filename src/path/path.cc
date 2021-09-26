#include <string>
#include <unistd.h>

#include "path/path.hpp"

#define DATADIR "/var/BOXDATA/"

std::string set_bucket (std::string bucket) {
    if (bucket.empty()){
        perror("string empty");
    } else {
       DirectoryEntity dir;
       if (dir.dir_open(bucket) == NULL){
           if (dir.dir_create(bucket, 0777) < 0)
                    perror("faile in dir creation");
            return bucket;
       }
    }
}


std::string get_path(std::string bucket, std::string name){
    if (name.empty()){
        perror("string empty");
    } else {
        if (file_name_lengh(name) <= DIR_LENGTH){
            return bucket + "/" + name;
        } else{
            return bucket + "/" + name.substr(0,DIR_LENGTH) + "/" + name;
        }
    }
}

std::string set__path (std::string bucket, std::string name) {
    if (name.empty()){
        perror("string empty");
    } else {
        if (file_name_lengh(name) <= DIR_LENGTH){
            return  bucket + "/" + name;
        } else{
            DirectoryEntity dir;
            if (dir.dir_open(bucket + "/" + name) == NULL){
                chdir((bucket + "/" ).c_str());
                if (dir.dir_create(name.substr(0,DIR_LENGTH), 0777) < 0)
                    perror("faile in dir creation");
            }
            return bucket + "/" + name.substr(0,DIR_LENGTH) + "/" + name;
        }
    }
}