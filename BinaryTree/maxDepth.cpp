//
// Created by shanshan on 2022/4/23.
//
#include <algorithm>
#include "treeNode.h"
using namespace std;
/*
 * 二叉树的最大深度定义为根节点到叶子节点的最长路径的节点数
 * 递归函数：
 *  -单层递归的逻辑：针对当前节点，求左右子树的最大深度；后取二者最大值+1，即加上当前节点
 *  -参数：根节点；返回值：最大深度
 */
class solution {
public:
    int getdepth(TreeNode* node) {
        if (node == nullptr) return 0;
        
        int leftdepth = getdepth(node->left);// 左
        int rightdepth = getdepth(node->right);// 右
        int depth = 1 + max(leftdepth, rightdepth);// 中
        return depth;
    }
    int maxdepth(TreeNode* root) {
        return getdepth(root);
    }
};