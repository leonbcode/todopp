#pragma once

#include <string>

#ifdef _WIN32
#define HOMEPATH "USERPROFILE"
#elif __unix__
#define HOMEPATH "HOME"
#endif

#define RESET "\e[0m"
#define BOLD "\e[1m"
#define STRIKE "\e[9m"

#define DONE_PREFIX "- [x] "
#define UNFINISHED_PREFIX "- [ ] "

static const std::string USAGE =
    "Usage: todopp [operator] [task names/numbers]\n\n"
    "Operators:\n"
    "   list      print all tasks of the todo list.\n"
    "   add [task names]  add tasks with the given names to the list.\n"
    "   remove [task numbers] remove tasks with the given number from the list.\n"
    "   done [task numbers] mark tasks with the specified numbers as "
    "completed.\n"
    "   sort      move done tasks to the end of the list.\n"
    "   clear     remove all tasks from the list.\n"
    "   help      print this message.";

static const std::string ERROR_FILE = "Error while opening file.";
static const std::string ERROR_ARGUMENT =
    "Invalid argument.\n"
    "Position out od bounds.";
