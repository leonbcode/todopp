#include "task.h"

std::string task::getText()
{
	if(done) return "\e[9m" + name + "\e[0m";
	else return name;
}
