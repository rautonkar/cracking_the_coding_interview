/******************************************************************************

1.2 Check Permutation:
Given two strings, write a method to decide if one is a permutation of the 
other.

*******************************************************************************/

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

bool is_permutation(const char* str1, const char * str2)
{
    uint32_t str1_ascii_count[256];
    uint32_t str2_ascii_count[256];
    
    memset(str1_ascii_count, 0, sizeof(str1_ascii_count));
    memset(str2_ascii_count, 0, sizeof(str2_ascii_count));
    
    uint32_t str1_len = strlen(str1);
    uint32_t str2_len = strlen(str2);
    
    for(uint32_t itr = 0; itr < str1_len; itr++)
    {
        str1_ascii_count[(uint32_t)str1[itr]] += 1;
    }
    
    for(uint32_t itr = 0; itr < str2_len; itr++)
    {
        str2_ascii_count[(uint32_t)str2[itr]] += 1;
    }
    
    for(uint32_t itr = 0 ; itr < 256; itr++)
    {
#if 0
        printf("str[%02u] = %u; str[%02u] = %u\n", 
                        itr, str1_ascii_count[itr],
                        itr, str2_ascii_count[itr]);
#endif
        if (str1_ascii_count[itr] != str2_ascii_count[itr])
        {
            return false;
        }
    }
    
    return true;
}

int main()
{
    printf("%s\n", is_permutation("Taco", "caTo") ? "True" : "False");
    printf("%s\n", is_permutation("Tattoo", "taotTo") ? "True" : "False");
    printf("%s\n", is_permutation("Tattoo", "taptTo") ? "True" : "False");


    return 0;
}
