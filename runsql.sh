#!/bin/bash

flex sql.l  
yacc -d sql.y  
gcc sql.c lex.yy.c y.tab.c -o mysql  
./mysql  
