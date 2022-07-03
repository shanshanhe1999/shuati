//
// Created by shanshan on 2022/5/22.
//
#include <vector>
#include "treeNode.h"
using namespace std;

//递归实现前序遍历
void traversalPreorder(TreeNode* node,vector<int>& vec){
    if(node== nullptr) return;
    
    vec.push_back(node->val);//中
    traversalPreorder(node->left,vec);//左
    traversalPreorder(node->right,vec);//右
    
    return;
}
//递归实现中序遍历
void traversalInorder(TreeNode* node,vector<int>& vec){
    if(node==nullptr) return;
    
    traversalInorder(node->left,vec);
    vec.push_back(node->val);
    traversalInorder(node->right,vec);
    
    return;
}
//递归实现后序遍历
void traversalPostorder(TreeNode* node,vector<int>& vec){
    if(node==nullptr) return;
    
    traversalPostorder(node->left,vec);
    traversalPostorder(node->right,vec);
    vec.push_back(node->val);
    
    return;
}
int main(){
    vector<int> preOrder;
    vector<int> inOrder;
    vector<int> postOrder;
    
    TreeNode* root;
    traversalPreorder(root,preOrder);
    traversalInorder(root,inOrder);
    traversalPostorder(root,postOrder);
    
    return 0;
}