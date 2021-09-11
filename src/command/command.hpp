#include <string>

# define MAX_PORT 255

class instruction_t : public std::exception {
public:
    instruction_t(std::string &_inst, std::string _bucket, int _index, std::string &_name, int _err);
    ~instruction_t() throw() {}
    std::string inst;
    std::string bucket;
    int index;
    std::string name;
    int err;

};

