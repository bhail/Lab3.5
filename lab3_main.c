/** lab3_main.c: Implements a front end for lab3_lib.c.
*
*
* Name:Ben Hail
* Email: bhail@purdue.edu
* Course: CNIT 315
* Lab batch:9:30am
* Lab assignment: 3
* Date:3/3/15
*last modified 2-27-15
* Collaborators: Ben Gregory
*
*/


#include <stdio.h>
#include "lab3_lib.h"
#include <stdlib.h>

/**
 * Using a dynamic array asking for input from the user to apply the searches
 sorts.
 *
 * 	@return 	0 - Successful completion of the program.
 * 				1 - An error during execution.
 */
 

 

 
int main()
{
	int response = 1;
	int menuChoice;
	int arraySize = 0;
	
	/* Initialize */
	int *chunky, *tempMemory;
	
	chunky=malloc(sizeof(int));
			
	
	while (response = 1)
	  {
	  
	  /* Menu */
        printf("Choose a function: 1 Add a new value, 2 Sort array,"
        "3 Search the array");
        scanf("%d", &menuChoice);
    
        if (menuChoice == 1)
        {
          printf("Please enter a value.");
          int value1;
          scanf("%d", &value1);
          chunky[arraySize] = value1;
          tempMemory=realloc(chunky, (arraySize + 2)*sizeof(int));
          
          if (tempMemory != NULL)
            {
              chunky = tempMemory;
              
            }
          else
            {
              free(chunky);
             
            }
         arraySize ++;
         
        }
        else if (menuChoice == 2)
          {
            
            int arraySorted[arraySize], i;
            bubble_sort(chunky, arraySize, arraySorted);
            
            for (i=0; i < arraySize; i++)
              {
              
                printf("These are the numbers:\n");
                printf("\n%d", arraySorted[i]);
              
              }
            
          }
        else if (menuChoice == 3)
        {
          int arraySorted[arraySize];
          int value3, locationIndex;
          printf("Please enter a value:\n");
          scanf("%d", &value3);
          bubble_sort(chunky, arraySize, arraySorted);
          binary_search(arraySorted, arraySize, value3, &locationIndex);
          
           if (locationIndex == -1)
            {
              printf("The number was not found in the array.");
              
            } 
           else if (locationIndex != -1)
            {
              printf("Number was found at index %d", locationIndex);
              
            }
           
        }
          
			printf("Do you wish to run this computation again? Press 1 for Yes and"
				" 2 for No \n");
			scanf("%d", &response);

			if (response == 1)
				{
					response = 1;
		
				}
			else if(response != 1)
				{

					response = 2;
					break;
				}
	  }	    
	//Your code goes here!

	/* Wrap up */

	return 0;
}
