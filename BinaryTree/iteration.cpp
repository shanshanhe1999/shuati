//
// Created by shanshan on 2022/5/10.
//
#include <stack>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include "treeNode.h"

using namespace std;

//迭代法实现前序遍历
vector<int> iteratePreorder(TreeNode* root){
    vector<int> ret;
    if(root== nullptr) return ret;
    stack<TreeNode*> st;
    st.push(root);
    while(!st.empty()){
        int size=st.size();
        TreeNode* node=st.top();st.pop();
        ret.push_back(node->val);
        if(node->right!=nullptr) st.push(node->right);
        if(node->left!=nullptr) st.push(node->left);
    }
    return ret;
}
//迭代法实现中序遍历
/*
 * 处理和访问的节点不一致，因而需要借用指针的遍历来帮助访问节点，栈用来处理节点上的元素
 */
vector<int> iterateInorder(TreeNode* root){
    vector<int> ret;
    if(root== nullptr) return ret;
    stack<TreeNode* > st;
    TreeNode* cur=root;
    while(!st.empty()||cur!=nullptr){
        if(cur!= nullptr){
            st.push(cur);
            cur=cur->left;
        }else{
            cur=st.top();
            st.pop();
            ret.push_back(cur->val);
            cur=cur->right;
        }
    }
    return ret;
}
//迭代法实现后序遍历
vector<int> interatePostorder(TreeNode* root){
    vector<int> ret;
    if(root==nullptr) return ret;
    stack<TreeNode* >st;
    st.push(root);
    while(!st.empty()){
        TreeNode* node=st.top();
        st.pop();
        ret.push_back(node->val);
        if(node->left!=nullptr) st.push(node->left);
        if(node->right!= nullptr) st.push(node->right);
        
    }
    reverse(ret.begin(),ret.end());
    return ret;
}
//迭代法实现层序遍历
vector<vector<int>> levelOrder(TreeNode* root){
    vector<vector<int>> ret;
    vector<int> temp;
    if(root== nullptr) return ret;
    queue<TreeNode* > q;
    q.push(root);
    while(!q.empty()){
        int size=q.size();
        for(int i=0;i<size;i++){
            TreeNode* node=q.front();q.pop();
            temp.push_back(node->val);
            if(node->left!=nullptr) q.push(node->left);
            if(node->right!= nullptr) q.push(node->right);
        }
        ret.push_back(temp);
    }
    return ret;
}
