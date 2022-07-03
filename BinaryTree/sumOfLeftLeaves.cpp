//
// Created by shanshan on 2022/5/22.
//
#include "treeNode.h"
#include <stack>

using namespace std;
//递归法
int sumOfLeftLeaves(TreeNode* root) {
    if(root== nullptr) return 0;
    
    int left= sumOfLeftLeaves(root->left);
    int right= sumOfLeftLeaves(root->right);
    
    int midValue=0;
    if(root->left!= nullptr&&root->left->left== nullptr&&root->left->right== nullptr){
        midValue+=root->left->val;
    }
    int sum=midValue+left+right;
    return sum;
}
//迭代法
int sumOfLeftLeaves2(TreeNode* root) {
    stack<TreeNode*> st;
    if (root == nullptr) return 0;
    st.push(root);
    int result = 0;
    while (!st.empty()) {
        TreeNode* node = st.top();
        st.pop();
        if (node->left != nullptr && node->left->left == nullptr && node->left->right == nullptr) {
            result += node->left->val;
        }
        if (node->right) st.push(node->right);
        if (node->left) st.push(node->left);
    }
    return result;
}