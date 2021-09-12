#include <stdint.h>

typedef int fd_t;

struct time_file_access
{
    time_t last_access;
    time_t last_change;
    time_t last_modification;
};
