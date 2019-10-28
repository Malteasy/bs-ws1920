#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
node_t *tree;

node_t *createTree(int rootValue){


  tree->value = rootValue;
  tree->parent = (node_t*)malloc(sizeof(tree)*10);
  tree->left = (node_t*)malloc(sizeof(tree)*10);
  tree->right = (node_t*)malloc(sizeof(tree)*10);



  return tree;
}

void insert(node_t *tree, int value){
  if ((int)tree->parent > value) {
    tree->left = createTree(value);

  }else{
    tree->right = createTree(value);

  }
}

// return 1 iff value is found in tree, 0 otherwise
int binarySearch(node_t *tree, int value){
  if ((int)tree->parent == value) {
    return 1;
  }else{
    return 0;
  }

}

// free all dynamically allocated memory of tree
void cleanUpTree(node_t *tree){
  free(tree);

}
