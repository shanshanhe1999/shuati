//
// Created by shanshan on 2022/5/21.
//
#include "treeNode.h"
#include <algorithm>
/*
 * 二叉树的最小深度定义为：从根节点到最近叶子节点的最短路径上的节点数量
 * 递归逻辑：
 *  -需要判断，当左子树为空而右子树不为空时，此时节点的最小深度为1+右子树的最小深度
 */
int getMinDepth(TreeNode* root){
    if(root== nullptr) return 0;
    
    int left= getMinDepth(root->left);//左
    int right= getMinDepth(root->right);//右
    //中
    /*
     * 以下代码为本层逻辑
     */
    if(root->left== nullptr && root->right!= nullptr) return 1+right;
    if(root->left!= nullptr && root->right== nullptr) return 1+left;
    
    return 1+std::min(left,right);
}
int minDepth(TreeNode* root){
    return getMinDepth(root);
}