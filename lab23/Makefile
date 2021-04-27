targets = main.bin test.bin
CC = g++ 
C_OPTS = -std=gnu++11 -g -Wall -Wextra -Wformat-security -Wfloat-equal -Wshadow -Wconversion -Wlogical-not-parentheses -Wnull-dereference -I./src 
OBJECTS = dist/File.o dist/Permission.o dist/Darray.o

vpath %.hpp src
vpath %.cpp src
vpath %.cpp test
vpath %.o dist
vpath %.bin dist

all: clean prep compile run

clean:
	rm -rf dist
prep:
	mkdir dist

compile: File.o Permission.o Darray.o main.bin test.bin

File.o: File.cpp File.hpp
	$(CC) $(C_OPTS) -c src/File.cpp -Isrc -o dist/File.o
Permission.o: Permission.cpp Permission.hpp
	$(CC) $(C_OPTS) -c src/Permission.cpp -Isrc -o dist/Permission.o
Darray.o: Darray.cpp Darray.hpp
	$(CC) $(C_OPTS) -c src/Darray.cpp -Isrc -o dist/Darray.o

main.bin: main.cpp File.o Permission.o Darray.o
	$(CC) $(C_OPTS) src/main.cpp $(OBJECTS) -Isrc -o dist/main.bin
#	rm -rf $(OBJECTS)
test.bin: test/test.cpp File.o Permission.o Darray.o
	$(CC) $(C_OPTS) test/test.cpp $(OBJECTS) -Isrc -o ./dist/$@
	rm -rf $(OBJECTS)

run: clean prep compile
	./dist/main.bin
	
doxygen:
	doxygen Doxyfile
format: #TODO

tidy: # TODO

