//
//  BinarySearchTree.c
//  BinarySearchTree
//
//  Created by Dirk on 10/24/18.
//  Copyright © 2018 Dirk. All rights reserved.
//

#include "BinarySearchTree.h"

//Adds a new value to the tree
Tree* add(Tree *node, int value) {
	//If the node doesn't exist add new node and allocate memory
	if (node == NULL) {
		node = (Tree*) malloc(sizeof (Tree));
		if (node == NULL) { //Legacy: make sure malloc was able to allocate memeory
			return NULL;
		}
		
		//Assign values to new node
		node->left = NULL;
		node->right = NULL;
		node->value = value;
		node->counter = 1;
		node->height = 1;
		
		return node;
	}
	//Add new node to correct side
	if (node->value == value) {
		node->counter++;
		return node;
	}
	
	node->height = max(height(node->left), height(node->right)) + 1;
	
	if (node->value > value) {
		node->left = add(node->left, value);
	} else {
		node->right = add(node->right, value);
	}
	
	//Get balance of current node
	int balance = getBalance(node);
	
	//Rotation cases based on balanceof node
	//One rotation
	//LL
	if (balance > 1 && value < node->left->value) {
		return rotateRight(node);
	}
	//RR
	if (balance < -1 && value > node->right->value) {
		return rotateLeft(node);
	}
	//Two rotation
	//LR
	if (balance > 1 && value > node->left->value) {
		node->left = rotateLeft(node->left);
		return rotateRight(node);
	}
	//RL
	if (balance < -1 && value < node->right->value) {
		node->right = rotateRight(node->right);
		return rotateLeft(node);
	}
	
	return node;
}

//Frees all of the allocated memory for the tree
void freeTree(Tree* node) {
	//Yer done
	if (node == NULL) {
		return;
	}
	
	//Recursively free da tree
	freeTree(node->left);
	freeTree(node->right);
	
	//Free yoself
	free(node);
}

//Deletes a node with a given value
Tree* delete(Tree *node, int value) {
	Tree *temp = NULL;
	
	//If node is null return null
	if (node == NULL) {
		return NULL;
	}
	
	//If the node value and delete value are the same, decrement counter
	if (node->value == value) {
		if (node->counter > 1) {
			node->counter--;
			return node;
		}
	}
	
	//If value is less than current node delete left
	if (value < node->value) {
		
		node->left = delete(node->left, value);
		
	} else if (value > node->value) { //If value is greater, delete right
		
		node->right = delete(node->right, value);
		
	} else if (node->left && node->right) { //If both pointers are populated - even case
		
		temp = findMin(node->right); //Find smallest node on the right
		node->value = temp->value; //Move smallest node up
		node->right = delete(node->right, node->value); //deleted right node
		
	} else if (node->left == NULL) { //Null checking
		node = node->right;
		
	} else if (node->right == NULL) {
		node = node->left;
	}
	
	free(temp); //Free that memory my dude
	
	return node;
}

//Finds the lowest value in the tree
Tree* findMin(Tree *node) {
	//If node is null return the sent node
	if (node == NULL) {
		return node;
	}
	
	//If left node is null return sent node
	if (node->left == NULL) {
		return node;
	}
	
	//Recursion left until we find null
	return findMin(node->left);
}

//Finds the loweset level in the tree
int findDepth(Tree *node) {
	
	//Don't incrememnt if node is NULL
	if (node == NULL) {
		return 0;
	}
	
	//Recursively find dept for each child
	int left = findDepth(node->left);
	int right = findDepth(node->right);
	
	//Return added up depth
	if (left > right) {
		return left + 1;
	} else {
		return right + 1;
	}
}

void traversePreOrder(Tree* node) {
	if (node != NULL) {
		printf("%d ", node->value);
		traversePreOrder(node->left);
		traversePreOrder(node->right);
	}
}

void traversePostOrder(Tree* node) {
	if (node != NULL) {
		traversePostOrder(node->left);
		traversePostOrder(node->right);
		printf("%d ", node->value);
	}
}

void traverseInOrder(Tree* node) {
	if (node != NULL) {
		traverseInOrder(node->left);
		printf("%d ", node->value);
		traverseInOrder(node->right);
	}
}

Tree** createQueue(int* head, int* tail) {
	Tree** queue = (Tree**)malloc(sizeof(Tree*));
	
	*head = 0;
	*tail = 0;
	
	return queue;
}

void enQueue(Tree **queue, int *tail, Tree *node) {
	queue[*tail] = node;
	(*tail)++;
}

Tree* deQueue(Tree **queue, int *head) {
	(*head)++;
	return queue[*head - 1];
}

void traverseLevelOrder(Tree* root) {
	
	int head;
	int tail;
	
	Tree **queue = createQueue(&head, &tail);
	Tree *temp = root;
	
	while (temp) {
		
		//Print current node
		printf("%d\t", temp->value);
		
		if (head == tail && head != 0) {
			break;
		}
		
		//En-queue left child if present
		if (temp->left) {
			enQueue(queue, &tail, temp->left);
		}
		
		//En-queue right chile if present
		if (temp->right) {
			enQueue(queue, &tail, temp->right);
		}
		
		//Dequeue current node
		temp = deQueue(queue, &head);
	}
}

Tree* rotateRight(Tree* root) {
	Tree *newRoot = root->left;
	Tree *temp = newRoot->right;
	
	//Rotation
	newRoot->right = root;
	root->left = temp;
	
	//Updating the height
	root->height = max(height(root->left), height(root->right));
	newRoot->height = max(height(newRoot->left), height(newRoot->right));
	
	return newRoot;
}

Tree* rotateLeft(Tree* root) {
	Tree *newRoot = root->right;
	Tree *temp = newRoot->left;
	
	//Rotation
	newRoot->left = root;
	root->right = temp;
	
	//Update height
	root->height = max(height(root->left), height(root->right));
	newRoot->height = max(height(newRoot->left), height(newRoot->right));
	
	return newRoot;
}

///Helper functions
//Returns the integer height of a node
int height(Tree *node) {
	if (node == NULL) {
		return 0;
	}
	return node->height;
}

//Returns the larger of two Integers
int max(int x, int y) {
	if (x > y) {
		return x;
	} else {
		return y;
	}
}

//Returns the balance of the provided node
int getBalance(Tree* node) {
	return height(node->left) - height(node->right);
}

void displayAsTree(Tree* node) {
	
	int head, tail;
	int height = node->height;
	int totalNodes = pow(2, (double) height + 1) - 1;
	
	Tree *temp = node;
	
	//Dummy node to show that this spot is blank
	Tree *dummy = (Tree*) malloc(sizeof (Tree));
	dummy->counter = 0;
	dummy->height = 0;
	dummy->left = NULL;
	dummy->right = NULL;
	dummy->value = -1;
	
	Tree** queue = createQueue(&head, &tail);
	int printArray[totalNodes];
	int index = 0;
	
	printArray[index] = node->value;
	index++;
	
	//Add tree to a queue to get a level order array of values
	while (temp) {
		if (head == tail && head != 0) {
			break;
		}
		
		if (temp->left == NULL && temp->right == NULL) {
			printf("both null");
		} else {
			if (temp->left) {
				enQueue(queue, &tail, temp->left);
				printArray[index] = temp->left->value;
				index++;
			} else {
				printArray[index] = -1;
				index++;
			}
			
			if (temp->right) {
				enQueue(queue, &tail, temp->right);
				printArray[index] = temp->right->value;
				index++;
			} else {
				printArray[index] = -1;
				index++;
			}
		}
		
		
		temp = deQueue(queue, &head);
	}
	
	free(dummy);
	free(queue);
	
	int topDown = node->height; //how many initial tabs
	int bottomUp = 0; //how many things to print
	index = 0;
	
	int i, k, j;
	
	for (i = 0; i < 10; i++) {
		printf("%d ", printArray[i]);
	}
	
	printf("\n");
	
	//Rows
	for ( i = 0; i < sqrt((sizeof(printArray)/sizeof(int))) + 1; ++i) {
		while (topDown !=  -1) {
			for ( k = 0; k < pow(2, topDown) - 1; k++) { //good
				printf("   ");
			}
			printf("%3d", printArray[index]);
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
					if (printArray[index] == -1) {
						printf("   ");
					} else {
						printf("%3d", printArray[index]);
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

int searchBST(Tree* node, int key) {
	if (node == NULL) {
		return 0;
	}
	
	if (node->value == key) {
		printf("\nKey found!\n");
		return 1;
	} else if (node->left) {
		searchBST(node->left, key);
	} else if (node->right) {
		searchBST(node->right, key);
	}
	
	return 0;
}

int checkAVL(Tree* node) {
	
	if (node == NULL) {
		return 0;
	}
	
	int balance = getBalance(node);
	
	if (balance == -1 || balance == 0 || balance == 1) {
		checkAVL(node->left);
		checkAVL(node->right);
	} else {
		return 0;
	}

	return 1;
}
