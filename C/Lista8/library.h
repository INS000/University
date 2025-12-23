typedef struct node{
    int val;
    struct node *left, *right; 
}node;

node *new_node(int val);

node *add_node(node *wood, int val);

node *del_node(node *wood, int val);

void free_tree(node *wood);

int min(node *wood);

int max(node *wood);

bool contain_val(node* wood, int val);

void next_val(node *wood, int val, int *wyn);

void prev_val(node *wood, int val, int *wyn);

void write(node *wood, int x);

void solve(node *tree);
