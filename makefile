BUILD=build
SOURCE=src/main.cc src/Thread.cc src/Player.cc
BIN=$(BUILD)/thread

CC=g++

MAGEPATH=../mage
INCPATH=$(MAGEPATH)/src
LIBPATH=$(MAGEPATH)/lib

CCFLAGS=-I $(INCPATH) -L $(LIBPATH) -lmage -arch x86_64 -framework OpenGL -framework Cocoa -lglfw

all: compile run

compile: clean
	mkdir -p $(BUILD)
	$(CC) $(SOURCE) -o $(BIN) $(CCFLAGS)

run:
	./$(BIN)

clean:
	rm -rf $(BUILD)
