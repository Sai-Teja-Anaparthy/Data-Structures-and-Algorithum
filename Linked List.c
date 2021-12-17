/*******************************************************************************************
 * File Name	: Lab1.c
 * Author	: Shamseddin Elmasri
 * Date		: Feb 18, 2021
 * Description	: This file is the skeleton for Lab 1 (Linked Lists). A linked list has already been created.
 *		  insertNode() and deleteNode() functions have been defined for you.
 * Instructions	:
 *			- Complete InsertNode() and deleteNode() functions.
 *			- Modify printLinkedList() function to display the total number of vowels in the list.
 *			- Do not modify the main() function or any other line of code.
 *
 *
 * Student Name: SAI TEJA ANAPARTHY
 * Student Number:8696855
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>



 /* Definition of linked list node */
typedef struct Node {

	char dataField;
	struct Node* ptrNextNode;	// Pointer to next node in the list

} Node_t;



/* Private Functions Prototypes */
void createList(Node_t** ptrHead, char* data);
void printLinkedList(Node_t* head);
void insertNode(Node_t** ptrHead, char data, int targetPosition);
void deleteNode(Node_t** ptrHead, uint8_t targetPosition);
void deleteList(Node_t** ptrHead);

/*** Do not change anything in this function ***/
int main(void)
{
	char mixedLetters[14] = { 'h','Y','V','w','R','U','a','j','o','M','q','Z','F','t' };
	char extraLetters[3] = { 'B','E','s' };

	// Define linked list head
	Node_t* head = NULL;
	Node_t** ptrHead = &head;

	createList(ptrHead, mixedLetters);		// Create linked list
	printLinkedList(head);				// Print out the linked list

	deleteNode(ptrHead, 4);
	insertNode(ptrHead, extraLetters[0], 0);
	insertNode(ptrHead, extraLetters[1], 3);
	insertNode(ptrHead, extraLetters[2], 15);
	printf("\nAfter modifying the list:\n");
	printLinkedList(head);               // Print out the linked list

	deleteList(ptrHead);
	printf("\nAfter deleting all nodes:\n");
	printLinkedList(head);				// Print out the linked list

	return 0;
}

// FUNCTION      : createList()
// DESCRIPTION   : This function creates a linked list
// PARAMETERS    :
//		Node_t** ptrHead - Used to store address of header pointer
//		char data	 - Data to be stored in the list
// RETURNS       : Nothing
void createList(Node_t** ptrHead, char* data) {

	Node_t* newNode = NULL;							// Used for pointing to new node
	Node_t* currentNode = NULL;						// Used for traversing

	for (int i = 0; i < 14; i++) {

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

	newNode->ptrNextNode = NULL;						// Set pointer to next node as null
}

// FUNCTION      : 	PrintLinkedList()
// DESCRIPTION   : 	This function prints out the data and address of each
//			node along with its next nodes address in the list.
//			The total number of nodes in the list is also printed.
// PARAMETERS    : 	Node_t *head: Pointer to head node
// RETURNS       : 	nothing
void printLinkedList(Node_t* head) {

	uint8_t nOfNodes = 0;// Counter used to count number of nodes in the list
	uint8_t nOfVowels = 0;// Counter used to count the number of vowels in the list
	Node_t* node;
	node = head;				// Pointing to the head of the list

	// Traverse through the whole list
	while (node != NULL) {

		printf("Data = %c\t node address: %p\t next node: %p\n",	// Print list with address

			node->dataField, node, node->ptrNextNode);			// of each node and its next node

		if (node->dataField == 'a' || node->dataField == 'e' || node->dataField == 'i' || node->dataField == 'o' || node->dataField == 'u' || node->dataField == 'A' || node->dataField == 'E' || node->dataField == 'I' || node->dataField == 'O' || node->dataField == 'U')
		{
			nOfVowels++;                      // Increment counter
		}

		nOfNodes++;							// Increment counter

		node = node->ptrNextNode;					// Go to next node
	}
	printf("\nNumber of nodes in the list is: %u\n", nOfNodes);
	printf("\nNumber of vowles in the list is: %u\n", nOfVowels);
}

// FUNCTION      : 	insertNode()
// DESCRIPTION   : 	This function inserts a node into the linked list at a particular position
// PARAMETERS    :
//		Node_t** ptrHead	- Used to store address of header pointer
//	        char data 		- Data to be stored in the inserted node
//		int targetPosition	- Desired position in the linked list for the node to be inserted at
// RETURNS       :	Nothing

void insertNode(Node_t** ptrHead, char data, int targetPosition) {
	int i;
	Node_t* newNode;             // Used for pointing to new node
	Node_t* tempPt;             // Used for temperorily hold the address

	/* Create new node, and check if allocation was successfull */
	newNode = (Node_t*)malloc(sizeof(Node_t));

	if (newNode == NULL)
	{
		printf("Unable to allocate memory\n");
	}
	else if (targetPosition == 0)           //check condition for inserting at 0 position
	{

		newNode->dataField = data;        // Copy data into new node's data field

		newNode->ptrNextNode = (*ptrHead);

		*ptrHead = newNode;              // copy newnode into pointerHead

		return;

	}

	else

	{
		newNode->dataField = data;            // Copy data into new node's data field

		newNode->ptrNextNode = (*ptrHead);          // Copy ptrHead into new node's ptrNextNode

		tempPt = (*ptrHead);                // copy pointer head in temp pointer

		//Traverse to the n - 1 position
		for (i = 0; i < targetPosition - 1; i++)
		{
			tempPt = tempPt->ptrNextNode;

			if (tempPt == NULL)

				break;
		}
		if (tempPt != NULL)
		{
			newNode->ptrNextNode = tempPt->ptrNextNode;

			tempPt->ptrNextNode = newNode;

		}

	}

}

// FUNCTION      : 	deleteNode()
// DESCRIPTION   : 	This function deletes a node defined by its position in the linked list
// PARAMETERS    :
//			Node_t** ptrHead	- Used to store address of header pointer
//			int targetPosition	- Desired position of node to be deleted
// RETURNS       :	Nothing
void deleteNode(Node_t** ptrHead, uint8_t targetPosition) {
	uint8_t i;
	Node_t* delNode;
	Node_t* prevNode;

	if (*ptrHead == NULL)
	{
		printf("List is already empty.");
	}
	else
	{
		delNode = *ptrHead;             //copy ptrHead to delnode

		prevNode = *ptrHead;            //copy ptrHead to prevnode

		for (i = 2; i <= targetPosition + 1; i++)          //condition to delete node at 4th poistion
		{
			prevNode = delNode;

			delNode = delNode->ptrNextNode;

			if (delNode == NULL)

				break;
		}

		if (delNode != NULL)         //check if deletenode is null
		{
			if (delNode == *ptrHead)      //check if delete node is equal to head

				*ptrHead = (*ptrHead)->ptrNextNode;    //traverse till targeted location

			prevNode->ptrNextNode = delNode->ptrNextNode;

			delNode->ptrNextNode = NULL;

			free(delNode);           //memory free
		}
	}
}

// FUNCTION      : 	deleteList()
// DESCRIPTION   : 	This function deletes all nodes in the list
// PARAMETERS    : 	Node_t** ptrHead	- Used to store address of header pointer
// RETURNS       :	Nothing
void deleteList(Node_t** ptrHead) {

	Node_t* tempPtr;      // Used for temperorily hold the address

	while (*ptrHead != NULL)
	{
		tempPtr = *ptrHead;

		*ptrHead = (*ptrHead)->ptrNextNode;

		free(tempPtr);      //Used to free space
	}
}
