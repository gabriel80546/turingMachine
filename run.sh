#!/usr/bin/env bash

# Desativa o modo de depuração
PS4='+ $(date "+%Y-%m-%d %T") $BASH_SOURCE:$LINENO: '
set -x
set -e

gcc -g main.c -o main
valgrind -s ./main

# Desativa o modo de depuração
set +e
set +x
