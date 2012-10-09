CC=c++

BUILD=build
SOURCE=$(wildcard src/*.cc)
BIN=$(BUILD)/thread

MAGEPATH=../mage
INCPATH=$(MAGEPATH)/src
LIBPATH=$(MAGEPATH)/lib

CCFLAGS=-I$(INCPATH) -Wall
LDFLAGS=-L$(LIBPATH) -Llib -lmage -framework OpenGL -framework Cocoa -lglfw

all: compile run

compile: clean
	mkdir -p $(BUILD)
	$(CC) $(SOURCE) -o $(BIN) $(CCFLAGS) $(LDFLAGS)

run:
	./$(BIN)

clean:
	rm -rf $(BUILD)
