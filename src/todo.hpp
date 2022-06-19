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
  void add(const task &t);
  void remove(const std::vector<unsigned long int> &pos);
  void done(const std::vector<unsigned long int> &pos);
  void sort();
  void clear();
};
