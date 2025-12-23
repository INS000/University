#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include "lib.h"
#define N ('z' - 'a' + 1)


int main(int argc, char *argv[]){
    node *root = new_node();
    int maxsize = 0;
    FILE *plik;
    char s[190000];
    for(int i = 1; i < argc; i++){
        plik = fopen(argv[i], "r");
        while(!feof(plik)){
            fscanf(plik, "%s", s);
            new_word(root, s, &maxsize);
        }
        fclose(plik);
    }
    interface(root, maxsize);
}
/*test1.txt

In this edition of The Lord of the Rings prepared for the fiftieth
anniversary of its publication between three and four hundred emendations have been made following an exhaustive review of past
editions and printings The present text is based on the setting of
the HarperCollins three volume hardcover edition of which in
turn was a revision of the HarperCollins reset edition of 1994 As
Douglas A Anderson comments ,in the preceding Note on the Text
each of those editions was itself corrected and each also introduced
new errors At the same time other errorssurvived undetected among
them some five dozen which entered aslong ago as  in the resetting
of The Fellowship of the Ring published as its second impression



test2.txt

agrawka polimer     oblazanek sma&cznego

oligarchia polimer polimer agrawka ola

*/