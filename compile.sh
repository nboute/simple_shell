#!/bin/bash
gcc -o hsh -Wall -Werror -Wextra -pedantic -std=gnu89 alias.c prompt.c history.c builtins.c _strsplit.c _copy_envp.c exit.c main.c simple_shell.c utils2.c help.c error.c _strjoin.c env.c _strtok.c unsetenv.c path.c setenv.c utils.c printenv.c utils4.c utils3.c utils5.c str_replace.c
