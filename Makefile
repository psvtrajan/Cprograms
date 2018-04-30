#
# @file		: Makefile
# @brief	: To compile the .c files.
# @author	: Thiyagarajan.P
#


CC = gcc
CFLAGS = -g -Wall
OUT = -o
RM = rm -f
BIN := $(patsubst %.c,%,$(wildcard *.c))

#Target "all" 
all: $(BIN)
	
#Compile all .c files and binary will be same name without ".c"
%: %.c
	$(CC) $(OUT) $@ $< $(CFLAGS)

#Remove all the binaries
clean:
	$(RM) $(BIN)
