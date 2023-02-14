#include <stdio.h>
#include <stdlib.h>
#include "bin_head.h"

// int main()
// {
//   char data[15] = {'H','H','V','2','5','1','V','V','H','3','V','7','4','6','8'};
//   Node* head = malloc(sizeof(Node));
//   head->value = 'a';
//   head->left = NULL;
//   head->right = NULL;
  
//   for(int i = 0; i<(sizeof(data)/sizeof(data[0]));i++)
//   {
//     Node* a = malloc(sizeof(Node));
//     a->value = data[i];
//     a->left = NULL;
//     a->right = NULL;

//     build_tree(head,head->left, a);
//   }
//   //printf("%c\n", head->left->value);
//   post_order_print(head->left);
//   free_tree(head);
//   return 0;
// }

int main()
{
  char c_read;
  int x_read;
  int y_read;


  Node* head = malloc(sizeof(Node));
  head->value = 'a';
  head->left = NULL;
  head->right = NULL;

  FILE *fp = fopen("examples/8.pr","r");


  c_read = fgetc(fp);
  if(c_read == EOF)
  {
    return EXIT_FAILURE;
  }


  while(c_read != EOF)
  {
    if(c_read == '\n')
    {
      c_read = fgetc(fp);
    }
    //printf("CREAD: %c\n", c_read);
    Node* a = malloc(sizeof(Node));
    a->value = c_read;
    a->left = NULL;
    a->right = NULL;
    if(c_read != 'V' && c_read != 'H')
    {
      fscanf(fp, "(%d,%d)\n", &x_read, &y_read);
      a->height = y_read;
      a->width = x_read;
    }
    build_tree(head,head->left, a);
    c_read = fgetc(fp);
  }
  
  fclose(fp);
  //printf("%c\n", head->left->value);
  post_order_print(head->left);
  free_tree(head);
  return 0;
}

