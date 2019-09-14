/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>
#include <string.h>
#include <stdio.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // TODO: implement a searching algorithm
    /* liner search
    
    if ( value < 0 )
    {
        return false;
    }
    else
    {
        for(int i = 0; i < n; i++)
            if ( values[i] == value )
                return true;
        
        return false;
    }
    */
    
    // binary search
    if ( value < 0 )
        return false;
    
    else
    {
        int min = 0;
        int max = n - 1;
        
        while (n > 0)
        {
            int midpoint = ( min + max )/2;
            
            //search left
            if ( values[midpoint] > value )
                max = midpoint - 1;
            
            //search right
            else if ( values[midpoint] < value )
                min = midpoint + 1;
                
            //check middle
            else
                return true;
                
            n = max - min + 1;
        }
        
        return false;
    
    }
}



/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement an O(n^2) sorting algorithm
    // bubble sort
    for( int i = 0 ; i < n - 1 ; i++ )
    {
        int swaped = 0;
        int sorted = n; 
        
        for( int j = 0 ; j < (sorted - 1) ; j++)
        {
            if ( values[j] > values[j+1] )
            {
                int num = values[j];
                values[j] = values[j+1];
                values[j+1] = num;
                swaped += 1;
            }
        }
        if ( swaped <= 0 )
        break;
        
    sorted-=1; 
        
    }
    /*
    for( int i = 0 ; i < n ; i++)
    printf("%i", values[i]);
    */
    return;
} 