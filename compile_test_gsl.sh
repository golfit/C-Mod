#!/bin/sh
#T. Golfinopoulos, 29 Dec. 2017
#Note: also had to modify LD_LIBRARY_PATH in .bashrc file
gcc -Wall -I/usr/local/include -c test_gsl.c #Compile
gcc test_gsl.o -lgsl -lgslcblas -lm #Link libraries

