/******************************************************************************

1.3 URLify:
Write a method to replace all spaces in a string with '%20'. You may assume 
that the string has sufficient space at the end to hold the additional 
characters, and that you are given the 'true' length of the string. 
(Note: If implementing in Java, please use a character array so that you can 
perform this operation in place.)
*******************************************************************************/

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

void URLify(char * str, size_t true_len)
{
    for (uint32_t itr = 0 ; itr < true_len; itr++)
    {
        if(' ' == str[itr])
        {
            memcpy(&str[itr+3], &str[itr+1], true_len - itr);
            str[itr+0] = '%';
            str[itr+1] = '2';
            str[itr+2] = '0';
            itr+=2;
            true_len +=2;
        }
    }
}

int main()
{
    {
    char url[] = "Mr John Smith      ";
    URLify(url, 13);
    printf("%s\n", url);
    }
    
    {
    char url[] = "Mr John Smith Doeke         ";
    URLify(url, 19);
    printf("%s\n", url);
    }
    return 0;
}
