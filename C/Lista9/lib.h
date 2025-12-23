#define N ('z' - 'a' + 1)

typedef struct node{
    struct node *child[N];
    unsigned int counter;
}node;

node *new_node();

void conv(char *a);

void new_word(node *root, char *word, int *maxsize);

unsigned int search(node *root, char *word);

void free_tree(node *root);

void dispal(node *root, char word[], int level);

void fdisp(node *root, int maxsize);

bool ifleg(char sl[]);

void interface(node *root, int maxsize);