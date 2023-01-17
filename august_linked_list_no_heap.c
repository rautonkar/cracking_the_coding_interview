#include <stdio.h>

struct st_list
{
	unsigned long val;
	struct st_list * next;
};

typedef struct st_list list;

int insert_list_element(list * root, list * new)
{
    while(root->next != NULL && root->next->val <= new->val)
    {
        root = root->next;
    }
    
    new->next = root->next;
    root->next = new;
    
    return 0;
}

void print_list(list * root)
{
    while(root != NULL)
    {
        printf("%lu\r\n", root->val);
        root = root->next;
    }
}

int main()
{
    list A, B, C, D, E, F;
    
    A.val = 0;
    B.val = 1;
    C.val = 2;
    D.val = 3;
    E.val = 4;
    F.val = 5;
    
    A.next = NULL;
    B.next = NULL;
    C.next = NULL;
    D.next = NULL;
    E.next = NULL;
    F.next = NULL;
    
    print_list(&A);
    printf("---\r\n");
    
    insert_list_element(&A, &C);
    
    print_list(&A);
    printf("---\r\n");
    
    insert_list_element(&A, &D);
    
    print_list(&A);
    printf("---\r\n");
    
    insert_list_element(&A, &B);
    
    print_list(&A);
    printf("---\r\n");
    
    return 0;
}