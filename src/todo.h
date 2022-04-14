#pragma once

#include <iostream>
#include <vector>
#include "task.h"

using namespace std;

struct todo
{
	const string path;
	vector<task> list;

	todo(const string p) : path(p) {}

	void load();
	void save();

	void print();
	void add(task t);
	void remove(vector<long unsigned int>& pos);
	void done(vector<long unsigned int>& pos);
	void sort();
	void clear();
};
