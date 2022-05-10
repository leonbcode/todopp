SRC_FILES= ./src/main.cpp ./src/task.cpp ./src/todo.cpp

build: clean format analyze compile

compile: 
	g++ -Wall -std=c++20 -g $(SRC_FILES) -o ./out/todopp

clean: 
	rm -rf ./out/*

format:
	clang-format -style=google -i --verbose ./src/*

analyze:
	cppcheck --enable=all src/*
