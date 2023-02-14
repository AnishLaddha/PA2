#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
   char value;
   struct _Node *left, *right;
} Node;

int build_tree(Node * prev, Node *curr, Node *a);

void post_order_print(Node *root);
void free_tree(Node* root);
