#!/bin/sh
set -e

cc -c *.c  -Wall -Werror -Wextra 

ar rcs libft.a *.o

rm -f *.o