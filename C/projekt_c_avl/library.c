#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>
#include<string.h>
#include"library.h"

node *new_node(int val){    //zaalokowanie pamieci na nowy wierzcholek i ustawienie poczatkowych parametrow
    node *temp = (node *)malloc(sizeof(node));
    temp->val = val;
    temp->left = temp->right = NULL;
    temp -> height = 0;
    return temp;
}

int height(node *wood){    //zwracanie wysokosci danego podrzewa
    if(wood == NULL)
        return -1;
    return wood->height;
}

int maxh(int h1, int h2){   //zwrocenie maksymalnej wysokosci z 2 podanych wysokosci
    return (h1 > h2)? h1 : h2;
}

void seth(node *wood){     //ustawienie wysokosci wierzcholka
    wood->height = maxh(height(wood->right), height(wood->left)) + 1;
}

int is_bal(node *wood){    //sprawdzenie czy drzewo jest zbalansowane i w ktora strona drzewa jest "ciezsza"
    if(wood == NULL)
        return 0;
    return height(wood->left) - height(wood->right);
}

node *right_rotate(node *red){     //prawa rotacja w drzewie (zmiana balansu podrzewa)
    node *blue = red->left;    //chcemy podmienic wierzholki blue i red aby zachowac strukture drzewa (dobrze ustawic ich dzieci)
    node *tmp = blue->right;

    blue -> right = red;
    red -> left = tmp;

    seth(blue); //ustawiamy wysokosci dwoch zmienionych poddrzew
    seth(red);

    return blue;
}

node *left_rotate(node *blue){  //analogicznie do right rotate
    node *red = blue -> right;
    node *tmp = red -> left;

    red->left = blue;
    blue -> right = tmp;

    seth(blue);
    seth(red);

    return red;
}

node *add_node(node *wood, int val){    //znalezienie miejsca gdzie dodac wierzcholek i dodanie go
    if(wood == NULL)
        return new_node(val);
    if(val < wood->val)
        wood->left = add_node(wood->left, val);
    else if(val > wood->val)
        wood->right = add_node(wood->right, val);
    else{
        fprintf(stderr, "Ta wartosc juz wystapila w drzewie\n");
        return wood;
    }

    seth(wood);
    int bal = is_bal(wood);

    if(bal > 1 && val < wood->left->val)    // lewe podrzewo wood rozciaga sie mocniej na lewo
        return right_rotate(wood);

    if(bal > 1 && val > wood->left->val){  // lewe podrzewo wood rozciaga sie mocniej na prawo
        wood->left = left_rotate(wood->left);
        return right_rotate(wood);
    }

    if(bal < -1 && val > wood->right->val)    //prawe podrzewo wood rozciaga sie mocniej na prawo
        return left_rotate(wood);

    if(bal > 1 && val < wood->right->val){  // left-right (lewe podrzewo wood rozciaga sie mocniej na prawo)
        wood->right = right_rotate(wood->right);
        return left_rotate(wood);
    }

    return wood;
}

int min(node *wood){    //znalezienie minimum w drzewie
    node *tmp = wood;
    while(tmp->left != NULL)
        tmp = tmp->left;
    return tmp->val;
}

int max(node *wood){    //znalezienie maximum w drzewie
    node *tmp = wood;
    while(tmp->right != NULL)
        tmp = tmp->right;
    return tmp->val;
}

node *del_node(node *wood, int val){    //znalezienie i usuniecie danego wierzcholka
    if(wood == NULL)
        return wood;

    if(val > wood->val)
        wood->right = del_node(wood->right, val);
    else if(val < wood->val)
        wood->left = del_node(wood->left, val);
    else{
        if(wood->left == NULL){ //przypadek 1 lub 0 dzieci
            node *new_wood = wood->right;
            free(wood);
            return new_wood;
        }
        else if(wood->right == NULL){   // przypadek 1 lewego dziecka
            node *new_wood = wood->left;
            free(wood);
            return new_wood;
        }
        else{   //przypadek 2 dzieci
            node *new_wood = wood->right;
            while(new_wood->left != NULL)
                new_wood = new_wood->left;
            wood->val = new_wood->val;
            wood->right = del_node(wood->right, new_wood->val);
        }
    }

    if(wood == NULL)
        return wood;

    seth(wood);     //update wyskosci
    int bal = is_bal(wood);

    if(bal > 1 && is_bal(wood->left) >= 0)    // lewe podrzewo wood rozciaga sie mocniej na lewo
        return right_rotate(wood);

    if(bal > 1 && is_bal(wood->left) < 0){    // lewe podrzewo wood rozciaga sie mocniej na prawo
        wood->left = left_rotate(wood->left);
        return right_rotate(wood);
    }

    if(bal < -1 && is_bal(wood->right) <= 0)    //prawe podrzewo wood rozciaga sie mocniej na prawo
        return left_rotate(wood);

    if(bal < -1 && is_bal(wood->right) > 0){    // left-right (lewe podrzewo wood rozciaga sie mocniej na prawo)
        wood->right = right_rotate(wood->right);
        return left_rotate(wood);
    }

    return wood;
}


void free_tree(node *wood){    //zwolnienie calego poddrzewa
    if(wood->left != NULL)
        free_tree(wood->left);
    if(wood->right != NULL)
        free_tree(wood->right);
    free(wood);
}

bool contain_val(node* wood, int val){     //wyszukanie i sprawdzenie czy dana wartosc wystepuje w drzewie
    if(wood == NULL)
        return 0;
    if(wood->val == val)
        return 1;
    if(wood->val < val)
        return contain_val(wood->right, val);
    return contain_val(wood->left, val);
}

void next_val(node *wood, int val, int *wyn){   //znalezienie najstepnej wartosic od podanej wartosci
    if(wood->val > val && wood->val < *wyn)
        *wyn = wood->val;
    if(wood->right != NULL)
        next_val(wood->right, val, wyn);
    if(wood->left != NULL)
        next_val(wood->left, val, wyn);
}

void prev_val(node *wood, int val, int *wyn){   //znalezienie poprzedniej wartosci od podanej wartosci
    if(wood->val < val && wood->val > *wyn)
        *wyn = wood->val;
    if(wood->right != NULL)
        prev_val(wood->right, val, wyn);
    if(wood->left != NULL)
        prev_val(wood->left, val, wyn);
}

void write(node *wood, int x){     //wypisanie drzewa
    if(wood->right != NULL)
        write(wood->right, x + 1);
    for(int i = 0; i < x; i++){
        printf("    ");
    }
    printf("%d\n", wood->val);
    if(wood->left != NULL)
        write(wood->left, x + 1);
}

void solve(node *tree){     //sklejenie wszystkich w funkcji w interaktywny interfejs
    int x;
    char s[6];
    int tmp;
    printf("\nPodaj jedna z wymienionych komend:\n\nins - dodanie nowego wierzcholka do drzewa\ndel - usuniecie wierzcholka z drzewa\nsrch - sprawdzenie czy dany wierzcholek wystapil w drzewie\nmin - znalezienie najmniejszej wartosci na drzewie\nmax - znalezienie najwiekszej wartosci na drzewie\nprev - znalezienie poprzednika podanego wierzcholka\nnext - znalezienie nastepnieka podanego wierzcholka\nprint - wypisanie calego drzewa\nquit - wyjscie z programu\n\n");
    while(true){
        scanf("%s", &s);
        if(strcmp(s, "ins")== 0){
            scanf("%d", &x);
            tree = add_node(tree, x);
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
