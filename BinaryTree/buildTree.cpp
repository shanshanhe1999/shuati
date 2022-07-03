//
// Created by shanshan on 2022/4/23.
//
//1 根据数组构造二叉树
#include <vector>
using namespace std;

struct TreeNode{
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode():value(0),left(nullptr),right(nullptr){};
    TreeNode(int _val):value(_val),left(nullptr),right(nullptr){};
};

class buildTree{
public:
    TreeNode* construct_binary_tree(const vector<int>& vec){
        vector<TreeNode*> vecTree(vec.size(),nullptr);
        TreeNode* root= nullptr;
        for(int i=0;i<vec.size();i++){
            TreeNode* node= nullptr;
            if(vec[i]!=-1) node=new TreeNode(vec[i]);
            vecTree[i]=node;
            if(i==0) root=node;
        }
        for(int i=0;i*2+2<vec.size();i++){
            if(vecTree[i]!=nullptr){
                vecTree[i]->left=vecTree[i*2+1];
                vecTree[i]->right=vecTree[i*2+2];
            }
        }
        return root;
    }
};
//2 根据中序和后序序列构造二叉树
/*
 * 若数组大小为0，则是空节点；
 * 若不为零，则取后序数组最后一个元素作为节点
 * 找到此元素在中序数组中的位置，对中序数组进行切割
 * 根据切割后的中序子数组的最后一个元素，再对后序数组进行切割
 * 递归处理左区间和右区间
 */
TreeNode* traversal(vector<int>& inorder,vector<int>& postorder){
    //判断数组大小是否为0
    //因为接下来要找后序数组的最后一个元素，所以判断的是后序数组的大小
    if(postorder.size()==0) return nullptr;
    //后序数组的最后一个元素即为当前轮的中间节点
    int rootval=postorder[postorder.size()-1];
    TreeNode* root=new TreeNode(rootval);
    
    if(postorder.size()==1) return root;
    //找到中序数组的切割点
    int In_idx;
    for(In_idx=0;In_idx<inorder.size();In_idx++){
        if(inorder[In_idx]==rootval)
            break;
    }
    /*
     * 整个切割过程会产生四个区间：
     *  中序的两个子区间形成的左右两个子数组
     *  和后序的两个子区间形成的两个左右子数组是相互对应的
     */
    //切割中序数组
    vector<int> leftInorder(inorder.begin(),inorder.begin()+In_idx);
    vector<int> rightInorder(inorder.begin()+In_idx+1,inorder.end());
    
    //切割后序数组——注意要先将最后一个元素删掉
    postorder.resize(postorder.size()-1);
    vector<int> leftPostorder(postorder.begin(),postorder.begin()+leftInorder.size());
    vector<int> rightPostorder(postorder.begin()+leftInorder.size(),postorder.end());
    //构造当前中间节点对应的左右节点
    root->left=traversal(leftInorder,leftPostorder);
    root->right=traversal(rightInorder,rightPostorder);
    
    return root;
}
TreeNode* buildTree(vector<int>& inorder,vector<int>& postorder){
    if(inorder.size()==1||postorder.size()==0) return nullptr;
    return traversal(inorder,postorder);
}
//3 从给定数组构造最大二叉树
TreeNode* constructMaxTree(vector<int>& nums){
    return traversal(nums);
}
TreeNode* traversal(vector<int>& nums){
    TreeNode* node=new TreeNode();
    if(nums.size()==1){
        node->value=nums[0];
        return node;
    }
    int maxValue=0;
    int maxIdx=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]>maxValue){
            maxValue=nums[i];
            maxIdx=i;
        }
    }
    node->value=maxValue;
    
    if(maxIdx>0){
        vector<int> newNums(nums.begin(),nums.begin()+maxIdx);
        node->left= traversal(newNums);
    }
    if(maxIdx<nums.size()-1){
        vector<int> newNums(nums.begin()+maxIdx+1,nums.end());
        node->right=traversal(newNums);
    }
    return node;
}