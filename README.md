<div align="center">
  <h1>Todopp</h1>
  <p>
    <b>A minimalist cli todo list written in c++.</b>
  </p>
  <p>
    <img alt="GitHub top language" src="https://img.shields.io/github/languages/top/leonbcode/todopp">
    <img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/leonbcode/todopp">
    <img alt="Lines of code" src="https://img.shields.io/tokei/lines/github/leonbcode/todopp">
  </p>
</div>

## Installation

### build from source

```bash
# Clone this repository
$ git clone https://github.com/leonbcode/todopp.git

# Open the project directory
$ cd ./todopp/

# Create a build directory
$ mkdir build

# Open the build directory
$ cd ./build/

# Initialize the CMake project
$ cmake ../

# Build the project with CMake
$ cmake --build .

# (optional) Install the project with CMake
$ sudo cmake --install .
```

Note: *If you are on Windows, you might want to add the installation directory to the PATH environment variable.*

## Usage

```bash
# Example
$ todopp add "example task"
``` 

| Operator          | Description                                  | Alias |
|-------------------|----------------------------------------------|-------|
| list              | List all tasks.                              | ls    |
| add `task names`  | Add one or multiple tasks.                   |       |
| remove `task ids` | Remove the specified tasks.                  | rm    |
| done `task ids`   | Mark the specified tasks as done.            |       |
| sort              | Move all done tasks to the end of the list.  |       |
| clear             | Remove all tasks.                            |       |
| help              | Print the help message.                      | ?     |
