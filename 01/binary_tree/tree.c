#include "tree.h"

node_t *tree;

node_t *createTree(int rootValue){



  tree = malloc(sizeof(tree));
  return tree;
}

void insert(node_t *tree, int value){
  if (tree->value > value) {
    tree->left = createTree(value);


  }else{
    tree->right = createTree(value);

  }
}

// return 1 iff value is found in tree, 0 otherwise
int binarySearch(node_t *tree, int value){
  if (tree->value < value) {
    return 1;
  }else{
    return 0;
  }

}

// free all dynamically allocated memory of tree
void cleanUpTree(node_t *tree){
  free(tree);

}
