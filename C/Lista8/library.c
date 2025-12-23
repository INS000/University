#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
#include<string.h>
#include"library.h"

node *new_node(int val){
    node *temp = (node *)malloc(sizeof(node));
    temp->val = val;
    temp->left = temp->right = NULL;
    return temp;
}

node *add_node(node *wood, int val){
    if(wood == NULL)
        return new_node(val);
    if(val < wood->val)
        wood->left = add_node(wood->left, val);
    else
        wood->right = add_node(wood->right, val);
    return wood; //nigdy sie nie wykona
}

node *del_node(node *wood, int val){
    if(wood == NULL)
        return wood;
    if(val > wood->val)
        wood->right = del_node(wood->right, val);
    else if(val < wood->val)
        wood->left = del_node(wood->left, val);
    else{
        if(wood->left == NULL){
            node *new_wood = wood->right;
            free(wood);
            return new_wood;
        }
        else if(wood->right == NULL){
            node *new_wood = wood->left;
            free(wood);
            return new_wood;
        }
        else{
            node *new_wood = wood->right;
            while(new_wood->left != NULL)
                new_wood = new_wood->left;
            wood->val = new_wood->val;
            wood->right= del_node(wood->right, new_wood->val);
            
        }
    }
    return wood;
}


void free_tree(node *wood){
    if(wood->left != NULL)
        free_tree(wood->left);
    if(wood->right != NULL)
        free_tree(wood->right);
    free(wood);
}

int min(node *wood){
    node *tmp = wood;
    while(tmp->left != NULL)
        tmp = tmp->left;
    return tmp->val;
}

int max(node *wood){
    node *tmp = wood;
    while(tmp->right != NULL)
        tmp = tmp->right;
    return tmp->val;
}

bool contain_val(node* wood, int val){
    if(wood == NULL)
        return 0;
    if(wood->val == val)
        return 1;
    if(wood->val < val)
        return contain_val(wood->right, val);   
    return contain_val(wood->left, val);
}

void next_val(node *wood, int val, int *wyn){
    if(wood->val > val && wood->val < *wyn)
        *wyn = wood->val;
    if(wood->right != NULL)
        next_val(wood->right, val, wyn);
    if(wood->left != NULL)
        next_val(wood->left, val, wyn);
}

void prev_val(node *wood, int val, int *wyn){
    if(wood->val < val && wood->val > *wyn)
        *wyn = wood->val;
    if(wood->right != NULL)
        prev_val(wood->right, val, wyn);
    if(wood->left != NULL)
        prev_val(wood->left, val, wyn);
}

void write(node *wood, int x){
    if(wood->right != NULL)
        write(wood->right, x + 1);
    for(int i = 0; i < x; i++){
        printf("    ");
    }
    printf("%d\n", wood->val);
    if(wood->left != NULL)
        write(wood->left, x + 1);
}

void solve(node *tree){
    int x;
    char s[6];
    int tmp;
    while(true){
        scanf("%s", &s);
        if(strcmp(s, "ins")== 0){
            scanf("%d", &x);
            if(contain_val(tree, x)){
                fprintf(stderr, "Ta wartosc juz wystapila w drzewie\n");
            }
            else{
                tree = add_node(tree, x);
            }
        }
        else if(!strcmp(s, "del")){
            scanf("%d", &x);
            if(!contain_val(tree, x)){
                fprintf(stderr, "Ta wartosc nie wystapile w drzewie\n");
            }
            else{
                tree = del_node(tree, x);
            }
        }
        else if(!strcmp(s, "srch")){
            scanf("%d", &x);
            if(contain_val(tree, x))
                printf("TAK\n");
            else
                printf("NIE\n");
        }
        else if(!strcmp(s, "min")){
            if(tree == NULL){
                fprintf(stderr, "Drzewo jest puste\n");
            }
            else{
                printf("%d\n", min(tree));
            }
            
        }
        else if(!strcmp(s, "max")){
            if(tree == NULL){
                fprintf(stderr, "Drzewo jest puste\n");
            }
            else{
                printf("%d\n", max(tree));
            }  
        }
        else if(!strcmp(s, "prev")){
            scanf("%d", &x);
            if(tree == NULL){
                fprintf(stderr, "Drzewo jest puste\n");
            }
            else if(min(tree) >= x){
                fprintf(stderr, "Podana wartosc to conajwyzej wartosc minimalna\n");
            }
            else{
                tmp = INT_MIN;
                prev_val(tree, x, &tmp);
                printf("%d\n", tmp);
            }
        }
        else if(!strcmp(s, "next")){
            scanf("%d", &x);
            if(tree == NULL){
                fprintf(stderr, "Drzewo jest puste\n");
            }
            else if(max(tree) <= x){
                fprintf(stderr, "Podana wartosc to conajmniej wartosc maksymalna\n");
            }
            else{
                tmp = INT_MAX;
                next_val(tree, x, &tmp);
                printf("%d\n", tmp);
            }
        }
        else if(!strcmp(s, "print")){
            write(tree, 0);
            // printf("\n");
        }
        else if(!strcmp(s, "quit")){
            free_tree(tree);
            break;
        }
        else {
            fprintf(stderr, "Podales zla komende\n");
        }
    }
}


/*poprzednia wersja dela jako funfact

void del_node(node *wood, node *elderwood, int val){
    if(val > wood->right->val && wood->right != NULL)
        del_node(wood->right, wood, val);
    else if(val < wood->val && wood->left != NULL)
        del_node(wood->left, wood, val);
    else{
        if(wood->val != val)
            return;

        if(wood->left != NULL){
            node *max = wood->left;
            node *max_child = max->right;
            if(max_child == NULL){
                max->right = wood->right;
                if(elderwood->val < wood->val)
                    elderwood->right = max;
                else
                    elderwood->left = max;
            }
            else{
                while(max_child->right != NULL){
                    max = max_child;
                    max_child = max_child->right;
                }
                max->right = max_child->left;
                max_child->left = wood->left;
                if(elderwood->val < wood->val)
                    elderwood->right = max_child;
                else
                    elderwood->left = max_child;
            }
        }
        else{
            node *max = wood->right;
            node *max_child = max->left;
            if(max_child == NULL){
                max->left = wood->left;
                if(elderwood->val < wood->val)
                    elderwood->right = max;
                else
                    elderwood->left = max;
            }
            else{
                while(max_child->left != NULL){
                    max = max_child;
                    max_child = max_child->left;
                }
                max->left = max_child->right;
                max_child->right = wood->right;
                if(elderwood->val < wood->val)
                    elderwood->right = max_child;
                else
                    elderwood->left = max_child;
            }
        }    
    }
    free(wood);
}*/