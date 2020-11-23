targets = task1.bin task2.bin task3.bin task4.bin task5.bin task6.bin task7.bin task8.bin task9.bin task10.bin task11.bin task12.bin
CC = gcc
C_OPTS = -std=gnu11 -g -Wall -Wextra -Wformat-security -Wfloat-equal -Wshadow -Wconversion -Wlogical-not-parentheses -Wnull-dereference -I./src

all: clean prep compile run

clean:
	rm -rf dist
prep:
	mkdir dist
compile: task1.bin task2.bin task3.bin task4.bin task5.bin task6.bin task7.bin task8.bin task9.bin task10.bin task11.bin task12.bin

task1.bin: src/task1.c
	$(CC) $(C_OPTS) $< -o ./dist/$@
task2.bin: src/task2.c
	$(CC) $(C_OPTS) $< -o ./dist/$@
task3.bin: src/task3.c
	$(CC) $(C_OPTS) $< -o ./dist/$@
task4.bin: src/task4.c
	$(CC) $(C_OPTS) $< -o ./dist/$@
task5.bin: src/task5.c
	$(CC) $(C_OPTS) $< -o ./dist/$@
task6.bin: src/task6.c
	$(CC) $(C_OPTS) $< -o ./dist/$@
task7.bin: src/task7.c
	$(CC) $(C_OPTS) $< -o ./dist/$@
task8.bin: src/task8.c
	$(CC) $(C_OPTS) $< -o ./dist/$@
task9.bin: src/task9.c
	$(CC) $(C_OPTS) $< -o ./dist/$@
task10.bin: src/task10.c
	$(CC) $(C_OPTS) $< -o ./dist/$@
task11.bin: src/task11.c
	$(CC) $(C_OPTS) $< -o ./dist/$@
task12.bin: src/task12.c
	$(CC) $(C_OPTS) $< -o ./dist/$@
run: clean prep compile
	./dist/task1.bin
	./dist/task2.bin
	./dist/task3.bin
	./dist/task4.bin
	./dist/task5.bin
	./dist/task6.bin
	./dist/task7.bin
	./dist/task8.bin
	./dist/task9.bin
	./dist/task10.bin
	./dist/task11.bin
	./dist/task12.bin
format: #TODO

tidy: # TODO

