/*******************************************************************************************
 * File Name	: FinalExamPart2.c
 * Author	: Shamseddin Elmasri
 * Date		: Apr 24, 2021
 * Description	: This file is the skeleton for Final Exam (part 2).

 * Instructions	:
 *			1) Complete the state machine as indicated in the comments inside
 *                         each state.
 *                      2) Complete the functions for pushing to the stack and poping from 
 *                         the stack without modifying the function declaration
 *
 * Student Name: SAI TEJA ANAPARTHY
 * Student Number: 8696855
 *Reference: https://codeforwin.org/2018/07/stack-implementation-using-array.html
 * I have used this code for first file and I have changed it second code
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h> 
#include <string.h>


void pushToStack(char* ptrInputBuffer);
char popFromStack(void);

uint8_t stackIndex;
char stack[100];
int top = -1;

int main()
{
        enum StateMachine
        {
                START_STATE,
                INITIALIZATION_STATE,
                WAIT_FOR_COMMAND_TYPE_STATE,
                WAIT_FOR_INPUT_STATE,
                PUSH_TO_STACK_STATE,
                POP_FROM_STACK_STATE,
                FINISH_STATE

        }State = START_STATE;


        char inputString[20];                   // Stores the user's input string

        
        while (1)
        {
                switch (State)
                {
                case START_STATE:

                        printf("Program started!\n");

                        State = INITIALIZATION_STATE;

                        break;


                case INITIALIZATION_STATE:

                        stackIndex == 0;
                     
                        break;


                case WAIT_FOR_COMMAND_TYPE_STATE:

                 printf("Enter the Valid value:");
		       scanf("%i", inputString); //taking the input string // User enters the command type from the terminal
                if ((inputString[0] == '0'))
				{ //we are comparing the two strings
				
					State = FINISH_STATE; //if they use exit we go it exit directly!
				}
                else if((inputString[0] == '1'))
				{
				
				    State = WAIT_FOR_INPUT_STATE;
				}
	        else if((inputString[0] == '2'))
				{
				
					
					State = POP_FROM_STACK_STATE;
				}
				break;
                        // 0 go to FINISH_STATE
                        // 1 go to WAIT_FOR_INPUT_STATE
                        // 2 go to POP_FROM_STACK_STATE
                        // Program should neglect any other input

                        break;


                case WAIT_FOR_INPUT_STATE:
                
                       printf("Enter the Value:");
		       scanf("%i", inputString);
                       
				
				State = PUSH_TO_STACK_STATE; //if they use exit we go it exit directly!
				// User enters the input string from terminal
                        // Go to PUSH_TO_STACK_STATE

                        break;


                case PUSH_TO_STACK_STATE:

                     popFromStack(); // Call the pushToStack function
            
                 State = WAIT_FOR_COMMAND_TYPE_STATE;// Check for overflow condition
                        // Go to WAIT_FOR_COMMAND_TYPE_STATE

                        break;


                case POP_FROM_STACK_STATE:

                        popFromStack();// Call popFromStack function
                        printf("pop value from stack: %d \n",popFromStack);// Display the item popped 
                
                 if(stack == 0)
                 {
                         State = WAIT_FOR_COMMAND_TYPE_STATE;
                 }
                 else
                 {
                         State = POP_FROM_STACK_STATE;
                 }
                        // If stack is empty go back to WAIT_FOR_COMMAND_TYPE_STATE
                        // Else stay in this state
                
                        break;


                case FINISH_STATE:
                        printf("Program exit"); 
                         printf("Data pushed to stack: %c ",stack);       
                         // Display what's inside the stack
                        State = 8;// Exit the program

                        break;


                default:

                        State = START_STATE;

                        break;
                }
        }

        return 0;
}



// FUNCTION      : pushToStack()
// DESCRIPTION   : This function receives a string and pushes it to the stack
// PARAMETERS    :	
//		   char* ptrInputBuffer: Pointer to input string
//
// RETURNS       : Nothing
void pushToStack(char* ptrInputBuffer)
{

   if (stackIndex < 100) {
                stack[stackIndex++] = *ptrInputBuffer; //increase the stack
   }
        else {
                printf("Error, stack over flow\n");
}  

}



// FUNCTION      : popFromStack()
// DESCRIPTION   : This function pops the top of the stack
// PARAMETERS    : Nothing
// RETURNS       : Top of the stack
char popFromStack(void)
{
        if (stackIndex > 0) {
                return stack[--stackIndex]; //decrease the pop
        }
        else {
            printf("Error, stack over flow\n");
}

}


