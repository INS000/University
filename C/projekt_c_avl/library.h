typedef struct node{
    int val, height;
    struct node *left, *right; 
}node;

node *new_node(int val);

int height(node *wood);

int maxh(int h1, int h2);

void seth(node *wood);

int is_bal(node *wood);

node *right_rotate(node *red);

node *left_rotate(node *blue);

node *add_node(node *wood, int val);

int min(node *wood);

int max(node *wood);

// node * minValueNode(node* wood);

node *del_node(node *wood, int val);

void free_tree(node *wood);

bool contain_val(node* wood, int val);

void next_val(node *wood, int val, int *wyn);

void prev_val(node *wood, int val, int *wyn);

void write(node *wood, int x);

void solve(node *tree);
