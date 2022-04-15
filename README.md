# Simple Shell
[![shell.png](https://i.postimg.cc/zXMc5wT4/shell.png)](https://postimg.cc/GHFQxy7j)
## Introduction
This repository is a project for Holberton School , the goal of which was to write a simple UNIX command line interpreter in *C*, using a limited number of standard library functions. The goal in this project was to make us understand how a shell works.

## Usage 
In order to run this program, 

Clone This Repo

`` git clone  https://github.com/nboute/simple_shell``

compile it with  

`gcc 4.8.4 -Wall -Werror -Wextra -pedantic *.c -o hsh`.  

You can then run it by invoking `./hsh` in that same directory.

### Required libraries

- stdio.h
- unistd.h
- stdlib.h
- sys/types.h
- sys/stat.h
- fcntl.h
- string.h
- sys/wait.h
- signal.h

### Examples

[![shell-examples.png](https://i.postimg.cc/Jzyj5d40/shell-examples.png)](https://postimg.cc/NKcygDXv)

## Details

For this project we worked on the environment of the shell, after had done a copy of the environment variables, we can use the PATH of each one to make our own built-ins.
Thanksfull, linked lists, structures, function pointers, you can now use in our simple shell, setenv, printenv, unsetenv, exit, help or history builtins.
You also can use commands like ls with his options, pwd or cat…
We had handle different types of error, like a poor recording of one command by the user.
The user can make aliases, change a name of a command by a word simplier for him.
In our shell, we had rewritten some functions like getline, strndup, atoi, strdup, strcpy, strcat…

### Built with
This project was built and developed with:

- C programming language

- Ubuntu 20.04 LTS

- GCC: GNU Compiler version 4.8.4

## Authors
- https://github.com/nboute
- https://github.com/LucileSD
- https://github.com/JayJay707
