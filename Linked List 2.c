/*******************************************************************************************
 * File Name	: Mid-term Exam.c
 * Author	: Shamseddin Elmasri
 * Date		: Jan 22, 2021
 *
 * Description	: This file is the skeleton code for part 1 of the mid-term exam. Two singly linked lists have been created.
 *		  createList(), printList(), and deleteList() functions have been implemented for you.
 *
 * Objective:	  To connect two existing singly linked lists and modify the new list.
 *
 * Instructions	:
 *		  Implement the following functions:
 *
 *		  connectLists(): Connects the two lists together by linking the tail of list 1 with the head of list 2. (8 points)
 *		  sortList() sorts the new list in the descending order (from greater to smaller).	(2 points)
 *		  deleteLastNode() Deletes the very last node (tail) of the new list.	(5 points)
 *
 * 		  Note: You may need to define an extra function for swapping nodes to perform the sorting
 *
 *
 *
 * Student Name:
 * Student Number:
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>



 /* Definition of linked list node */
typedef struct Node {

	int dataField;
	struct Node* ptrNextNode;	// Pointer to next node in the list (NULL if it's the tail)

} Node_t;



/* Private Functions Prototypes */
void createList(Node_t** ptrHead, int* data, int listSize);
void printList(Node_t* head);
void deleteList(Node_t** ptrHead);
void sortList(Node_t* head);
void connectLists(Node_t* head1, Node_t* head2);
void deleteLastNode(Node_t* head);
void swapNodes(Node_t* node1, Node_t* node2);


int main(void)
{
	int list1_Items[5] = { 7, 25, 61, 84, 2 };
	int list2_Items[7] = { 38, 95, 11, 8, 76, 72, 60 };

	// Define linked list head
	Node_t* head1 = NULL;
	Node_t* head2 = NULL;

	createList(&head1, list1_Items, 5);		// Create list 1
	createList(&head2, list2_Items, 7);		// Create list 2
	printf("List 1:\n");
	printList(head1);				// Print out the list 1
	printf("List 2:\n");
	printList(head2);				// Print out the list 2

	connectLists(head1, head2);			// Connect lists (new list starts from head 1)

	sortList(head1);				// Sort new list in descending order

	printf("New list:\n");
	printList(head1);				// Print out new list

	deleteLastNode(head1);				// Delete last node in new list
	printf("After deleting last node:\n");
	printList(head1);				// Print out new list

	deleteList(&head1);				// Delete the new list

	printf("\nAfter deleting all nodes:\n");
	printList(head1);				// Double check if deleting was successfully done

	return 0;
}



// FUNCTION      :	createList()
// DESCRIPTION   :	This function creates a linked list
// PARAMETERS    :	
//			Node_t** ptrHead: Used to store address of head pointer
//			char data: Data to be stored in the list
// RETURNS       :	Nothing
void createList(Node_t** ptrHead, int* data, int listSize) {

	Node_t* newNode = NULL;							// Used for pointing to new node
	Node_t* currentNode = NULL;						// Used for traversing

	for (int i = 0; i < listSize; i++) {

		/* Create new node, and check if allocation was successfull */
		newNode = malloc(sizeof(Node_t));

		if (newNode != NULL) {

			newNode->dataField = data[i];				// Copy data into new node's data field
		}
		else {

			printf("No sufficient memory!\n");
			return;
		}

		/* Set first node as head */
		if (i == 0) {

			*ptrHead = newNode;
			currentNode = *ptrHead;					// Start traversing from head
			continue;
		}

		currentNode->ptrNextNode = newNode;				// Place new node at the end of the list	
		currentNode = currentNode->ptrNextNode;				// Traverse to next node			
	}

	newNode->ptrNextNode = NULL;						// Set tail's next pointer to null		
}



// FUNCTION      : 	printList()
// DESCRIPTION   : 	This function prints out the data and address of each
//			node along with its next nodes address in the list.
//			The total number of nodes in the list is also printed.
// PARAMETERS    : 	Node_t *head: Pointer to head node
// RETURNS       : 	nothing
void printList(Node_t* head) {

	uint8_t nOfNodes = 0;			// Counter used to count number of nodes in the list
	Node_t* node;
	node = head;				// Pointing to the head of the list

	// Traverse through the whole list
	while (node != NULL) {

		printf("Data = %i\t node address: %p\t next node: %p\n",	// Print list with address
			node->dataField, node, node->ptrNextNode);			// of each node and its next node

		nOfNodes++;							// Increment counter
		node = node->ptrNextNode;					// Go to next node
	}

	printf("\nNumber of nodes in the list is: %u\n", nOfNodes);
}



// FUNCTION      : 	deleteList()
// DESCRIPTION   : 	This function deletes all nodes for a given list
// PARAMETERS    : 	Node_t** ptrHead: Used to store address of head pointer
// RETURNS       :	Nothing
void deleteList(Node_t** ptrHead) {

	Node_t* tempPtr;

	while (*ptrHead != NULL)
	{
		tempPtr = *ptrHead;
		*ptrHead = (*ptrHead)->ptrNextNode;
		free(tempPtr);
	}
}



// FUNCTION      : 	connectLists()
// DESCRIPTION   : 	This function connects two lists by linking the tail
//			of the first list with the head of the second list
// PARAMETERS    : 	
//			Node_t* head1: pointer to head of list 1
//			Node_t* head2: pointer to head of list 2
//
// RETURNS       :	Nothing
void connectLists(Node_t* head1, Node_t* head2) {
	Node_t* list_1;
	list_1 = head1;
	Node_t* list_2;
	list_2 = head2;
	if (list_1 - 1 == NULL) {

	}
	if (list_2 == NULL) {

	}
	while (list_1->ptrNextNode!= NULL) {
		list_1 = list_1->ptrNextNode;
	}
	list_1->ptrNextNode = list_2;
}




// FUNCTION      : 	deleteLastNode()
// DESCRIPTION   : 	This function deletes the last node of a linked list
// PARAMETERS    : 	Node_t* head: pointer to head of the list
// RETURNS       :	Nothing
void deleteLastNode(Node_t* head) {
	Node_t* toDelete;
	Node_t* secondLastNode;

	if (head == NULL)
	{
		printf("List is already empty.");
	}
	else
	{
		toDelete = head;
		secondLastNode = head;

		/* Traverse to the last node of the list */
		while (toDelete->ptrNextNode != NULL)
		{
			secondLastNode = toDelete;
			toDelete = toDelete->ptrNextNode;
		}

		if (toDelete == head)
		{
			head = NULL;
		}
		else
		{
			/* Disconnect link of second last node with last node */
			secondLastNode->ptrNextNode = NULL;
		}

		/* Delete the last node */
		free(toDelete);

	}
}
//FUNCTION: 	swapNode()
// DESCRIPTION   : 	This function swaps the linked list 
// PARAMETERS    : 	Node_t* head: pointer to head of the list
// RETURNS       :	Nothing
void swapNodes(Node_t* node1, Node_t* node2) {
	char temp = node1->dataField;
	node1->dataField = node2->dataField;
	node2->dataField = temp;
}

// FUNCTION      : 	sortList()
// DESCRIPTION   : 	This function sorts the linked list in the ascendiong order
// PARAMETERS    : 	Node_t* head: pointer to head of the list
// RETURNS       :	Nothing
void sortList(Node_t* head) { 
	Node_t* node;
	Node_t* stop = NULL;
	int flag = 0;
	if (head == NULL) {
		printf("Erro, unable to sort empty list\n");
		return;
	}
	while (!flag) {
		flag = 1;
		node = head;
		while (node->ptrNextNode != stop) {
			if (node-> dataField > node->ptrNextNode->dataField){
			swapNodes(node, node->ptrNextNode);
			flag = 0;
		  }
		  node = node->ptrNextNode;
			}
		stop = node;
	}
	

}