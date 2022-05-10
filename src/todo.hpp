#pragma once

#include <fstream>
#include <string>
#include <vector>

#include "task.hpp"

struct todo {
  std::string path;
  std::fstream file;

  std::vector<task> list;

  todo();
  ~todo();

  void print();
  void add(task t);
  void remove(const std::vector<long unsigned int>& pos);
  void done(const std::vector<long unsigned int>& pos);
  void sort();
  void clear();
};
