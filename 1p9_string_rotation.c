/******************************************************************************

1.9 String Rotation: (Used hint)
Assume you have a method isSubstring which checks if one word is a substring 
of another. GIven two strings s1 and s2, write code to check if s2 is a 
rotation of s1 using only one call to isSubstring. (e.g., "waterbottle" is 
a rotation of "erbottlewat").

*******************************************************************************/

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

bool isSubstring(char * haystack, char * needle)
{
    if(NULL==strstr(haystack, needle))
    {
        return false;
    }
    
    return true;
}

bool is_rotation(const uint32_t len_s1, const uint32_t len_s2,
                    char * s1, char * s2 )
{
    char x2s1[len_s1*2];
    
    memset(x2s1, 0, sizeof(x2s1));
    
    sprintf(x2s1, "%s%s", s1, s1);
    
    return isSubstring(x2s1, s2);
}

int main(void)
{
    printf("%s", is_rotation(strlen("erbottlewat"), strlen("waterbottle"), 
    "erbottlewat","waterbottle") ? "true":"false");
    return 0;
}