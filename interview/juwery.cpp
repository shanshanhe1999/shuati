//
// Created by shanshan on 2022/5/18.
//
#include <string>
#include <vector>
#include <iostream>
using namespace std;


int main(){
    int n;
    cin>>n;
    vector<pair<int,int>> input;
    for(int i=0;i<n;i++){
        int temp1=0;int temp2=0;
        cin>>temp1>>temp2;
        input[i].first=temp1;
        input[i].second=temp2;
    }
    sort(input.begin(),input.end(),cmp);
    int count=1;
    vector<int> zhadan;vector<int> san;vector<int> single;
    for(int i=0;i<n;i++){
        if(i>0&&input[i].second==input[i-1].second){
            count++;
            if(count==4){
                zhadan.push_back(input[i].second);
            }else if(count==3){
                san.push_back(input[i].second);
            }
            continue;
        }
        if(count==1){
        
        }
    }
}