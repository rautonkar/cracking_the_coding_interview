/******************************************************************************

1.7 Rotate Matrix:
Given an image represented by an N x N matrix where each pixel in the image is 
represented by an integer, write a method to rotate the image by 90 degrees. 
Can you do this in place?
*******************************************************************************/

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

void rotate_matrix(const uint32_t n, const uint32_t in[n][n], uint32_t out[n][n])
{
    uint32_t temp[n][n];
    
    for(uint32_t itr = 0; itr < n; itr++)
    {
        for(uint32_t itc = 0; itc < n; itc++)
        {
            temp[itr][itc] = in[itr][n - 1 - itc];
            
            printf("%u,",temp[itr][itc]);
        }
        printf("\n");
    }
    
    printf("\n");
    
    for(uint32_t itr = 0; itr < n; itr++)
    {
        for(uint32_t itc = 0; itc < n; itc++)
        {
            out[itr][itc] = temp[itc][itr];
            
            printf("%u,",out[itr][itc]);
        }
        printf("\n");
    }
    
    return;
}

void rotate_matrix_inplace(const uint32_t n, volatile uint32_t in[n][n])
{
    uint32_t temp[n][n];    
    
    for(uint32_t itr = 0; itr < n; itr++)
    {
        for(uint32_t itc = 0; itc < n; itc++)
        {
            temp[itr][itc] = in[itr][n - 1 - itc];
            
            printf("%u,",temp[itr][itc]);
        }
        printf("\n");
    }
    
    printf("\n");
    
    for(uint32_t itr = 0; itr < n; itr++)
    {
        for(uint32_t itc = 0; itc < n; itc++)
        {
            in[itr][itc] = temp[itc][itr];
            
            printf("%u,",in[itr][itc]);
        }
        printf("\n");
    }
    
    return;
}

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