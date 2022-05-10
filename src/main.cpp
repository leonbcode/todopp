#include <iostream>
#include <vector>

#include "task.hpp"
#include "todo.hpp"
#include "util.hpp"

using namespace std;

int main(int argc, const char** argv) {
  todo todo;

  if (argc <= 1) {
    cout << USAGE << endl;
    exit(EXIT_FAILURE);
  }

  string action(argv[1]);

  if (action == "list" || action == "ls") {
    todo.print();
  } else if (action == "add") {
    for (int i = 2; i < argc; ++i) todo.add(task(argv[i], false));
  } else if (action == "rm") {
    vector<long unsigned int> pos;
    for (int i = 2; i < argc; ++i) pos.push_back(atoi(argv[i]) - 1);
    todo.remove(pos);
  } else if (action == "done") {
    vector<long unsigned int> pos;
    for (int i = 2; i < argc; ++i) pos.push_back(atoi(argv[i]) - 1);
    todo.done(pos);
  } else if (action == "sort") {
    todo.sort();
  } else if (action == "clear") {
    todo.clear();
  } else if (action == "help") {
    cout << USAGE << endl;
  } else {
    cout << USAGE << endl;
  }

  return 0;
}
