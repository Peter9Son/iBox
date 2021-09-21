#include <string>

#include "path/path.hpp"



std::string getpath(std::string name){
    if (name.empty()){
        perror("string empty");
    } else {
        if (name.length() < DIR_LENGTH){
            return name;
        } else{
            return name.substr(0,DIR_LENGTH) + "/" + name;
        }
    }
}

std::string setpath (std::string bucket, std::string name) {
    if (name.empty()){
        perror("string empty");
    } else {
        if (name.length() < DIR_LENGTH){
            return name;
        } else{
            directoryEntity dir;
            if (dir.dir_open(bucket + "/" + name) == NULL){
                if (dir.dir_create(name , 0777) < 0)
                    perror("faile in dir creation");
            }
            return name.substr(0,DIR_LENGTH) + "/" + name;
        }
    }
}