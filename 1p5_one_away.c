/******************************************************************************

1.5 One Away:
There are three types of edits that can be performed on strings: insert a 
character, remove a character, or replace a character. Given two strings, write 
a function to check if the are one edit (or zero edits) away

*******************************************************************************/

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

bool compare_string(const char * larger, size_t larger_len, 
                    const char * smaller, size_t smaller_len)
{
    bool found = false;
    for(uint32_t itr = 0; itr < smaller_len; itr++)
    {
        if(smaller[itr] == larger[itr])
        {
            found = true;
        }
        else if(smaller[itr] == larger[itr+1])
        {
            found = true;
        }
        else
        {
            found = false;
            break;
        }
    }
    
    return found;
}

bool is_one_away(char * str1, char * str2)
{
    uint32_t str1_len = strlen(str1);
    uint32_t str2_len = strlen(str2);
    
    const char * str_smaller = NULL;
    const char * str_larger  = NULL;
    uint32_t strlen_smaller = 0;
    uint32_t strlen_larger  = 0;
    
    if(str1_len < str2_len)
    {
        str_smaller = str1;
        strlen_smaller = str1_len;
        str_larger = str2;
        strlen_larger = str2_len;
    }
    else if (str1_len > str2_len)
    {
        str_smaller = str2;
        strlen_smaller = str2_len;
        str_larger = str1;
        strlen_larger = str1_len;
    }
    else
    {
        strlen_smaller = str1_len;
        strlen_larger = str1_len;
    }
    
    if((strlen_larger - strlen_smaller) > 1)
    {
        /* More than 1 edit away since two characters were added */
        return false;
    }
    else if ((strlen_larger - strlen_smaller) == 1)
    {
        /* One character extra in the larger string.
            All characters in the smaller string must be present. */
        
        return compare_string(str_larger, strlen_larger, 
                                str_smaller, strlen_smaller);
    }
    else
    {   
        uint32_t delta_count = 0;
        for(uint32_t itr = 0; itr < strlen_larger; itr++)
        {
            if(str1[itr] != str2[itr])
            {
                delta_count++;
            }
            
            if(delta_count > 1)
            {
                return false;
            }
        }
        
        return true;
    }
}

int main()
{
    printf("%s\n", is_one_away("pale","ple") ? "true":"false");
    printf("%s\n", is_one_away("pales","pale") ? "true":"false");
    printf("%s\n", is_one_away("pale","bale") ? "true":"false");
    printf("%s\n", is_one_away("pale","bake") ? "true":"false");

    return 0;
}
