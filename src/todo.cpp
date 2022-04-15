#include "todo.hpp"

#include <iostream>

using namespace std;

void addVectors(vector<task>& v1, vector<task>& v2) {
  for (task t : v2) v1.push_back(t);
}

void todo::load() {}

void todo::save() {}

void todo::print() {
  for (long unsigned int i = 0; i < list.size(); ++i) {
    cout << "\e[1m" << (i + 1) << ". \e[0m" << list[i].getText() << endl;
  }
}

void todo::add(task t) {
  list.push_back(t);
  save();
}

void todo::remove(vector<long unsigned int>& pos) {
  for (long unsigned int p : pos) {
    if (p >= list.size()) {
      cerr << "Invalid argument" << endl
           << "rm only accepts numbers in range of the todo list" << endl
           << "(currently: 1 - " << list.size() << ")" << endl;
      exit(EXIT_FAILURE);
    }
    list[p].remove = true;
  }
  vector<task> tmp;
  for (task t : list)
    if (!t.remove) tmp.push_back(t);
  clear();
  addVectors(list, tmp);
  save();
}

void todo::done(vector<long unsigned int>& pos) {
  for (long unsigned int p : pos) {
    if (p >= list.size()) {
      cerr << "Invalid argument" << endl
           << "done only accepts numbers in range of the todo list" << endl
           << "(currently: 1 - " << list.size() << ")" << endl;
      exit(EXIT_FAILURE);
    }
    list[p].done = true;
  }
  save();
}

void todo::sort() {
  vector<task> tmp;
  vector<task> done;
  for (task t : list) {
    if (t.done)
      done.push_back(t);
    else
      tmp.push_back(t);
  }
  clear();
  addVectors(list, tmp);
  addVectors(list, done);
  save();
}

void todo::clear() {
  list.clear();
  save();
}
