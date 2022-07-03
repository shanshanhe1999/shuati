//
// Created by shanshan on 2022/5/21.
//
#include "treeNode.h"

int getNodesNum(TreeNode* root){
    if(root== nullptr) return 0;
    
    int leftNum = getNodesNum(root->left);      // 左
    int rightNum = getNodesNum(root->right);    // 右
    int treeNum = leftNum + rightNum + 1;      // 中
    
    return treeNum;
}
