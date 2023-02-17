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

void post_order_print(Node *root, FILE *fp)
{
  if(root == NULL)
  {
    return;
  }
  post_order_print(root->left, fp);
  post_order_print(root->right, fp);
  fprintf(fp,"%c", root->value);
  if(root->value != 'V' && root->value != 'H')
  {
    fprintf(fp,"(%d,%d)", root->dim[0], root->dim[1]);
  }
  fprintf(fp,"\n");
}


int* dim_calc(Node* root)
{
  if(root->value != 'H' && root->value != 'V')
  {
    return root->dim;
  }
  else{
    int* left_dim = dim_calc(root->left);
    int* right_dim = dim_calc(root->right);
    if(root->value == 'H')
    {
      root->dim[1] = left_dim[1] + right_dim[1];
      root->dim[0] = max_val(left_dim[0], right_dim[0]);
    }
    else if(root->value == 'V')
    {
      root->dim[0] = left_dim[0] + right_dim[0];
      root->dim[1] = max_val(left_dim[1], right_dim[1]);
      //printf("V-- w: %d h: %d\n", root->dim[0], root->dim[1]);
    }
  }
  return root->dim;
}

void coord_calc(Node* prev, Node* curr)
{
  if(curr == NULL)
  {
    return;
  }
  if(prev->value == 'a')
  {
    curr->coords[0] = 0;
    curr->coords[1] = 0;
    coord_calc(curr, curr->left);
    coord_calc(curr, curr->right);
    return;
  }
  if(prev->value == 'H')
  {
    if(curr == prev->left)
    {
      curr->coords[0] = prev->coords[0];
      curr->coords[1] = (prev->dim[1] - curr->dim[1]) + prev->coords[1];
      coord_calc(curr, curr->left);
      coord_calc(curr, curr->right);
      return;
    }
    if(curr == prev->right)
    {
      curr->coords[0] = prev->coords[0];
      curr->coords[1] = prev->coords[1];
      coord_calc(curr, curr->left);
      coord_calc(curr, curr->right);
      return;
    }
  }
  if(prev->value == 'V')
  {
    if(curr == prev->left)
    {
      curr->coords[0] = prev->coords[0];
      curr->coords[1] = prev->coords[1];
      coord_calc(curr, curr->left);
      coord_calc(curr, curr->right);
      return;
    }
    if(curr == prev->right)
    {
      curr->coords[0] = (prev->dim[0] - curr->dim[0]) + prev->coords[0];
      curr->coords[1] =  prev->coords[1];
      coord_calc(curr, curr->left);
      coord_calc(curr, curr->right);
      return;
    }
  }

  return;
}

int max_val(int a, int b)
{
  if (a>b)
  {
    return a;
  }
  return b;
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

void post_order_print_dim(Node *root, FILE *fp)
{
  if(root == NULL)
  {
    return;
  }
  post_order_print_dim(root->left, fp);
  post_order_print_dim(root->right, fp);
  fprintf(fp,"%c", root->value);
  fprintf(fp,"(%d,%d)", root->dim[0], root->dim[1]);
  fprintf(fp,"\n");
}

void pre_order_print_coords(Node *root, FILE *fp)
{
  if(root == NULL)
  {
    return;
  }
  if(root->value != 'V' && root->value != 'H')
  {
    fprintf(fp,"%c((%d,%d)(%d,%d))\n", root->value, root->dim[0], root->dim[1],
    root->coords[0], root->coords[1]);
  }
  //printf("%c: %d %d\n", root->value, root->coords[0], root->coords[1]);
  pre_order_print_coords(root->left, fp);
  pre_order_print_coords(root->right, fp);
}
