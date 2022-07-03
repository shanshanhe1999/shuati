//
// Created by shanshan on 2022/5/8.
//
/*
 * 判断是否满足条件比较复杂，可以写一个单独的函数isValid()
 */
#include <vector>
#include <string>
using namespace std;

class Solution{
public:
    vector<vector<string>> ret;
    //vector<string> path;
    void backtrack(int n,int row,vector<string>& chessboard){
        if(row==n){
            ret.push_back(chessboard);
            return;
        }
        for(int i=0;i<n;i++){
            if(isValid(row,i,chessboard,n)){
                chessboard[row][i]='Q';
                backtrack(n,row+1,chessboard);
                chessboard[row][i]='.';
            }
        }
    }
    bool isValid(int row,int col,vector<string>& chessboard,int n){
        for(int i=0;i<row;i++){
            if(chessboard[i][col]=='Q') return false;
        }
        for(int i=row-1,j=col-1;i>=0&&j>=0;i--,j--){
            if(chessboard[i][j]=='Q') return false;
        }
        for(int i=row-1,j=col+1;i>=0&&j<n;i--,j++){
            if(chessboard[i][j]=='Q') return false;
        }
        return true;
    }
    vector<vector<string>> solveNQueens(int n){
        ret.clear();
        vector<string> chessboard(n,string(n,'.'));
        backtrack(n,0,chessboard);
        return ret;
    }
};