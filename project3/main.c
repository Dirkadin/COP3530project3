//
//  main.c
//  project3
//
//  Created by Dirk on 11/13/18.
//  Copyright © 2018 Dirk. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include "BinarySearchTree.h"
#include "MinHeap.h"

int menu() {
	printf("What do you wish to do?\n");
	printf("Display In-order Traversal (1) Display Level-order Traversal (2) Display Both Traversals (3) Display as a tree (4) SearchHeap(5) InsertHeap(6) Check if AVL(7) Quit(Q)\n");
	printf("Please enter a choice: ");
	
	int choice = -1;
	scanf("%d", &choice);
	
	return choice;
}

int main(int argc, const char * argv[]) {
	
	printf("This program lets the user create a Binary Search Tree or a Heap.\n\n");
	printf("It asks the user to enter the number of nodes to be created.\n\n");
	printf("Then it asks the user to enter the data values for thespecified number ofnodes.\n\n");
	printf("Then it asks the user to enter the data values for thespecified number ofnodes.\n\n");
	printf("-------------------------------------------------------------------------------------------\n\n");
	
	int size = 0;
	printf("Enter the number of nodes in the structureto be initially created: ");
	scanf("%d", &size);
	
	int myNums[size];
	
	for (int i = 0; i < size; i++) {
		printf("\n\nEnter the data value to be placed in the node: ");
		scanf("%d", &myNums[i]);
	}
	
	char selection[1];
	printf("What do you wish to create –a Binary search Tree (T) or a Min-Heap (H)?: ");
	scanf("%s", selection);
	
	if (selection[0] == 'T') { //Tree selected
		//Create Tree
		
		Tree *bst = NULL;
		for (int i = 0; i < size; i++) {
			bst = add(bst, myNums[i]);
		}
		printf("\nTree created successfully!\n");
		
		int menuChoice = 0;
		menuChoice = menu();
		
		switch (menuChoice) {
			case 1:
				traverseInOrder(bst);
				break;
			case 2:
				//level order
				traverseLevelOrder(bst);
				break;
			case 3:
				//in order and level order
				traverseInOrder(bst);
				printf("\n");
				traverseLevelOrder(bst);
				break;
			case 4:
				//Display as tree
				break;
			case 5:
				//Search heap
				break;
			case 6:
				//insert heap
				break;
			case 7:
				//check if avl
				break;
			case 8:
				//quit
				exit(0);
				break;
				
			default:
				//you broke it
				break;
		}
		
	} else if (selection[0] == 'H') { //Min-Heap selected
		//Create Min-Heap
		printf("\nMin-Heap created successfully!\n");
		
		minHeap temp = createMinHeap(size);
		minHeap *mh = &temp;
		buildMinHeap(mh, myNums, size);
		
		for (int i = 0; i < size; i++) {
			printf("%d ", mh->element[i].value);
		}
		
		int menuChoice = 0;
		menuChoice = menu();
		
		switch (menuChoice) {
			case 1:
				//in order
				break;
			case 2:
				//level order
				levelOrder(mh);
				break;
			case 3:
				//in order and level order
				break;
			case 4:
				//Display as tree
				break;
			case 5:
				//Search heap
				break;
			case 6:
				//insert heap
				break;
			case 7:
				//check if avl
				break;
			case 8:
				//quit
				exit(0);
				break;
				
			default:
				//you broke it
				break;
		}
		
	}
	
	return 0;
}
