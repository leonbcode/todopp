#include "todo.hpp"

#include <algorithm>
#include <iostream>

#include "util.hpp"

using namespace std;

todo::todo() {
  path = string(getenv("HOME")) + string("/.todopp");

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

void todo::remove(const vector<long unsigned int>& pos) {
  for (long unsigned int p : pos) {
    if (p >= list.size()) {
      cerr << ERROR_ARGUMENT << endl;
      exit(EXIT_FAILURE);
    }
    list[p].remove = true;
  }
  erase_if(list, [](task t) { return t.remove; });
}

void todo::done(const vector<long unsigned int>& pos) {
  for (long unsigned int p : pos) {
    if (p >= list.size()) {
      cerr << ERROR_ARGUMENT << endl;
      exit(EXIT_FAILURE);
    }
    list[p].done = true;
  }
}

void todo::sort() {
  std::sort(list.begin(), list.end(),
            [](task l, task r) { return !l.done && r.done; });
}

void todo::clear() { list.clear(); }
