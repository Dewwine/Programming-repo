targets = main.bin test.bin
CC = gcc 
C_OPTS = -std=gnu11 -g -Wall -Wextra -Wformat-security -Wfloat-equal -Wshadow -Wconversion -Wlogical-not-parentheses -Wnull-dereference -I./src 

all: clean prep gen_static_lib compile run

clean:
	rm -rf dist
	rm -rf shared
prep:
	mkdir dist
	mkdir shared

compile: main.bin test.bin

gen_static_lib: 
	cp list/list.h ./shared
	cp data/data.h ./shared
	$(CC) $(C_OPTS) -c list/list.c -o ./dist/list.o
	$(CC) $(C_OPTS) -I./shared -c data/data.c -o ./dist/data.o
	ar rcs ./dist/libmylib.a ./dist/list.o ./dist/data.o
	cp ./dist/libmylib.a ./shared

gen_dynamic_lib: 
	cp list/list.h ./shared
	cp data/data.h ./shared
	$(CC) -c $(C_OPTS) -fPIC -I./shared list/list.c -o ./dist/list.o
	$(CC) -c $(C_OPTS) -fPIC -I./shared data/data.c -o ./dist/data.o
	$(CC) -shared dist/list.o dist/data.o -o dist/libmylib.so
	cp ./dist/libmylib.so ./shared

main.bin: src/main.c
	$(CC) $(C_OPTS) -I./shared $< -lmylib -L./shared -Wl,-rpath,./shared -o ./dist/$@
	
test.bin: test/test.c
	$(CC) $(C_OPTS) -I./shared $< -lmylib -L./shared -Wl,-rpath,./shared -o ./dist/$@

run: clean prep compile
	./dist/main.bin
	
doxygen:
	doxygen Doxyfile
format: #TODO

tidy: # TODO

