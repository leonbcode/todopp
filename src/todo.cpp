#include "todo.hpp"

#include <iostream>

#include "util.hpp"

using namespace std;

void addVectors(vector<task>& v1, vector<task>& v2) {
  for (task t : v2) v1.push_back(t);
}

todo::todo() {
  path = getenv("HOME");
  path += "/.todopp";

  file.open(path, ios::in);
  if (!file) {
    cerr << ERROR_FILE << endl;
    exit(EXIT_FAILURE);
  }

  string line;
  while (getline(file, line)) {
    bool done = false;
    if (line[0] == DONE_PREFIX) {
      done = true;
      line = line.substr(1);
    }
    add(task(line, done));
  }
  file.close();
}

todo::~todo() {
  file.open(path, ios::out);
  if (!file) {
    cerr << ERROR_FILE << endl;
    exit(EXIT_FAILURE);
  }

  for (task t : list) {
    if (t.done)
      file << DONE_PREFIX << t.name << endl;
    else
      file << t.name << endl;
  }
  file.close();
}

void todo::print() {
  for (long unsigned int i = 0; i < list.size(); ++i) {
    cout << BOLD << (i + 1) << ". " << RESET << list[i].getText() << endl;
  }
}

void todo::add(task t) { list.push_back(t); }

void todo::remove(vector<long unsigned int>& pos) {
  for (long unsigned int p : pos) {
    if (p >= list.size()) {
      cerr << ERROR_ARGUMENT << endl;
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
      cerr << ERROR_ARGUMENT << endl;
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
