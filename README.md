# Pipex

A 42 school project that recreates the behavior of shell pipes using C system calls.

## Table of Contents

- [About](#about)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [System Calls Used](#system-calls-used)
- [Project Structure](#project-structure)
- [Examples](#examples)
- [Error Handling](#error-handling)
- [Resources](#resources)
- [Author](#author)

## About

Pipex is a project from the 42 school curriculum that teaches students how to work with pipes, processes, and file descriptors in C. The program mimics the behavior of shell pipes by connecting the output of one command to the input of another.

The project recreates this shell command behavior:
```bash
< file1 cmd1 | cmd2 > file2
```

Which is equivalent to:
```bash
./pipex file1 cmd1 cmd2 file2
```

## Features

- ✅ Pipe creation and management
- ✅ Process forking and child process handling
- ✅ File descriptor manipulation with `dup2()`
- ✅ Command execution with `execve()`
- ✅ Environment variable handling
- ✅ Error handling and cleanup
- ✅ Memory management

## Installation

1. Clone the repository:
```bash
git clone https://github.com/oktaycb/pipex.git
cd pipex
```

2. Compile the project:
```bash
make
```

3. Clean object files (optional):
```bash
make clean
```

4. Remove all generated files:
```bash
make fclean
```

## Usage

```bash
./pipex file1 cmd1 cmd2 file2
```

### Parameters

- `file1`: Input file to read from
- `cmd1`: First command to execute
- `cmd2`: Second command to execute  
- `file2`: Output file to write to

### Example

```bash
./pipex input.txt "grep hello" "wc -l" output.txt
```

This is equivalent to:
```bash
< input.txt grep hello | wc -l > output.txt
```

## System Calls Used

| Function | Purpose |
|----------|---------|
| `dup2()` | Duplicate file descriptors |
| `fork()` | Create child processes |
| `pipe()` | Create pipes for inter-process communication |
| `execve()` | Execute commands |
| `wait()` | Wait for child processes to finish |
| `access()` | Check file permissions |
| `open()` | Open files |
| `close()` | Close file descriptors |

## Project Structure

```
pipex/
├── Makefile          # Build configuration
├── README.md         # Project documentation
├── pipex.h           # Header file with function prototypes
├── pipex.c           # Main program logic
├── utilities.c       # Helper functions
└── libft/            # Custom C library
    ├── libft.h
    └── *.c files
```

## Examples

### Basic usage:
```bash
./pipex input.txt "cat" "grep 42" output.txt
```

### With complex commands:
```bash
./pipex data.txt "grep -i error" "sort" errors.txt
```

### Using built-in commands:
```bash
./pipex file.txt "ls -la" "wc -l" count.txt
```

## Error Handling

The program handles various error cases:

- ❌ Invalid number of arguments
- ❌ File permission errors
- ❌ Command not found
- ❌ Pipe creation failures
- ❌ Fork failures
- ❌ Memory allocation errors

Error messages are written to `stderr` and the program exits with appropriate error codes.

## Resources

- [pipe(2) man page](https://man7.org/linux/man-pages/man2/pipe.2.html)
- [fork(2) man page](https://man7.org/linux/man-pages/man2/fork.2.html)
- [execve(2) man page](https://man7.org/linux/man-pages/man2/execve.2.html)
- [dup2(2) man page](https://man7.org/linux/man-pages/man2/dup2.2.html)
- [42 School Curriculum](https://42.fr/)

## Author

**Oktay Çubukçu** - [oktaycb](https://github.com/oktaycb)

---

## 🚀 Don't copy, learn!

This project is part of the 42 school curriculum. The purpose is to learn and understand the concepts. Please use this as a reference for learning, not for copying.

---

*Made with ❤️ at 42 School*
