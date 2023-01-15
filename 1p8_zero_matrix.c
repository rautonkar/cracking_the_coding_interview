/******************************************************************************

1.8 Zero Matrix:
Write an algorithm such that if an element in an M x N matrix is zero, it's 
entire row and column are set to zero.

*******************************************************************************/

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

void zero_matrix(const uint32_t r, const uint32_t c, uint32_t in[][c], uint32_t out[][c])
{
    bool zero_row[r];
    bool zero_col[c];
    
    memset(zero_row, 0, sizeof(zero_row));
    memset(zero_col, 0, sizeof(zero_col));
    
    for(uint32_t itr = 0; itr < r; itr++ )
    {
        for(uint32_t itc = 0; itc < c; itc++)
        {
            if (in[itr][itc] == 0)
            {
                zero_row[itr] = true;
                zero_col[itc] = true;
            }
        }
    }
    
    for(uint32_t itr = 0; itr < r; itr++ )
    {
        for(uint32_t itc = 0; itc < c; itc++)
        {
            if((zero_row[itr] == true) || (zero_col[itc] == true))
            {
                out[itr][itc] = 0;
            }
            else
            {
                out[itr][itc] = in[itr][itc];
            }
            printf("%u,", out[itr][itc]);
        }
        
        printf("\n");
    }
    
    printf("\n");
    
    return;
}

int main()
{
    {
        uint32_t in[3][3] = 
        {
            {1, 2, 3},
            {1, 2, 3},
            {1, 2, 3},
        };
        
        uint32_t out[3][3] = 
        {
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0},
        };
    
        zero_matrix(3, 3, in, out);
    }
    
    {
        uint32_t in[3][3] = 
        {
            {1, 2, 3},
            {1, 0, 3},
            {1, 2, 3},
        };
        
        uint32_t out[3][3] = 
        {
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0},
        };
        
        zero_matrix(3, 3, in, out);
    }
    
    {
        uint32_t in[3][3] = 
        {
            {0, 2, 3},
            {1, 2, 3},
            {1, 2, 3},
        };
        
        uint32_t out[3][3] = 
        {
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0},
        };
        
        zero_matrix(3, 3, in, out);
    }
    
    {
        uint32_t in[3][3] = 
        {
            {1, 2, 3},
            {1, 2, 3},
            {1, 2, 0},
        };
        
        uint32_t out[3][3] = 
        {
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0},
        };
        
        zero_matrix(3, 3, in, out);
    }
    
    {
        uint32_t in[3][3] = 
        {
            {1, 2, 0},
            {1, 2, 3},
            {1, 2, 3},
        };
        
        uint32_t out[3][3] = 
        {
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0},
        };
        
        zero_matrix(3, 3, in, out);
    }
    
    {
        uint32_t in[3][3] = 
        {
            {1, 2, 0},
            {1, 2, 3},
            {1, 2, 0},
        };
        
        uint32_t out[3][3] = 
        {
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0},
        };
        
        zero_matrix(3, 3, in, out);
    }
    
    {
        uint32_t in[4][3] = 
        {
            {1, 2, 3},
            {1, 2, 3},
            {1, 2, 3},
            {1, 0, 3},
        };
        
        uint32_t out[4][3] = 
        {
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0},
        };
        
        zero_matrix(4, 3, in, out);
    }

    return 0;
}