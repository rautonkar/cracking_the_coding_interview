/******************************************************************************
2.1 Return Kth to last
Implement an algorithm to find kth to the last element of a singly linked list.
*******************************************************************************/
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

struct st_node
{
	unsigned long val;
	struct st_node * next;
};

typedef struct st_node node_t;

node_t * return_kth_to_last(node_t * p_root, const size_t kth)
{
    node_t * p_runner = p_root;
    uint32_t len_list = 0;
    
    for (node_t * p_runner = p_root; NULL != p_runner; p_runner = p_runner->next)
    {
        len_list++;
    }
    
    if((kth > (len_list - 1)) || (len_list == 0))
    {
        return NULL;
    }
    
    node_t * p_return = p_root;
    for(uint32_t skip_count = len_list - kth - 1; skip_count > 0; skip_count--)
    {
        p_return = p_return->next;
    }
    
    return p_return;
}

void print_nodes(node_t * p_runner)
{
    for( ;p_runner != NULL; p_runner = p_runner->next)
    {
        printf("%lu,", p_runner->val);
    }
    
    printf("\n");
}

int main(void)
{
    {
        node_t list[] = 
        {
            [0] = {
                .val = 1,
                .next = &list[1],
            },
            [1] = {
                .val = 2,
                .next = &list[2],
            },
            [2] = {
                .val = 3,
                .next = &list[3],
            },
            [3] = {
                .val = 4,
                .next = &list[4],
            },
            [4] = {
                .val = 5,
                .next = &list[5],
            },
            [5] = {
                .val = 6,
                .next = &list[6],
            },
            [6] = {
                .val = 7,
                .next = &list[7],
            },
            [7] = {
                .val = 8,
                .next = NULL,
            },
        };
        
        print_nodes (&list[0]);
        
        print_nodes (return_kth_to_last(&list[0], 0));
        
        print_nodes (return_kth_to_last(&list[1], 0));
        
        print_nodes (return_kth_to_last(&list[0], 1));
        
        print_nodes (return_kth_to_last(&list[1], 1));
        
        print_nodes (return_kth_to_last(&list[0], 7));
        
        print_nodes (return_kth_to_last(&list[1], 7));
    }
    
    return 0;
}

