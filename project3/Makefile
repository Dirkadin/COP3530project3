all: client.x

client.x: main.o BinarySearchTree.o MinHeap.o
	gcc -Wall  main.o BinarySearchTree.o MinHeap.c -o oust.x

countOust.o: BinarySearchTree.c BinarySearchTree.h
	gcc -Wall -c BinarySearchTree.c

DoubleLinkedList.o: MinHeap.c MinHeap.h
	gcc -Wall -c MinHeap.c

gameMain.o: main.c
	gcc -Wall -c main.c

clean:
	rm *.o
	rm *.x
