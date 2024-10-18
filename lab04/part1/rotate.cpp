// Problem 2

// Do not include any other file
#include "bst.h"

TreeNode* find_node( int key , TreeNode* root) {
    if(root==NULL)return NULL;
    TreeNode* curr = root;
    while(true){
        if( curr->key==key ) {
          return curr;
        } else if(curr->key > key) {
            if(curr->left==NULL){
                return NULL;
            }else{
                curr = curr->left;
            }
        }else{
            if(curr->right==NULL){
                return NULL;
            }else{
                curr = curr->right;
            }
        }
    }
    return NULL;
}

bool BST::rotate(int y_key) {
  if( y_key < 0) {
    return false;
  }
  TreeNode* y;
  if (find(y_key)) {y = find_node(y_key, root);}
  else return false;
  if (y == NULL) return false;
  if (y->parent == NULL) return false;
  TreeNode* x = y->parent;
  TreeNode* x_parent;
  if(x->parent != NULL) {
    x_parent = x->parent;
  }
  else {
    x_parent = NULL;
  }
  //TreeNode* x_parent = x->parent;
  if (x_parent != NULL) {
    if (x_parent->left == x) {
      if (x->right == y) {
        x->right = y->left;
        if (x->right != NULL) {
          x->right->parent = x;
        }
        x->parent = y;
        y->parent = x_parent;
        x_parent->left = y;
        y->left = x;
      }   
      if (x->left == y) {
        x->left = y->right;
        if (x->left != NULL) {
          x->left->parent = x;
        }
        x->parent = y;
        y->parent = x_parent;
        x_parent->left = y;
        y->right = x;
      }   
  }
  if (x_parent->right == x) {
      if (x->right == y) {
        x->right = y->left;
        if (x->right != NULL) {
          x->right->parent = x;
        }
        x->parent = y;
        y->parent = x_parent;
        x_parent->right = y;
        y->left = x;
      }   
      if (x->left == y) {
        x->left = y->right;
        if (x->left != NULL) {
          x->left->parent = x;
        }
        x->parent = y;
        y->parent = x_parent;
        x_parent->right = y;
        y->right = x;
      }   
  }
  }
  else {
    if (x->right == y) {
        x->right = y->left;
        if (x->right != NULL) {
          x->right->parent = x;
        }
        x->parent = y;
        y->parent = NULL;
        //x_parent->right = y;
        y->left = x;
      }   
      if (x->left == y) {
        x->left = y->right;
        if (x->left != NULL) {
          x->left->parent = x;
        }
        x->parent = y;
        y->parent = NULL;
        //x_parent->right = y;
        y->right = x;
      }   
  }
  return true;
}
