#include <stdio.h>
#include <stdlib.h>
#include "bin_head.h"

int main()
{
  char data[5] = {'H','3','V','1','2'};
  Node* head = malloc(sizeof(Node));
  head->value = 'a';
  head->left = NULL;
  head->right = NULL;
  
  for(int i = 0; i<5;i++)
  {
    Node* a = malloc(sizeof(Node));
    a->value = data[i];
    a->left = NULL;
    a->right = NULL;

    build_tree(head,head->left, a);
  }
  //printf("%c\n", head->left->value);
  post_order_print(head->left);
  free_tree(head);
  return 0;
}
