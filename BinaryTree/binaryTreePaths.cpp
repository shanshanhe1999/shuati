//
// Created by shanshan on 2022/5/22.
//
#include "treeNode.h"
#include <vector>
#include <string>
#include <stack>
using namespace std;

void traversal(TreeNode* node,vector<int>& path,vector<string>& ret){
    if(node->left== nullptr&&node->right== nullptr){
        string sPath;
        for(int i=0;i<path.size()-1;i++){
            sPath+= to_string(path[i]);
            sPath+="->";
        }
        sPath+=to_string(path[path.size()-1]);
        ret.push_back(sPath);
        return;
    }
    path.push_back(node->val);
    //在这里需要判断下节点是否为空
    if(node->left) {
        traversal(node->left,path,ret);//左
        path.pop_back();//回溯
    }
    if(node->right) {
        traversal(node->right,path,ret);//右
        path.pop_back();//回溯
    }
    
}
//迭代法实现
vector<string> getPathsIterate(TreeNode* root){
    stack<TreeNode*> tree;
    stack<string> paths;
    vector<string> ret;
    if(root==nullptr) return ret;
    tree.push(root);
    paths.push(to_string(root->val));
    while(!tree.empty()){
        TreeNode* node=tree.top();tree.pop();
        string path=paths.top();paths.pop();
        //如果当前节点是叶子节点，则将路径放入结果中
        if(node->left==nullptr&&node->right==nullptr){
            ret.push_back(path);
        }
        if(node->right){
            tree.push(node->right);
            paths.push(path="->"+to_string(node->right->val));
        }
        if(node->left){
            tree.push(node->left);
            paths.push(path+"->"+to_string(node->left->val));
        }
    }
    return ret;
}

//递归法实现
vector<string> getPaths(TreeNode* root){
    vector<string> ret;
    vector<int> path;
    traversal(root,path,ret);
    return ret;
}
