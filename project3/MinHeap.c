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


///MARK: Helper functions
//Returns index of parent
int findParent(int x) {
	return (x - 1) / 2;
}

//Returns index of left child
int findLeftChild(int x) {
	return 2 * x + 1;
}

//Returns index of right child
int findRightChild(int x) {
	return 2 * x + 2;
}
