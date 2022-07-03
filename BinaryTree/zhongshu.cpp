//
// Created by shanshan on 2022/5/31.
//
#include "treeNode.h"
#include <vector>
#include <climits>
#include <algorithm>
#include <stack>

using namespace std;

class Solution{
private:
    int count=0;
    int maxCount=INT_MIN;
    vector<int> ret;
    TreeNode* pre;
    void searchBST(TreeNode* root){
        if(root==nullptr) return;
        searchBST(root->left);
        if(pre== nullptr){
            count=1;
        }else if(pre->val==root->val){
            count++;
        }else{
            count=1;
        }
        pre=root;
        if(count==maxCount){
            ret.push_back(root->val);
        }else if(count>maxCount){
            ret.clear();
            maxCount=count;
            ret.push_back(root->val);
        }
        searchBST(root->right);
        return;
    }
public:
    vector<int> findMode(TreeNode* root){
        ret.clear();
        pre= nullptr;
        searchBST(root);
        return ret;
    }
};
//迭代法
vector<int> findMode(TreeNode* root){
    stack<TreeNode* > st;
    TreeNode* cur=root;
    TreeNode* pre= nullptr;
    int maxCount=0;
    int count=0;
    vector<int> ret;
    while(cur||!st.empty()){
        if(cur!= nullptr){
            st.push(cur);
            cur=cur->left;
        }else{
            cur=st.top();st.pop();
            if(pre== nullptr){
                count=1;
            }else if(pre->val==cur->val){
                count++;
            }else{
                count=1;
            }
            if(count==maxCount){
                ret.push_back(cur->val);
            }else if(count>maxCount){
                ret.clear();
                maxCount=count;
                ret.push_back(cur->val);
            }
            pre=cur;
            cur=cur->right;
        }
    }
    return ret;
}

