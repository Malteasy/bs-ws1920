#include "tree.h"
node_t tree;

node_t *createTree(int rootValue){
  tree.value = rootValue;
  tree->parent = (int*)rootValue;
  tree->left = NULL;
  tree->right = NULL;

  return tree;
}
