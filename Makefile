# rbtrie をつくる Makefile
#
VPATH = src include
CPPFLAGS = -I include
#CC = gcc -O3 -Wall -Wextra -lm
CC = gcc -g3 -Wall -Wextra -lm

hicuts: hicuts.o 

clean:
	rm *.o
