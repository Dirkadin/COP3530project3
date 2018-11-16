//
//  main.c
//  project3
//
//  Created by Dirk on 11/13/18.
//  Copyright © 2018 Dirk. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
	
	printf("\n\n%s", selection);
	
	return 0;
}
