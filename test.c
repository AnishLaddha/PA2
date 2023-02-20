#include <stdio.h>
#include <stdlib.h>
#include "bin_head.h"

int main(int argc, char** argv)
{
  if(argc != 5)
  {
    return EXIT_FAILURE;
  }
  char c_read;
  int x_read;
  int y_read;


  Node* head = malloc(sizeof(Node));
  head->value = 'a';
  head->left = NULL;
  head->right = NULL;


  FILE *fp = fopen(argv[1],"r");
  if(fp == NULL)
  {
    free_tree(head);
    return EXIT_FAILURE;
  }
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
      if (fscanf(fp, "(%d,%d)\n", &x_read, &y_read) == 0)
      {
        fprintf(stderr, "Could not read values\n");
      }
      //consider 2 digit case ->use fseek to return 
      a->dim[1] = y_read;
      a->dim[0] = x_read;
    }
    build_tree(head,head->left, a);
    c_read = fgetc(fp);
  }
  
  fclose(fp);

  
  fp = fopen(argv[2],"w");
  if(fp == NULL)
  {
    free_tree(head);
    return EXIT_FAILURE;
  }
  int* temp = dim_calc(head->left);
  head->left->dim[0] = temp[0];
  head->left->dim[1] = temp[1];
  post_order_print(head->left, fp);
  fclose(fp);


  fp = fopen(argv[3],"w");
  if(fp == NULL)
  {
    free_tree(head);
    return EXIT_FAILURE;
  }
  post_order_print_dim(head->left, fp);
  fclose(fp);


  fp = fopen(argv[4],"w");
  coord_calc(head, head->left);
  if(fp == NULL)
  {
    free_tree(head);
    return EXIT_FAILURE;
  }
  pre_order_print_coords(head->left,fp);
  fclose(fp);



  

  free_tree(head);
  return EXIT_SUCCESS;
}

