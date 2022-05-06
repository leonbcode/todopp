#include "task.hpp"

static const std::string strike = "\e[9m";
static const std::string reset = "\e[0m";

std::string task::getText() {
  if (done)
    return strike + name + reset;
  else
    return name;
}
