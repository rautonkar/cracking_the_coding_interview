/******************************************************************************

1.1 Is Unique:
Implement an algorithm to determine if a string has all unique characters.
What if you cannot use additional data structures?

*******************************************************************************/

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

bool is_unique_simple(const char * str)
{
    size_t len = strlen(str);
    
    for(uint32_t itr = 0; itr < len - 1; itr++)
    {
        for (uint32_t itr2 = itr+1; itr2 < len; itr2++)
        {
            if (str[itr] == str[itr2])
            {
                return true;
            }
        }
    }
    
    return false;
    
}

int main()
{
    printf("%s\n", is_unique_simple("Taco") ? "True" : "False");
    printf("%s\n", is_unique_simple("caco") ? "True" : "False");
    printf("%s\n", is_unique_simple("stucco") ? "True" : "False");

    return 0;
}
