#include <string>

#include "path.hpp"

class Instruction_t : public Pathstring {
public:
    Instruction_t();
    ~Instruction_t() {}
    std::string command_file_create(std::string bucket, std::string name){};
    std::string command_file_write(std::string bucket, std::string name){};
    std::string command_file_read(std::string bucket, std::string name){};
    std::string command_file_delete(std::string bucket, std::string name){};
};