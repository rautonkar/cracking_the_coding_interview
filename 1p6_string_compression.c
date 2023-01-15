/******************************************************************************

1.6 String Compression:
Implement a method to perform basic string compression using the counts of 
repeated characters. For example, the string aabcccccaaa would become a2b1c5a3.
If the "compressed" string would not become smaller than the original string, 
your method should return the original string. You can assume the string has 
only uppwercase and lowercase letters (a-z)


*******************************************************************************/

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

uint32_t count_char(const char * str_in, const size_t len_str_in)
{
    uint32_t repeated = 1;

    for(uint32_t itr = 0; itr < len_str_in; itr++)
    {
        if(str_in[itr] == str_in[itr+1])
        {
            repeated += 1;
        }
        else
        {
            break;
        }
    }

    return repeated;
}

char * compress_string(const char * str_in, const size_t len_str_in, 
                             char * str_out, const size_t len_str_out)
{
    char * result = NULL;
    char compressed_str[len_str_in*2];
    uint32_t char_count = 0;
    
    memset(compressed_str, 0, sizeof(compressed_str));
    
    for ( uint32_t itr = 0, out_adder; (itr < len_str_in) && (str_in[itr] != '\0'); )
    {
        uint32_t rc = count_char(&str_in[itr], len_str_in);
#if 0
        printf("%c", str_in[itr]);
        printf("%d\n", rc);
#endif
        out_adder += sprintf(&compressed_str[out_adder],"%c%d",str_in[itr], rc);
        
        itr += rc;
    }
    
    if(len_str_in < strlen(compressed_str))
    {
        result = (char *) str_in;
    }
    else
    {
        memset(str_out, 0, strlen(compressed_str)+1);
        memcpy(str_out, compressed_str, strlen(compressed_str));
        result = str_out;
    }

    return result;
}


int main()
{
    
    char * test = "aabcccccaaa";
    size_t len  = strlen(test);
    char output[256];
    
    
    printf("%s\n", compress_string(test, strlen("aabcccccaaa"),
                    &output[0], sizeof(output)));
    
    return 0;
}
