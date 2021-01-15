 Assignment3: Assignment3.o
	g++ -Wall -std=c++11 -o Assignment3 Assignment3.o

Assignment3.o: Assignment3.cpp BinarySearchTree.h AvlTree.h
	g++ -Wall -std=c++11 -o Assignment3.o -c Assignment3.cpp 

clean:
	rm -rf Assignment3 Assignment3.o