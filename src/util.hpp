#pragma once

#include <string>

static const std::string RESET = "\e[0m";
static const std::string BOLD = "\e[1m";
static const std::string STRIKE = "\e[9m";

static const char DONE_PREFIX = '-';

static const std::string USAGE =
    "Usage: t1 [operator] [task names/numbers]\n\n"
    "Operators:\n"
    "   list      print all tasks of the t1 list.\n"
    "   add [task names]  add tasks with the given names to the list.\n"
    "   rm [task numbers] remove tasks with the given number from the list.\n"
    "   done [task numbers] mark tasks with the specified numbers as "
    "completed.\n"
    "   sort      move done tasks to the end of the list.\n"
    "   clear     remove all tasks from the list.\n"
    "   help      print this message.";

static const std::string ERROR_FILE = "Error while opening file.";
static const std::string ERROR_ARGUMENT =
    "Invalid argument.\n"
    "Position out od bounds.";
