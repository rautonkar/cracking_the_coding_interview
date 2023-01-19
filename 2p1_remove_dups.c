/******************************************************************************

2.1 Remove Dups:
Write code to remove duplicates from a linked list

FOLLOW duplicates

How would you solve this problem if a temporary buffer is not available

*******************************************************************************/

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

struct st_element
{
	unsigned long val;
	struct st_list * next;
};

int main(void)
{
    
    uint32_t in[3][3] = 
        {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9},
        };
        
        uint32_t out[3][3] = 
        {
            {3, 6, 9},
            {2, 5, 8},
            {1, 4, 7},
        };
    
    rotate_matrix(3, in, out);
    
    printf("---\n");
    
    rotate_matrix_inplace(3, in);
    
    return 0;
}