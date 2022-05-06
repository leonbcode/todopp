#include <iostream>
#include <vector>

#include "task.hpp"
#include "todo.hpp"

using namespace std;

int main(int argc, const char** argv) {
  string path = getenv("HOME");
  path += "/.todopp";
  todo todo(path);
  todo.load();

  // usage message
  const string USAGE_MSG =
      "Usage: t1 [operator] [task names/numbers]\n\n"
      "Operators:\n"
      "   list			print all tasks of the t1 list.\n"
      "   add [task names]	add tasks with the given names to the list.\n"
      "   rm [task numbers]	remove tasks with the given number from the "
      "list.\n"
      "   done [task numbers]	mark tasks with the specified numbers as "
      "completed.\n"
      "   sort			move done tasks to the end of the list.\n"
      "   clear 		remove all tasks from the list.\n"
      "   help			print this message.";

  if (argc <= 1) {
    cout << USAGE_MSG << endl;
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
    cout << USAGE_MSG << endl;
  } else {
    cout << USAGE_MSG << endl;
  }

  todo.save();
  return 0;
}
