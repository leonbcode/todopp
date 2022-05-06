#pragma once

#include <fstream>
#include <string>
#include <vector>

#include "task.hpp"

struct todo {
  const std::string path;
  std::fstream file;
  std::vector<task> list;

  todo(const std::string p) : path(p) {}

  void load();
  void save();

  void print();
  void add(task t);
  void remove(std::vector<long unsigned int>& pos);
  void done(std::vector<long unsigned int>& pos);
  void sort();
  void clear();
};
