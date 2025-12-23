#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct list {
    int val;
    struct list *next;
} list;

list *make(int wart);

list *make_neigh(list *list, int val);

void ginit(int *m, int *n, char c[]);

void dfs(int beg);

int spoj(int n);

void freet(list *smak);

void freeall(list *smak[], int n);

void solve(int ile, char plik[]);
