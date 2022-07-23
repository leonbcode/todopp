#include "todo.hpp"

#include <algorithm>
#include <iostream>

#include "util.hpp"

using namespace std;

todo::todo() {
  path = string(getenv(HOMEPATH)) + string("/.todopp");

  file.open(path, fstream::in | fstream::app);
  if (!file) {
    cerr << ERROR_FILE << endl;
    exit(EXIT_FAILURE);
  }

  string line;
  while (getline(file, line)) {
    bool taskDone = false;
    if (line[0] == DONE_PREFIX) {
      taskDone = true;
      line = line.substr(1);
    }
    add(task(line, taskDone));
  }
  file.close();
}

todo::~todo() {
  file.open(path, ios::out);
  if (!file) {
    cerr << ERROR_FILE << endl;
    exit(EXIT_FAILURE);
  }

  for (const task &t : list) {
    if (t.done)
      file << DONE_PREFIX << t.name << endl;
    else
      file << t.name << endl;
  }
  file.close();
}

void todo::print() {
  for (unsigned long int i = 0; i < list.size(); ++i) {
    cout << BOLD << (i + 1) << ". " << RESET << list[i].getText() << endl;
  }
}

void todo::add(const task &t) { list.push_back(t); }

void todo::remove(const vector<unsigned long int> &pos) {
  for (unsigned long int p : pos) {
    if (p >= list.size()) {
      cerr << ERROR_ARGUMENT << endl;
      exit(EXIT_FAILURE);
    }
    list[p].remove = true;
  }
  erase_if(list, [](const task &t) { return t.remove; });
}

void todo::done(const vector<unsigned long int> &pos) {
  for (unsigned long int p : pos) {
    if (p >= list.size()) {
      cerr << ERROR_ARGUMENT << endl;
      exit(EXIT_FAILURE);
    }
    list[p].done = true;
  }
}

void todo::sort() {
  std::sort(list.begin(), list.end(),
            [](const task &l, const task &r) { return !l.done && r.done; });
}

void todo::clear() { list.clear(); }
