#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
   char value;
   int coords[2]; //coords[0]: x coordinate, coords[1]: 
   int dim[2]; //dim[0]: width, dim[1]: height
   struct _Node *left, *right;
} Node;

int build_tree(Node * prev, Node *curr, Node *a);

void post_order_print(Node *root, FILE *fp);
void free_tree(Node* root);
int max_val(int a, int b);
int* dim_calc(Node* root);
void post_order_print_dim(Node *root, FILE *fp);