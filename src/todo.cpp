#include "todo.hpp"

#include <iostream>

using namespace std;

void addVectors(vector<task>& v1, vector<task>& v2) {
  for (task t : v2) v1.push_back(t);
}

void todo::load() {
  file.open(path, ios::in);
  if (!file) {
    cerr << "Error while opening file" << endl;
    exit(EXIT_FAILURE);
  }
  string line;
  while (getline(file, line)) {
    bool done = false;
    if (line[0] == '-') {
      done = true;
      line = line.substr(1);
    }
    add(task(line, done));
  }
  file.close();
}

void todo::save() {
  file.open(path, ios::out);
  if (!file) {
    cerr << "Error while opening file" << endl;
    exit(EXIT_FAILURE);
  }
  for (task t : list) {
    string prefix = "";
    if (t.done) prefix = "-";
    file << prefix << t.name << endl;
    ;
  }
  file.close();
}

void todo::print() {
  for (long unsigned int i = 0; i < list.size(); ++i) {
    cout << "\e[1m" << (i + 1) << ". \e[0m" << list[i].getText() << endl;
  }
}

void todo::add(task t) { list.push_back(t); }

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
}

void todo::clear() { list.clear(); }
