#!/bin/bash
gcc -o hsh -Wall -Werror -Wextra -pedantic -std=gnu89 prompt.c builtins.c _strsplit.c _copy_envp.c exit.c main.c simple_shell.c utils2.c error.c _strjoin.c env.c _strtok.c unsetenv.c path.c setenv.c utils.c printenv.c utils4.c utils3.c 
