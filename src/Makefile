#Makefile - compiler for Lab 1



# compiler flags.  -g for debug, -O3 for optimization

CFLAGS=-g -O3



# first target built by default

all:	tokens



# file dependencies

tokenizer.o: tokenizer.h



history.o: history.h



echo.o: echo.c



# compiles the tokenizer

tokens: tokenizer.o history.o echo.o

	cc -o $@ $^ $(CFLAGS)



# deltes the files generated from the compilation

clean:

	rm -f *.o tokens
