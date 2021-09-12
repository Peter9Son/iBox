#include "command/command.hpp"

instruction_t::instruction_t(std::string inst, std::string bucket, int index, std::string name)
: inst_(inst),
  bucket_(bucket),
  index_(index),
  name_(name),
  err_(0) {
}