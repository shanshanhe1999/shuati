//
// Created by shanshan on 2022/5/22.
//
#include "treeNode.h"
#include <algorithm>
using namespace std;

int getDepth(TreeNode* node){
    if(node==nullptr) return 0;
    
    int left= getDepth(node->left);
    if(left==-1) return -1;
    int right= getDepth(node->right);
    if(right==-1) return -1;
    
    if(abs(left-right)>1){
        return -1;
    }else{
        return 1+max(left,right);
    }
}