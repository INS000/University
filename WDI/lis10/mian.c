#include<stdio.h>
#include<stdlib.h>

typedef struct elem{
    int val;
    struct elem *next;
 }elem;

elem *tail = NULL;

elem *utworz(int wart){
    elem *pom = (elem *)malloc(sizeof(elem));
    pom->val = wart;
    pom->next = NULL;
    return pom;
}

void print(elem *list){
    if(list != NULL)
        printf("%d", list->val);
    if(list->next != NULL){
        printf(" -> ");
        print(list->next);
    }
        
}

elem *zad1(elem *list, int val){
    if(list == NULL)
        return utworz(val);
    else
        list->next = zad1(list->next, val);
    
    return list;
}

elem *zad2(elem *list){
    elem *tmp = list;
    if(tmp == NULL){
        return tmp;
    }
    if(tmp->next == NULL){
        free(tmp);
        return NULL;
    }
    while(tmp->next->next != NULL)
        tmp = list->next;
    tmp->next = NULL;
    free(tmp->next);
    return(list);
}

elem *zad3(elem *list1, elem *list2){
    if(list1 == NULL){
        return list2;
    }
    elem *tmp = list1;
    while(tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = list2;
    return list1;
}

elem *zad4(elem *list, int val){
    if(list == NULL)
        return list;
    elem *tmp = list;
    while(list != NULL && list->val == val){
        tmp = list;
        list = list->next;
        free(tmp);
    }
    elem *prev = NULL, *curr = list;
    while(curr != NULL){
        if(curr->val == val){
            prev->next = curr->next;
            tmp = curr;
            curr = curr->next;
            free(tmp);
        }
        else{
            prev = curr;
            curr = curr->next;
        }
    }
    return list;   
}

elem *zad6(elem *list){
    if(list->next != NULL)
        zad6(list->next);
    printf("%d ", list->val);
}

// elem *tail = NULL;

elem *zad7(elem *list, elem *prev){
    if(list->next == NULL)
        tail = list;
    if(list->next != NULL)
        zad7(list->next, list);
    list->next = prev;
    return tail;
}

// void zad8(elem *list, int val, elem *list2){
//     if(list == NULL)
//         return list;
//     elem *tlis = list, *tlis2 = list2;
//     if(list->val > 0){
//         while(tlis != NULL && tlis->val > 0){
//             tlis = tlis->next;
//         }
//         if(tlis == NULL)
//             return;
//         list2
//     }
   
// }

typedef struct dli{
    int val;
    struct dli *next, *prev;
 }dli;

dli *make(int wart, dli *prev){
    dli *pom = (dli *)malloc(sizeof(dli));
    pom->val = wart;
    pom->next = NULL;
    pom->prev = prev;
    return pom;
}

void dmak(dli *node, dli *prev, int val){
    if(node == NULL){
        node = make(val, NULL);
        return;
    }
    else{

    }

}

// void zad9


int main(){
    elem *list = NULL;
    elem *list2 = NULL;
    list = zad1(list, 8);
    list = zad1(list, 8);
    list = zad1(list, 6);
    list = zad1(list, 8);
    list = zad1(list, 8);
    list = zad1(list, 3);
    list = zad1(list, 8);
    list = zad1(list, 8);
    list = zad1(list, 8);
    list = zad1(list, 2);
    list = zad1(list, 1);
    list = zad1(list, 8);
    list = zad4(list, 8);
    print(list);


}