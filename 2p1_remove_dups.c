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

struct st_node
{
	unsigned long val;
	struct st_node * next;
};

typedef struct st_node node_t;

void delete_next_node(node_t * p_node)
{
    p_node->next = p_node->next->next;
    
    return;
}


void delete_duplicates(node_t * p_root)
{
    for(node_t * p_runner = p_root; (p_runner != NULL) && (p_runner->next != NULL) ; p_runner = p_runner->next)
    {
        for(node_t * p_comp = p_runner; (p_comp != NULL) && (p_comp->next != NULL) ; p_comp = p_comp->next)
        {
            if(p_runner->val == p_comp->next->val)
            {
                delete_next_node(p_comp);
            }
        }
    }
    
    return;
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
        printf("\n");
        print_nodes (&list[0]);
        delete_duplicates(&list[0]);
        print_nodes (&list[0]);
    }
    
    {
        node_t list[] = 
        {
            [0] = {
                .val = 1,
                .next = &list[1],
            },
            [1] = {
                .val = 1,
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
        printf("\n");
        print_nodes (&list[0]);
        delete_duplicates(&list[0]);
        print_nodes (&list[0]);
    }
    
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
                .val = 7,
                .next = NULL,
            },
        };
        printf("\n");
        print_nodes (&list[0]);
        delete_duplicates(&list[0]);
        print_nodes (&list[0]);
    }
    
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
                .val = 4,
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
        printf("\n");
        print_nodes (&list[0]);
        delete_duplicates(&list[0]);
        print_nodes (&list[0]);
        
    }
    
    
    return 0;
}

