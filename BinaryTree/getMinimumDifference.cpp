//
// Created by shanshan on 2022/5/30.
//
#include "treeNode.h"
#include <climits>
#include <algorithm>
#include <stack>

using namespace std;
//1 递归法
int minDiff=INT_MAX;
TreeNode* pre;

void traversal(TreeNode* node){
    if(node==nullptr) return;
    traversal(node->left);
    if(pre){
        minDiff=min(minDiff,node->val-pre->val);
    }
    pre=node;//pre记录的是上一轮递归的根节点
    traversal(node->right);
}
int getMinDiff(TreeNode* root){
    traversal(root);
    return minDiff;
}
//2 迭代法
int getMinDifference(TreeNode* root){
    stack<TreeNode* > st;
    TreeNode* pre= nullptr;
    TreeNode* cur=root;
    int ret=INT_MAX;
    while(cur||!st.empty()){
        if(cur){
            st.push(cur);
            cur=cur->left;
        }else{
            cur=st.top();st.pop();
            if(pre){
                ret=min(ret,cur->val-pre->val);
            }
            pre=cur;
            cur=cur->right;
        }
    }
    return ret;
}