#pragma once

#include <string>

struct task {
  std::string name;
  bool done;
  bool remove;

  task(const std::string &n, const bool d) : name(n), done(d), remove(false) {}

  std::string getText();
};
