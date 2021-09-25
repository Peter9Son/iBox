#include <string>
#include <unistd.h>

#include "path/path.hpp"



std::string getpath(std::string bucket, std::string name){
    if (name.empty()){
        perror("string empty");
    } else {
        if (name.length() <= DIR_LENGTH){
            return bucket + "/" + name;
        } else{
            return bucket + "/" + name.substr(0,DIR_LENGTH) + "/" + name;
        }
    }
}

std::string setpath (std::string bucket, std::string name) {
    if (name.empty()){
        perror("string empty");
    } else {
        if (name.length() <= DIR_LENGTH){
            return  bucket + "/" + name;
        } else{
            directoryEntity dir;
            if (dir.dir_open(bucket + "/" + name) == NULL){
                chdir((bucket + "/" ).c_str());
                if (dir.dir_create(name.substr(0,DIR_LENGTH), 0777) < 0)
                    perror("faile in dir creation");
            }
            return bucket + "/" + name.substr(0,DIR_LENGTH) + "/" + name;
        }
    }
}