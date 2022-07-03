//
// Created by shanshan on 2022/5/5.
//
/*
 * 回溯法：
 *      1 确定回溯函数的参数和返回值
 *      2 确定回溯函数的终止条件
 *      3 确定回溯搜索的遍历过程
 *伪代码：
 *      void backtrack(参数){
 *          if(终止条件){
 *          存放结果；
 *          return;
 *          }
 *          for(选择：本层集合中元素（树中节点孩子的数量就是集合的大小）){
 *              处理节点；
 *              backtrack(路径，选择列表);//递归
 *              回溯，撤销处理结果
 *          }
 *      }
 */
#include <vector>
using namespace std;

class backTrack{
public:
    vector<int> path;
    vector<vector<int>> ret;
    void backtrack(int n,int k, int startIdx){
        if(path.size()==k){
            ret.push_back(path);
            return;
        }
        //单层搜索的过程
        for(int i=startIdx;i<=n;i++){
            path.push_back(i);
            backtrack(n,k,i+1);
            path.pop_back();
        }
    }
};