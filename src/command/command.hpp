#include <string>

# define MAX_PORT 255

class instruction_t {
public:
    instruction_t(std::string inst, std::string bucket, int index, std::string name);
    ~instruction_t() {}
private:
    std::string inst_;
    std::string bucket_;
    int index_;
    std::string name_;
    int err_;

};