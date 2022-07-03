//
// Created by shanshan on 2022/5/23.
//
/*
 * 1 判断两个树是否相等：
 *  -当前两个树的根节点值相等
 *  -两个树的左子树和右子树分别都相等
 *  此时的三个条件必须同时成立
 * 2 判断两个树是否为父子
 *  -当前两个树相等
 *  -t是s的左子树
 *  -t是s的右子树
 *  -此时的三个条件只要有一个成立即可
 */
#include "treeNode.h"

using namespace std;

bool isSameTree(TreeNode* root1,TreeNode* root2){
    if(root1==nullptr&&root2==nullptr) return true;
    else if(root1== nullptr&&root2!= nullptr) return false;
    else if(root1!=nullptr&&root2== nullptr) return false;
    else if(root1->val!=root2->val) return false;
    //剩下的就是root1->val==root2->val的情况
    //后序遍历
    bool left= isSameTree(root1->left,root2->left);
    bool right= isSameTree(root1->right,root2->right);
    bool isSame=left&&right;
    
    return isSame;
}
bool isSubTree(TreeNode* root1,TreeNode* root2){
    if(root1== nullptr&&root2== nullptr) return true;
    else if(root1==nullptr&&root2!= nullptr) return false;
    //else if(root1!= nullptr&&root2== nullptr) return false;
    
    bool left= isSubTree(root1->left,root2);
    bool right= isSubTree(root1->right,root2);
    bool isSame= isSameTree(root1,root2);
    bool isSub=isSame||left||right;
    return isSub;
}