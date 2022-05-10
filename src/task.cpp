#include "task.hpp"

#include "util.hpp"

std::string task::getText() {
  if (done)
    return STRIKE + name + RESET;
  else
    return name;
}
