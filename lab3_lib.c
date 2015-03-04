/** lab3_lib.c: implements sorting and searching functions.
*
*
* Name:Ben Hail
* Email: bhail@purdue.edu
* Course: CNIT 315
* Lab batch: Lab 03
* Lab assignment: 3
* Date: 2/26/15
*/
/*Collaborators:
*
*/

#include <stdio.h>
#include <string.h> //for memcpy

#include "lab3_lib.h"

/*
 * Pro-tip: use this function to copy arrays.
 */
void deep_copy_array(int* array_from, int* array_to, int array_length){
	//Read more about memcpy over here: http://www.cplusplus.com/reference/cstring/memcpy/
	memcpy(array_from, array_to, array_length*sizeof(int));
}

/*
 * Pro-tip:use this function to generate random arrays.
 */
int generate_random_int_array(int* array, int array_length){
	/* Initialize */
	int i;
	/* Validate input */
	if(!array){
		printf("Error: Input array was NULL\n");
		return 1;
	}
	if(array_length < 1){
		printf("Error: required array size < 1\n");
		return 1;
	}
	/* Generate random values */
	for (i = 0; i < array_length; i++) {
		array[i] = rand();
	}
	return 0;
}


int bubble_sort(int* array_unsorted, int array_length, int* array_sorted){
	/* Initialize */

	//Put your variable declarations here.
    
    int   c, d, swap;
    
    
	/* Validate input */
	if(!array_unsorted){
		printf("Error: Unsorted array was NULL\n");
		return 1;
	}
	if(array_length < 1){
		printf("Error: unsorted array size < 1\n");
		return 1;
	}
	if(array_sorted == NULL){
		printf("Error: sorted array is NULL\n");
		return 1;
	}
	/* Sort array */
    deep_copy_array (array_sorted, array_unsorted, array_length);

        for (c = 0 ; c < ( array_length - 1 ); c++)
    {
        for (d = 0 ; d < array_length - c - 1; d++)
        {
            if (array_sorted[d] > array_sorted[d+1]) /* For decreasing order use < */
            {
                swap       = array_sorted[d];
                array_sorted[d]   = array_sorted[d+1];
                array_sorted[d+1] = swap;
            }
        }
    }
    
	//I can has code?

	return 0; //Change me!
}


int selection_sort(int* array_unsorted, int array_length, int* array_sorted){
	/* Initialize */

	//Put your variable declarations here.
    int c, d, position, swap;

	/* Validate input */
	if(!array_unsorted){
		printf("Error: Unsorted array was NULL\n");
		return 1;
	}
	if(array_length < 1){
		printf("Error: unsorted array size < 1\n");
		return 1;
	}
	if(array_sorted == NULL){
		printf("Error: sorted array is NULL\n");
		return 1;
	}
	/* Sort array */

	//Let the code-pocalypse begin!

    deep_copy_array (array_sorted, array_unsorted, array_length);
    
    for ( c = 0 ; c < ( array_length - 1 ) ; c++ )
    {
        position = c;
        
        for ( d = c + 1 ; d < array_length ; d++ )
        {
            if ( array_sorted[position] > array_sorted[d] )
                position = d;
        }
        if ( position != c )
        {
            swap = array_sorted[c];
            array_sorted[c] = array_sorted[position];
            array_sorted[position] = swap;
        }
    }
    
	return 0; //Change me!
}

int insertion_sort(int* array_unsorted, int array_length, int* array_sorted){
	/* Initialize */

	//Put your variable declarations here.
    
    int c, d, t;

	/* Validate input */
	if(!array_unsorted){
		printf("Error: Unsorted array was NULL\n");
		return 1;
	}
	if(array_length < 1){
		printf("Error: unsorted array size < 1\n");
		return 1;
	}
	if(array_sorted == NULL){
		printf("Error: sorted array is NULL\n");
		return 1;
	}
	/* Sort array */

	//Round 4: CODE!
    
    deep_copy_array (array_sorted, array_unsorted, array_length);
    
    for (c = 1 ; c <= array_length - 1; c++) {
        d = c;
        
        while ( d > 0 && array_sorted[d] < array_sorted[d-1]) {
            t          = array_sorted[d];
            array_sorted[d]   = array_sorted[d-1];
            array_sorted[d-1] = t;
            
            d--;
        }
    }

	return 0; //Change me!
}

int linear_search(int* array, int array_length, int value, int* location){
	/* Initialize */

	//Put your variable declarations here.
    
    int c;

	/* Validate input */
	if(!array){
		printf("Error: array pointer is NULL\n");
		return 1;
	}
	if(array_length < 1){
		printf("Error: array size < 1\n");
		return 1;
	}
	if(!location){
		printf("Error: location variable is NULL\n");
		return 1;
	}
	/* Search array */

	//All of your code-base are belong to us.
    
    
    for (c = 0; c < array_length; c++)
    {
        if (array[c] == value)     /* if required element found */
        {
            *location = c;
            break;
        }
    }
    if (c == array_length)
    {
     
        *location = -1;
        return 0;
        
    }
	return 0; //Change me!
}

/*
 * You will have to implement this entire function! Remember to check for
 * input errors like the other functions.
 */
int binary_search(int* array, int array_length, int value, int* location){

    int first, last, middle, foundCheck = 0;
    
    if(!array){
		printf("Error: array pointer is NULL\n");
		return 1;
	}
	if(array_length < 1){
		printf("Error: array size < 1\n");
		return 1;
	}
	if(!location){
		printf("Error: location variable is NULL\n");
		return 1;
	}

    
	//The cake is a lie.
    
    
    first = 0;
    last = array_length - 1;
    middle = (first+last)/2;
    
    while( first <= last )
    {
        if ( array[middle] < value )
            first = middle + 1;    
        else if ( array[middle] == value ) 
        {
            *location = middle;
            foundCheck = 7;
            break;
        }
        
       else if ( first > last )
        {
            *location = -1;
            return 1;
            
            
        }

        
        else
        {
            last = middle - 1;
        }
        
        middle = (first + last)/2;
    }
     
    if (foundCheck == 0)   
      {
        *location = -1;
        return 1;
      }
    
    
    	return 0;
}
