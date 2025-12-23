#include<stdio.h>

typedef struct node
{
    node *next;
    int val;
}node;

node *wywal(node *root){
    node *tmp = root, *a;
    if(tmp->val % 2 == 0)
        a = tmp;
    while(tmp->next->next != NULL){
        if(a->next->val % 2 == 0)
            a = tmp;
        tmp = tmp->next;
    }
    tmp = a->next;
    a->next = tmp->next;
    free(tmp);
}
