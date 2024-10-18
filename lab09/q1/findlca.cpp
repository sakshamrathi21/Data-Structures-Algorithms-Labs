#include "tree.h"

// Function which returns lca node of given nodes 'a' and 'b'
TreeNode* TREE::findlca(TreeNode* a, TreeNode* b) {
  if (root == nullptr || a == nullptr || b == nullptr) {
    return nullptr;
  }
  TreeNode* curra = a;
  TreeNode* currb = b;
  int levela = 0;
  int levelb = 0;

  while (curra != root) {
    levela ++;
    curra = curra->parent;
  }

  while (currb != root) {
    levelb ++;
    currb = currb->parent;
  }

  curra = a;
  currb = b;

  if (levela > levelb) {
    for (int i = 0; i < levela-levelb; i ++) {
      curra = curra->parent;
    }
  }
  else if (levelb > levela) {
    for (int i = 0; i < levelb-levela; i ++) {
      currb = currb->parent;
    }
  }

  while (curra != currb) {
    curra = curra->parent;
    currb = currb->parent;
  }

  return curra;
}