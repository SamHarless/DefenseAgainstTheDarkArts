#!/bin/bash

FLEX_FILE="virus-patterns.l"

flex $FLEX_FILE

gcc -o scanner lex.yy.c -lfl


