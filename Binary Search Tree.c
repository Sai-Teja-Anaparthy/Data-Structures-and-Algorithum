/*******************************************************************************************
 * File Name	: Lab3.c
 * Author	: Shamseddin Elmasri
 * Date		: Mar 11, 2021
 * Description	: This file is the skeleton for Lab 3 (Binary Search Tree).

 * Instructions	:
 *			1) Complete the structure for the binary tree nodes. This structure should contain a data field,
 *                         and two pointers (one for right child and the other for the left child).
 *                         You may add more fields to the structure if necessary.
 *
 *	                2) Complete the following functions:
 *		               
 *                              insertNode(): Creates a new node, inserts it to the binary search tree, 
 *                                            and updates the height of the tree and its total number of nodes
 *		                
 *                              printInOrder(): Prints all the nodes in the tree in the ascending order
 *		                
 *                              deleteNode(): Deletes a specific node in the tree. 
                                              (Cover all cases: node with no child, node with one child, and node with two children)
 *		                
 *                              deleteTree(): Deletes entire tree.
 *
 *     			3) Uncomment the commented lines only to test your work for the intermediate and advanced outcomes, otherwise 
 *                         do not modify any line in main() function.
 *              
 *                      4) You may add more functions for your program, however these functions must not be called from main().
 *
 *
 * Student Name: SAI TEJA ANAPARTHY
 * Student Number: 8696855
 * Reference: https://www.thegeekstuff.com/2013/02/c-binary-tree/
 * https://www.geeksforgeeks.org/tree-traversals-inorder-preorder-and-postorder/
 *  https://www.codepoc.io/blog/c-programming/4868/program-to-insert-and-delete-a-node-from-the-binary-search-tree
 * https://www.geeksforgeeks.org/write-a-c-program-to-delete-a-tree/
 *
 */

#include <stdio.h>
#include <stdlib.h>



#define SCALE_FACTOR 5
#define TRUE 1
#define FALSE 0


int a[16] = { 0 };      //array used to store nodes for second tree (intermediate outcomes)



/* Definition of tree nodes*/
typedef struct Node {
   int Data;
   struct Node *left;
   struct Node *right;

}treeNode;



/* Private Function Prototypes*/
void insertNode(treeNode** node, int value);
void printInOrder(treeNode* root);
void deleteNode(treeNode** root, int value);
void deleteTree(treeNode** node);
void search (treeNode **, int,treeNode **, treeNode **, int *);

void postOrderCopy(treeNode* node);
int scaleUpAndDeleteOdd(int array[], int);
void createNewTree(int* array, treeNode** root);
void printPreOrder(treeNode* root);
int treeHeight(treeNode* node);



int main()
{
        int input[15] = { 43, 68, 77, 53, 12, 8, 59, 30, 16, 74, 36, 61, 20, 94, 2 };

        treeNode* treeRoot = NULL;
        
        int noOfNodes = 0;      // Total number of nodes in the tree
              
        /* Insert nodes into the tree */
        for (int i = 0; i < 15; i++) {
                
                insertNode(&treeRoot, input[i]);
        }

        printf("Inorder traversal of the given tree \n");
        printInOrder(treeRoot);
         
         /*********Advanced Outcomes***************
     
        int height = treeHeight(treeRoot);

        printf("\nThe tree has a height of %i and contains %i number nodes\n", height, noOfNodes);
        
         *******************************************/

        printf("\n");

        /***********Intermediate Outcomes****************
        
        postOrderCopy(treeRoot);        // Copy tree into the globally defined array 'a' in post-order traversal
        
        // Print out elements of array 'a' 
        for (int i = 0; i < 15; i++) {

                printf("%i ", a[i]);
        }
        
        ***********************************************/
        
        printf("\n");

        /************* Advanced Outcomes ****************
        
        height = treeHeight(treeRoot);
        printf("\nThe tree has a height of %i and contains %i number nodes\n", height, noOfNodes);
        

        ************************************************/

       
        /***********This section is prepared to test the tree*****************/
        int test[] = { 20, 43, 59, 77, 8 };                                  //
                                                                             //   
        for (int i = 0; i < sizeof test / sizeof * test; i++) {              //
                                                                             //
                printf("\nDelete %i:", test[i]);                             //
                deleteNode(&treeRoot, test[i]);                              //
                printf("\nInorder traversal of the modified tree \n");       //
                printInOrder(treeRoot);                                      //
        }                                                                    //
        /*********************************************************************/

        deleteTree(&treeRoot);      // Delete first tree

        // Intermediate Outcomes
        /*****************************************

        int numberOfElements = scaleUpAndDeleteOdd(a, SCALE_FACTOR);

        // Print out elements of array 'a' after modification
        for (int i = 0; i < numberOfElements; i++) {

                printf("%i ", a[i]);
        }

        treeNode* newTreeRoot = NULL;

        createNewTree(a, &newTreeRoot);         // Create new tree using elements of array 'a'
        printf("Preorder traversal of the new tree: \n");
        printPreOrder(newTreeRoot);

        deleteTree(&newTreeRoot);      // Delete second tree

        ****************************************/
      
        return 0;
}



// FUNCTION      : insertNode()
// DESCRIPTION   : This function creates a new node and inserts it to a given binary search tree
// PARAMETERS    :	
//		treeNode** ptrRoot  - Used to store address of root pointer
//		int value	 - Data/Key to be stored in the node
// RETURNS       : Nothing
void insertNode(treeNode** ptrRoot, int value){

treeNode *temp = NULL;
    if(!(*ptrRoot))
    {
        temp = (treeNode *)malloc(sizeof(treeNode)); //allocating a node
        temp->left = temp->right = NULL; //temp is assigned to NULL
        temp->Data = value; 
        *ptrRoot = temp; //assigning a ptr to temp
        return;
    }

    if(value < (*ptrRoot)->Data) //if the value is greater than the ptrRoot
    {
        insertNode(&(*ptrRoot)->left, value); //then its inserted in left
    }
    else if(value > (*ptrRoot)->Data) //if the value is less than the ptrRoot
    {
        insertNode(&(*ptrRoot)->right, value); //then its inserted in right
    } 
}



// FUNCTION      : printInOrder()
// DESCRIPTION   : This function prints out a given binary search tree in in-order traversal
// PARAMETERS    :	
//		treeNode* root  - Pointer to root of the binary search tree
// RETURNS       : Nothing
void printInOrder(treeNode* root){
if (root == NULL)
    return;
        printInOrder(root->left);
        printf("%d\n",root->Data); //prints the list 
        printInOrder(root->right);
    
}
// FUNCTION      : search()
// DESCRIPTION   : This function prints out a given binary search tree in in-order traversal
// RETURNS       : Nothing
void search (treeNode **root, int num, treeNode **par,treeNode **x, int *found)
{
    struct Node *q; //defining the node

    q = *root;
    *found = FALSE;
    *par = NULL;

    while (q!=NULL)
    {
        /* if the node to be deleted is found */
        if (q->Data==num)
        {
            *found = TRUE;
            *x = q; 
            return; //return nothing
        }

        *par = q; //assigning q to par

        if (q -> Data > num)
            q=q->left; 
        else
            q=q->right;
    }
}

// FUNCTION      : deleteNode()
// DESCRIPTION   : This function deletes a specific node in the tree given a specific key
// PARAMETERS    :	
//		treeNode** ptrRoot  - Used to store address of root pointer
//              int value        - Key of node to be deleted
// RETURNS       : Nothing
void deleteNode(treeNode** ptrRoot, int value){
	int found ; //local variable
    struct Node *parent, *x, *xsucc ;

    /* if tree is empty */
    if (*ptrRoot == NULL) //
    {
        printf("No Element Found");
        return; //return back
    }

    parent = x = NULL;

    /* call to search function to find the node to be deleted */
    search(ptrRoot, value, &parent, &x, &found);

    /* if the node to deleted is not found */
    if (found == FALSE)
    {
        return; //return back
    }

    /* if the node to be deleted has two children */
    if (x->left != NULL && x->right != NULL)
    {
        parent = x;
        xsucc = x->right;

        while ( xsucc -> left!= NULL)
        {
            parent = xsucc;
            xsucc = xsucc->left;
        }

        x -> Data = xsucc->Data;
        x = xsucc;
    }

    /* if the node to be deleted has no child */
    if ( x -> left == NULL && x -> right == NULL)
    {
        if ( parent -> right == x){
            parent -> right = NULL;
        }
        else{
            parent -> left = NULL;
        }

        free(x); //free the space in x
        return;
    }

    /* if the node to be deleted has only rightchild */
    if (x -> left== NULL && x -> right != NULL)
    {
        if (parent -> left == x){
            parent -> left = x -> right;
        }
        else{
            parent -> right = x -> right ;
        }

        free(x); //free the space in x
        return;
    }

    /* if the node to be deleted has only left child */
    if (x -> left != NULL && x -> right == NULL)
    {
        if (parent -> left == x){
            parent -> left = x -> left;
        }
        else{
            parent -> right = x -> left;
        }

        free(x); //free the space in x
        return;
    }
}





// FUNCTION      : postOrderCopy()
// DESCRIPTION   : This function copies the elements from a given binary search tree into
//                 the global array in post-order traversal.
// PARAMETERS    :	
//		treeNode* root   - Pointer to root of the binary search tree
// RETURNS       : Nothing
void postOrderCopy(treeNode* root) {
    

     
}



// FUNCTION      : scaleUpAndDeleteOdd()
// DESCRIPTION   : This function scales up the data field of all nodes in the tree by a factor passed to the function as an argument
//                 then deletes all the odd elements inside the array and returns the number of elements in the
//		   array after modification.                 
//                 This function should reject scale factor of 0.
// PARAMETERS    :	
//		int array[]     - Pointer to array to be scaled up
//              int scaleFactor - Scaling factor
// RETURNS       : Number of elements in the array after modification
int scaleUpAndDeleteOdd(int array[], int scaleFactor) {

        return 0;
}



// FUNCTION      : createNewTree()
// DESCRIPTION   : This function creates a new BST using the elements from the new modified array (maintaining the post-order traversal). 
// PARAMETERS    :	
//		int* array     - Pointer to array to retreive data of nodes for the new tree
//              treeNode** ptrRoot  - Used to store address of root pointer
// RETURNS       : Nothing
void createNewTree(int* array, treeNode** ptrRoot) {

}



// FUNCTION      : printPreOrder()
// DESCRIPTION   : This function prints out a given binary search tree in pre-order traversal
// PARAMETERS    :	
//		treeNode* root   - Pointer to root of the binary search tree
// RETURNS       : Nothing
void printPreOrder(treeNode* root) {

}



// FUNCTION      : treeHeight()
// DESCRIPTION   : This function finds and returns the height of a given binary search tree.
// PARAMETERS    :	
//		treeNode* root   - Pointer to root of the binary search tree
// RETURNS       : Height of tree
int treeHeight(treeNode* root){

}




// FUNCTION      : deleteTree()
// DESCRIPTION   : This function deletes all nodes for a given binary search tree
// PARAMETERS    :	
//		treeNode** ptrRoot   - Used to store address of root pointer
// RETURNS       : Nothing
void deleteTree(treeNode** ptrRoot) {
    if (*ptrRoot == NULL){ //if ptr is NULL return back
    return;
    }
    deleteTree(&(*ptrRoot)->left); 
    deleteTree(&(*ptrRoot)->right);
    printf("\n Deleting node: %d", (*ptrRoot)->Data); //to display the deleted node
    free(*ptrRoot); //to clear the ptr
    *ptrRoot = NULL; //ptr asssign to NULL
    return;
}
