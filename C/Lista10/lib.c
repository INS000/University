#include "lib.h"

bool vis[1000003];

list *neigh[1000003];

list *make(int wart) {
    list *pom = (list *)malloc(sizeof(list));
    pom->val = wart;
    pom->next = NULL;
    return pom;
}

list *make_neigh(list *list, int val) {
    if (list == NULL)
        return make(val);
    else
        list->next = make_neigh(list->next, val);
  return list;
}

void ginit(int *m, int *n, char c[]){
    FILE *ptr;
    ptr = fopen(c, "r");
    int a, b;
    fscanf(ptr, "%d %d", n, m);
    for(int i = 0; i < *m; i++){
        fscanf(ptr, "%d %d", &a, &b);
        neigh[a] = make_neigh(neigh[a], b);
        neigh[b] = make_neigh(neigh[b], a);
    }
    fclose(ptr);
}

void dfs(int beg){
    vis[beg] = 1;
    list *pom = neigh[beg];
    while(pom != NULL){
        if(!vis[pom->val]){
            dfs(pom->val);
        }
        pom = pom->next;
    }
}

int spoj(int n){
    int wyn = 0;
    for(int i = 0; i < n; i++){
        if(!vis[i]){
            dfs(i);
            wyn++;
        }
    }
    return wyn;
}

void freet(list *smak){
    if(smak->next != NULL){
        freet(smak->next);
    }
    free(smak);
}

void freeall(list *smak[], int n){
    for(int i = 0; i < n; i++)
        free(smak[i]);
}

void solve(int ile, char plik[]){
    int n, m; // n - wierzcholki, m - krawedzi
    if(ile != 2){
        fprintf(stderr, "Podano zle dane");
        return;
    }
    ginit(&m, &n, plik);
    printf("%d", spoj(n));
    freeall(neigh, n);
}
