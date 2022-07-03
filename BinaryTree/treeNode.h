//
// Created by shanshan on 2022/5/21.
//

#ifndef SHUATI_TREENODE_H
#define SHUATI_TREENODE_H

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode():val(0),left(nullptr),right(nullptr){}
    TreeNode(int _val):val(_val),left(nullptr),right(nullptr){}
};
#endif //SHUATI_TREENODE_H
