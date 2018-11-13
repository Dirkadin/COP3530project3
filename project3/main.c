//
//  main.c
//  project3
//
//  Created by Dirk on 11/13/18.
//  Copyright © 2018 Dirk. All rights reserved.
//

#include <stdio.h>

int size = 0;

void startGame() {
	
	printf("This program lets the user create a Binary Search Tree or a Heap.\n\n");
	printf("It asks the user to enter the number of nodes to be created.\n\n");
	printf("Then it asks the user to enter the data values for thespecified number ofnodes.\n\n");
	printf("Then it asks the user to enter the data values for thespecified number ofnodes.\n\n");
	printf("-------------------------------------------------------------------------------------------\n\n");
	
	printf("Enter the number of nodes in the structureto be initially created: ");
	scanf("%d", &size);
	
	int myNum[size];
	for (int i = 0; i < size; i++) {
		printf("\n\nEnter the data value to be placed in the node: ");
		scanf("%d", &myNum[i]);
	}
	
	char *selection = NULL;
	printf("What do you wish to create –a Binary search Tree (T) or a Min-Heap (H)?: ");
	scanf("%c", selection);
	
	printf("\n\n%s", selection);
	
}

int main(int argc, const char * argv[]) {
	
	startGame();
	
	return 0;
}
