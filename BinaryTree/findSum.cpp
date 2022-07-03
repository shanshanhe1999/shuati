//
// Created by shanshan on 2022/5/9.
//
#include <iostream>
#include "treeNode.h"

using namespace std;
/*
 * 递归函数的返回值问题：
 *  -当需要遍历的是整棵树且不用对返回值进行处理->不要有返回值
 *  -当需要遍历的是整棵树且需要对返回值进行处理->需要有返回值
 *  -当需要搜索出某条符合要求的路径->需要有返回值（因为当条件满足就要及时返回）
 * 相对应的例题：113，236，112（只要找到就行，所以设置返回值，只要存在就返回true）
 */
//递归三步：
/*
 * 1 递归函数的参数和返回值：
 *  -参数：当前节点；当前遍历过的节点之和
 *  -返回值：
 * 2 终止条件
 *  遇到了叶子节点却不符合条件->递归终止
 * 3 单层逻辑--这里有回溯
 */
//112.路径总和
bool traversal(TreeNode* root,int count){
    if(!root->left&&!root->right&&count==0) return true;
    else if(!root->left&&!root->right) return false;
    //这样写的话，对于当前节点来说是不需要进行处理的
    //左
    if(root->left){
        count-=root->left->val;
        traversal(root->left,count);
        count+=root->left->val;
    }
    if(root->right){
        count-=root->right->val;
        traversal(root->right,count);
        count+=root->right->val;
    }
    return false;
}
bool hasPathSum(TreeNode* root,int sum){
    if(root==nullptr) return false;
    return traversal(root,sum);
}
//路径总和Ⅱ
