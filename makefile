SRC_FILES = ./src/main.cpp ./src/task.cpp ./src/todo.cpp


build: clean compile

compile:
	g++ -Wall -g  $(SRC_FILES) -o ./out/todo

clean:
	rm -rf ./out/*
