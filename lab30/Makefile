targets = main.bin test.bin
CC = g++
C_OPTS = -std=gnu++11 -g -Wall -Wextra -Wformat-security -Wfloat-equal -Wshadow -Wconversion -Wlogical-not-parentheses -Wnull-dereference -I./src 
OBJECTS = dist/Permission.o dist/File.o dist/Videofile.o dist/Imagefile.o dist/FileArray.o 
# dist/Darray.o dist/VideoArray.o dist/ImageArray.o

vpath %.h src
vpath %.cpp src
vpath %.cpp test
vpath %.o dist
vpath %.bin dist

all: clean prep compile run

clean:
	rm -rf dist
prep:
	mkdir dist

compile: File.o Videofile.o Imagefile.o Permission.o FileArray.o main.bin test.bin

Permission.o: Permission.cpp Permission.h
	$(CC) $(C_OPTS) -c src/Permission.cpp -Isrc -o dist/Permission.o
File.o: File.cpp File.h
	$(CC) $(C_OPTS) -c src/File.cpp -Isrc -o dist/File.o
Videofile.o: Videofile.cpp Videofile.h
	$(CC) $(C_OPTS) -c src/Videofile.cpp -Isrc -o dist/Videofile.o
Imagefile.o: Imagefile.cpp Imagefile.h
	$(CC) $(C_OPTS) -c src/Imagefile.cpp -Isrc -o dist/Imagefile.o
FileArray.o: FileArray.cpp FileArray.h
	$(CC) $(C_OPTS) -c src/FileArray.cpp -Isrc -o dist/FileArray.o
# Darray.o: Darray.cpp Darray.h
# 	$(CC) $(C_OPTS) -c src/Darray.cpp -Isrc -o dist/Darray.o
# VideoArray.o: VideoArray.cpp VideoArray.h
# 	$(CC) $(C_OPTS) -c src/VideoArray.cpp -Isrc -o dist/VideoArray.o
# ImageArray.o: ImageArray.cpp ImageArray.h
# 	$(CC) $(C_OPTS) -c src/ImageArray.cpp -Isrc -o dist/ImageArray.o

main.bin: main.cpp Permission.o File.o Videofile.o Imagefile.o FileArray.o
# Darray.o VideoArray.o ImageArray.o
	$(CC) $(C_OPTS) src/main.cpp $(OBJECTS) -Isrc -o dist/main.bin
#	rm -rf $(OBJECTS)
test.bin: test/test.cpp Permission.o File.o Videofile.o Imagefile.o FileArray.o
# Darray.o VideoArray.o ImageArray.o
	$(CC) $(C_OPTS) test/test.cpp $(OBJECTS) -Isrc -o ./dist/$@
	rm -rf $(OBJECTS)

run: clean prep compile
	./dist/main.bin
	
doxygen:
	doxygen Doxyfile
format: #TODO

tidy: # TODO

