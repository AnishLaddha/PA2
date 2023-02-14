#include <stdio.h>
#include <stdlib.h>
#include "bin_head.h"

int build_tree(Node * prev, Node *curr, Node *a)
{

  if(curr == NULL)
  {
    if(curr == prev->left)
    {
      prev ->left = a;
    }
    else
    {
      prev -> right = a;
    }
    return 1;
  }
  if(curr->value == 'H' || curr->value == 'V')
  {
    int s = build_tree(curr, curr->left, a);
    if(s == 0)
    {
      s = build_tree(curr, curr->right, a);
    }
    return s;
  }
  return 0;
}

void post_order_print(Node *root)
{
  if(root == NULL)
  {
    return;
  }
  post_order_print(root->left);
  post_order_print(root->right);
  printf("%c", root->value);
  if(root->value != 'V' && root->value != 'H')
  {
    printf("(%d,%d)", root->width, root->height);
  }
  printf("\n");
}

void free_tree(Node* root)
{
  if(root == NULL)
  {
    return;
  }
  free_tree(root->left);
  free_tree(root->right);
  free(root);
}
