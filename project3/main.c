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

int getKey() {
	printf("What value you would you like to look for or add? ");
	int value = 0;
	scanf("%d", &value);
	return value;
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
				displayAsTree(bst);
				break;
			case 5:
				//Search tree
				menuChoice = searchBST(bst, getKey());
				if (menuChoice == 0) {
					printf("\n%d was not found.\n", menuChoice);
				} else {
					printf("\n%d was found.\n", menuChoice);
				}
			case 6:
				//insert tree
				bst = add(bst, getKey());
				break;
			case 7:
				//check if avl
				menuChoice = checkAVL(bst);
				if (menuChoice == 1) {
					printf("\nBST is balanced!\n");
				} else {
					printf("\nBST is not balanced!\n");
				}
				break;
			case 8:
				//quit
				exit(0);
				break;
				
			default:
				//you broke it
				exit(-1);
				break;
		}
		
	} else if (selection[0] == 'H') { //Min-Heap selected
		//Create Min-Heap
		printf("\nMin-Heap created successfully!\n");
		
		minHeap temp = createMinHeap(size);
		minHeap *mh = &temp;
		buildMinHeap(mh, myNums, size);
		
		int menuChoice = 0;
		menuChoice = menu();
		
		switch (menuChoice) {
			case 1:
				//in order
				inOrder(mh, 0);
				break;
			case 2:
				//level order
				levelOrder(mh);
				break;
			case 3:
				//in order and level order
				inOrder(mh, 0);
				printf("\n");
				levelOrder(mh);
				break;
			case 4:
				//Display as tree
				break;
			case 5:
				//Search heap
				menuChoice = searchHeap(mh, getKey());
				if (menuChoice == 0) {
					printf("\n%d was not found.\n", menuChoice);
				} else {
					printf("\n%d was found.\n", menuChoice);
				}
				break;
			case 6:
				//insert heap
				insert(mh, getKey());
				break;
			case 7:
				//check if avl
				menuChoice = checkAVLheap(mh);
				if (menuChoice == 1) {
					printf("\nMin-Heap is balanced!\n");
				} else {
					printf("\nMin-Heap is not balanced!\n");
				}
				break;
			case 8:
				//quit
				exit(0);
				break;
				
			default:
				//you broke it
				exit(-1);
				break;
		}
		
	}
	
	return 0;
}
