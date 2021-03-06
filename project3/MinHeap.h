//
//  MinHeap.h
//  project3
//
//  Created by Dirk on 11/17/18.
//  Copyright © 2018 Dirk. All rights reserved.
//

#ifndef MinHeap_h
#define MinHeap_h

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct minHeapNode {
	int value;
} node;

typedef struct minHeap {
	int size;
	node *element;
} minHeap;

//Heap functions
minHeap createMinHeap(int);
void buildMinHeap(minHeap*, int*, int);
void insert(minHeap*, int);
void removeNode(minHeap*);
void percolate(minHeap*, int);
void levelOrder(minHeap*);
void inOrder(minHeap*, int);
void displayAsHeap(minHeap*, int);

//Helper functions
int findParent(int);
int findLeftChild(int);
int findRightChild(int);
void swap(node*, node*);
int searchHeap(minHeap*, int);
int checkAVLheap(minHeap*);

#endif /* MinHeap_h */
