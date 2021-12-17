
/*******************************************************************************************
 * File Name	: Lab4.c
 * Author	: Shamseddin Elmasri
 * Date		: Apr 17, 2021
 * Description	: This file is the skeleton for Lab 4 (Hashing).

 * Instructions	:
 *			1) Complete the state machine as indicated in the comments inside
 *                         each state.
 *                      2) Create your own hash function to find the hash value for each
 *                         input (You may use the example provided in the lecture slides
 *                         as a starting point, however, your hash function must be
 *                         different)
 *                      3) For advanced outcomes, create another state machine inside 
 *                         FINISH_STATE to enable the user of restarting the program             
 *
 * Student Name: SAI TEJA ANAPARTHY
 * Student Number:8696855
 * Reference: https://stackoverflow.com/questions/7666509/hash-function-for-string
 * Lab-2
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

uint32_t hashFunction(unsigned char *ptrInputBuffer);


int main(){

	enum StateMachine{

		START_STATE,
		INITIALIZATION_STATE,
		WAIT_FOR_INPUT_STATE,
		GET_HASH_STATE,
		FINISH_STATE,

	}
	STATE = START_STATE;

	uint32_t counter;
	char inputString[20];
	char exitMessage[5] = "EXIT";
	uint32_t hashValue;

	while(1){

		switch(STATE){

			case START_STATE:

				printf("Program started!\n");

				STATE = INITIALIZATION_STATE;

				break;

			case INITIALIZATION_STATE:
	
				counter = 0; //reset the counter
			
				
			STATE = WAIT_FOR_INPUT_STATE; //next state for input
			        
				break;

			case WAIT_FOR_INPUT_STATE:
            
				printf("Enter the Valid String:");
				scanf("%s", inputString); //taking the input string

				if ((strcmp(inputString,"exit") == 0) || (strcmp(inputString,"EXIT") == 0)) //we are comparing the two strings
				{
					STATE = FINISH_STATE; //if they use exit we go it exit directly!
				}
                else if((inputString[0] == '0'||inputString[0] == '1'||inputString[0] == '2'||inputString[0] == '3'||inputString[0] == '4'||inputString[0] == '5'||inputString[0] == '6'||inputString[0] == '7'||inputString[0] == '8'||inputString[0] == '9'||inputString[0] == '%'||inputString[0] == '#'||inputString[0] == '@'||inputString[0] == '$'||inputString[0] == '^'))
				{
				    printf("Invalid String\n");
				}
				else
				{
					counter++; //increasing the counter
					STATE = GET_HASH_STATE;
				}
				break;

			case GET_HASH_STATE:

				hashFunction(inputString); //implementing the hash algorithum to input string
                printf("Hashed value: %x \n",hashFunction(inputString)); //

                        STATE = WAIT_FOR_INPUT_STATE; //move to required state
                break;

           	case FINISH_STATE:

           	
           		printf("The Program has ended. \n "); 
                printf("The previously entered number of valid strings: %d \n ",counter); //valid strings
                printf(" Type 'Restart or restart' to restart the Program. \n ");
           		scanf("%s", inputString); //taking the input
           		if ((strcmp(inputString, "restart") == 0) ||(strcmp(inputString, "Restart") == 0 )) //string compairsion
           		{
           		    printf("\033[2J");      // Clear screen
                    printf("\033[0;0H");    // Reset cursor
           		    STATE = START_STATE; //first state
           		    
           		}
           		else
                {
                
                    printf("Wrong input for restarting of program \n ");
                    
                }	
           		break;

           	default:
                 
           		STATE = START_STATE; //to go back to starting of FSM 
           		
           		break;
		}
	}
	return 0;

}

uint32_t hashFunction(unsigned char *ptrInputBuffer)
{
    uint32_t calculatedHashValue = 0;
    
for (calculatedHashValue = 0; *ptrInputBuffer != '\0'; ptrInputBuffer++)
        calculatedHashValue= *ptrInputBuffer + 31*calculatedHashValue;
    return calculatedHashValue;
}