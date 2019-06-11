CC = g++
CPPFLAGS = -std=c++17 -Wall -pedantic -g -DDEBUG

BIN = $(patsubst %.cpp,%, $(wildcard *.cpp))

all : $(BIN)

test :
	echo $(BIN)

clean:
	$(RM) $(BIN)