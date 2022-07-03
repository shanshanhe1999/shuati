//
// Created by shanshan on 2022/5/28.
//
#include "treeNode.h"
#include <climits>

using namespace std;
/*
 * 我们要比较的不是单纯的左节点小于中间节点，右节点大于中间节点
 * 而是，左子树所有节点小于中间节点，右子树所有节点大于中间节点
 */
long long maxval=LONG_MIN;
bool isValidBST(TreeNode* root){
    if(root== nullptr) return root;
    
    bool left= isValidBST(root->left);
    if(maxval<root->val) maxval=root->val;
    else return false;
    bool right= isValidBST(root->right);
    
    return left&&right;
}