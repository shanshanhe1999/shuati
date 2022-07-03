//
// Created by shanshan on 2022/5/21.
//
#include "treeNode.h"

bool compare(TreeNode* root1,TreeNode* root2){
    if(root1== nullptr && root2!= nullptr) return false;
    else if(root2== nullptr && root1!= nullptr) return false;
    else if(root1== nullptr && root2 == nullptr) return true;
    else if(root1->val!=root2->val) return false;
    
    bool outside=compare(root1->left,root2->right);
    bool inside=compare(root1->right,root2->left);
    bool isSym=outside&&inside;
    return isSym;
}
bool isSymmetric(TreeNode* root){
    bool ret=false;
    if(root== nullptr) return true;
    ret=compare(root->left,root->right);
    return ret;
}