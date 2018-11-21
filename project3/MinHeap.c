//
//  MinHeap.c
//  project3
//
//  Created by Dirk on 11/17/18.
//  Copyright © 2018 Dirk. All rights reserved.
//

#include "MinHeap.h"

//Creates and returns a Min-Heap
minHeap createMinHeap(int size) {
	minHeap mh;
	mh.size = 0;
	return mh;
}

//Builds the min heap
void buildMinHeap(minHeap *mh, int *arr, int size) {
	
	int i;
	
	for ( i = 0; i < size; ++i) {
		if (mh->size) {
			mh->element = realloc(mh->element, (mh->size + 1) *sizeof(node));
		} else {
			mh->element = malloc(sizeof(node));
		}
		node newNode;
		newNode.value = arr[i];
		mh->element[(mh->size)++] = newNode;
	}
	
	for(int i = (mh->size - 1) / 2; i >= 0; i--) {
		percolate(mh, i);
	}
	
}

//Inserts node into heap
void insert(minHeap *mh, int value) {
	if (mh->size) {
		mh->element = realloc(mh->element, (mh->size + 1) * sizeof(node));
	} else {
		mh->element = malloc(sizeof(node));
	}
	
	node newNode;
	newNode.value = value;
	
	int i = (mh->size)++;
	while (i && newNode.value < mh->element[findParent(i)].value) {
		mh->element[i] = mh->element[findParent(i)];
		i = findParent(i);
	}
	
}

//Removes a node
void removeNode(minHeap *mh) {
	if (mh->size) {
		mh->element[0] = mh->element[mh->size - 1];
		//Need to update with some sort of memory reallocation
		percolate(mh, 0); //revalideate our heap
	} else {
		//If passed heep is empty
		printf("The heap you passed is empty!!!");
	}
}

void percolate(minHeap *mh, int index) {
	int smallest;
	//Checking to see if MinHeap rules are followed in our array
	if (findLeftChild(index) < mh->size
		&& mh->element[findLeftChild(index)].value < mh->element[index].value) {
		smallest = findLeftChild(index);
	} else {
		smallest = index;
	}
	
	if (findRightChild(index) < mh->size
		&& mh->element[findRightChild(index)].value < mh->element[smallest].value) {
		smallest = findRightChild(index);
	}
	
	//Performs the swap if our smallest element is not at the index
	if (smallest != index) {
		swap(&(mh->element[index]), &(mh->element[smallest]));
		percolate(mh, smallest); //Recursivly checking the rest of the heap
	}
	//My head hurts after that
}

void levelOrder(minHeap *mh) {
	int i;
	for ( i = 0; i < mh->size; i++) {
		printf("%d ", mh->element[i].value);
	}
}

void inOrder(minHeap *mh, int index) {
	if (findLeftChild(index) < mh->size) {
		inOrder(mh, findLeftChild(index));
	}
	printf("%d ", mh->element[index].value);
	if (findRightChild(index) < mh->size) {
		inOrder(mh, findRightChild(index));
	}
}


///MARK: Helper functions
//Returns index of parent
int findParent(int index) {
	return (index - 1) / 2;
}

//Returns index of left child
int findLeftChild(int index) {
	return 2 * index + 1;
}

//Returns index of right child
int findRightChild(int index) {
	return 2 * index + 2;
}

//Swaps data in two nodes
void swap(node *first, node *second) {
	node temp = *first;
	*first = *second;
	*second = temp;
}

int searchHeap(minHeap* mh, int key) {
	if (mh == NULL) {
		return 0;
	}
	
	int i;
	for ( i = 0; i < mh->size; i++) {
		if (mh->element[i].value == key) {
			return 1;
		}
	}
	return 0;
}

int checkAVLheap(minHeap* mh) {
	if (mh == NULL) {
		return 0;
	}
	
	int i;
	
	for ( i = 0; i < mh->size; i++) {
		if (mh->size == 0) {
			return 0;
		}
	}
	
	return 1;
}

void displayAsHeap(minHeap* mh, int size) {
	
	if (mh == NULL) {
		return;
	}
	
	int z, i, j, k;
	
	int height = size;
	printf("%d\n", height);
	height = height / 2;
	printf("%d\n", height);
	
	for ( z = 0; z < 5; z++) {
		printf("%d ", mh->element[z].value);
	}
	
	int topDown = height;
	int bottomUp = 0;
	int index = 0;
	
	for ( i = 0; i < height + 1; ++i) {
		while (topDown !=  -1) {
			for ( k = 0; k < pow(2, topDown) - 1; k++) { //good
				printf("   ");
			}
			printf("%d", mh->element[index].value);
			index++;
			
			//Are thre more things to print?
			if (bottomUp != 0) {
				//How many?
				for ( i = 0; i < pow(2, bottomUp) - 1; i++) {
					//Appropriate number of tabs
					for ( j = 0; j < pow(2, topDown + 1) - 1; j++) {
						printf("   ");
					}
					//print the value
					if (mh->element[index].value == -1) {
						printf("   ");
					} else {
						printf("%d", mh->element[index].value);
					}
					
					index++;
				}
			}
			printf("\n");
			
			topDown--;
			bottomUp++;
		}
	}
}
