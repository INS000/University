#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include "lib.h"

#define N ('z' - 'a' + 1)


node *new_node(){
    node *tmp = (node *)malloc(sizeof(node));
    for(int i = 0; i < N; i++){
        tmp->child[i] = NULL;
    }
    tmp->counter = 0;
    return tmp;
}

void conv(char *a){
    if(*a >= 'A' && *a <= 'Z')
        *a = *a - 'A' + 'a';        
}

void new_word(node *root, char *word, int *maxsize){
    node *tmp = root;
    if(*maxsize < strlen(word))
        *maxsize = strlen(word);
    for(int i = 0; word[i] !='\0'; i++){
        char c = word[i];
        conv(&c);
        if(c > 'z' || c < 'a'){
            fprintf(stderr, "Znak %c jest nielegalny, slowo z tym znakiem nie zostalo dodane\n", c);
            return;
        }
        if(tmp->child[c - 'a'] == NULL)
            tmp->child[c - 'a'] = new_node();
        tmp = tmp->child[c - 'a'];
    }
    tmp->counter = tmp->counter + 1;
}

unsigned int search(node *root, char *word){
    node *tmp = root; 
    for(int i = 0; word[i] != '\0'; i++){
        conv(&word[i]);
        if(tmp->child[word[i] - 'a'] == NULL)
            return 0;
        tmp = tmp->child[word[i] - 'a'];
    }
    return tmp -> counter;
}

void free_tree(node *root){
    for(int i = 0; i < N; i++){
        if(root->child[i] != NULL){
            free_tree(root->child[i]);
        }
    }
    free(root);
}

void dispal(node *root, char word[], int level){
    if(root->counter > 0){
        for(int i = 0; i < level; i++){
            printf("%c", word[i]);
        }
        printf(" %u\n", root->counter);
    }
    for(int i = 0; i < N; i++){
        if(root->child[i] != NULL){
            word[level] = 'a' + i;
            dispal(root->child[i], word, level + 1);
        }
    }
}

void fdisp(node *root, int maxsize){
    char word[maxsize];
    dispal(root, word, 0);
}

bool ifleg(char sl[]){
    char c;
    for(int i = 0; i < strlen(sl); i++){
        c = sl[i];
        conv(&c);
        if(c >'z' || c < 'a'){
            return false;
        }
    }
    return true;
}

void interface(node *root, int maxsize){
    char s[10];
    char sl[190000];
    while(true){
        scanf("%s", &s);
        if(!strcmp(s, "quit")){
            free_tree(root);
            break;
        }
        else if(!strcmp(s, "list")){
            fdisp(root, maxsize);
            printf("\n");
        }
        else if(!strcmp(s, "srch")){
            scanf("%s", sl);
            if(!ifleg(sl))
                fprintf(stderr, "Szukane slowo ma niedozwolony znak\n\n");
            else
                printf("Slowo wystapilo %u razy\n\n", search(root, sl));
        
        }
        else{
            fprintf(stderr, "Podales zla komende\n\n");
        }
    }

}