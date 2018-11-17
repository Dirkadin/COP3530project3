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
	
	for (int i = 0; i < size; ++i) {
		if (mh->size) {
			mh->element = realloc(mh->element, (mh->size + 1) *sizeof(node));
		} else {
			mh->element = malloc(sizeof(node));
		}
		node newNode;
		newNode.value = arr[i];
		mh->element[(mh->size)++] = newNode;
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
		validateMinHeap(mh, 0); //revalideate our heap
	} else {
		//If passed heep is empty
		printf("The heap you passed is empty!!!");
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

void validateMinHeap(minHeap *mh, int index) {
	int smallest;
	//Checking to see if MinHeap rules are followed in our array
	if (findLeftChild(index) < mh->size
		&& mh->element[findLeftChild(index)].value < mh->element[index].value) {
		smallest = findLeftChild(index);
	} else {
		smallest = index;
	}
	
	//Performs the swap if our smallest element is not at the index
	if (smallest != index) {
		swap(&(mh->element[index]), &(mh->element[smallest]));
		validateMinHeap(mh, smallest); //Recursivly checking the rest of the heap
	}
	//My head hurts after that
}
