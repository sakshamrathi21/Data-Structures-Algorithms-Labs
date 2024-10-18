// Problem 1

#include "bst.h"

bool recursive_search(TreeNode* root) {
  if (root == NULL) return true;
  TreeNode* curr = root;
  if (curr->left == NULL && curr->right == NULL) return true;
  else if (curr->left == NULL && curr->right != NULL) {
    if(curr->right->key >= curr->key) {return recursive_search(curr->right);}
    else {return false;}}
  else if (curr->left != NULL && curr->right == NULL) {
    if(curr->left->key <= curr->key) {return recursive_search(curr->left);}
    else {return false;}}
  else {
    if(curr->left->key > curr->key) return false;
    if (curr->right->key < curr->key) return false;
    bool left_sign = recursive_search(curr->left);
    bool right_sign = recursive_search(curr->right);
    if (left_sign && right_sign) return true;
    else return false;
    }
}

bool BST::isBST() {
  TreeNode* curr = root;
  return recursive_search(curr);
}
