CC = g++
CFLAGS = -Wall -Wextra -O2
LDLIBS = -lm

build: algo1_test.o algo2_test.o algo3_test.o

run-best:
	./test1

run-p1:
	./test1

run-p2:
	./test2

run-p3:
	./test3

SegmentTree.o: SegmentTree.cpp
	g++ SegmentTree.cpp -c $(CFLAGS)

algo1_test.o: main2.cpp SegmentTree.o
	g++ SegmentTree.o main2.cpp -o test1 $(CFLAGS)

SparseTable.o: SparseTable.cpp
	g++ SparseTable.cpp -c $(CFLAGS)

algo2_test.o: main1.cpp SparseTable.o
	g++ SparseTable.o main1.cpp -o test2 $(CFLAGS)

SquareRoot.o: SquareRoot.cpp
	g++ SquareRoot.cpp -c $(CFLAGS)

algo3_test.o: main3.cpp SquareRoot.o
	g++ SquareRoot.o main3.cpp -o test3 $(CFLAGS)

.PHONY: clean

clean:
	rm -rf *.o test1 test2 test3 test.in test.out
