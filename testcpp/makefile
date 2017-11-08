CC=g++
prog=test
FLAGS=-g -lstdc++

OBJS=main.o test.o

all:$(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(prog)

main.o:main.cpp test.h
	$(CC) $(FLAGS) main.cpp test.h -c

test.o:test.cpp test.h
	$(CC) $(FLAGS) test.cpp test.h -c

.PHONY:clean
clean:
	rm -rf $(OBJS) $(prog) core
