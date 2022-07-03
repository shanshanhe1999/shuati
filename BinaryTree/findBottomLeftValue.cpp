//
// Created by shanshan on 2022/5/22.
//
#include "treeNode.h"
#include <climits>
#include <queue>

using namespace std;

//迭代法
int findBottomLeftValue(TreeNode* root) {
    queue<TreeNode*> que;
    if (root != nullptr) que.push(root);
    int result = 0;
    while (!que.empty()) {
        int size = que.size();
        for (int i = 0; i < size; i++) {
            TreeNode* node = que.front();
            que.pop();
            if (i == 0) result = node->val; // 记录最后一行第一个元素
            if (node->left) que.push(node->left);
            if (node->right) que.push(node->right);
        }
    }
    return result;
}
//递归法
/*
 * 树的左下角的值即：
 *  是最深的那一层的最左边的值
 *  递归三步：
 *      -递归函数的参数和返回值
 *          -参数：根节点；当前的深度
 *          -返回值：无
 *      -终止条件：当遇到叶子节点时，需要更新最大深度
 *      -单层递归的逻辑
 */
int maxlen=INT_MIN;
int leftValue=0;

void traversal(TreeNode* root,int level){
    if(root->left== nullptr&&root->right==nullptr){
        if(level>maxlen){//这里其实起到了控制每一层只更新一次的作用，也就是这是最新一层的最左边的值
            maxlen=level;
            leftValue=root->val;
        }
    }//中
    if(root->left){
        level++;
        traversal(root->left,level);
        level--;
        /*
         * 回溯可以利用函数传参是传拷贝进行精简
         * traversal(root->left,level+1);
         * 函数结束后，level的值并不会发生改变
         */
    }
    if(root->right){
        level++;
        traversal(root->right,level);
        level--;
    }
}
int findLeftValue(TreeNode* root){
    traversal(root,0);
    return leftValue;
}