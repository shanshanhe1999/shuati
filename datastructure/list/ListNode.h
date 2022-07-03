//
// Created by shanshan on 2022/5/20.
//

#ifndef SHUATI_LISTNODE_H
#define SHUATI_LISTNODE_H
struct ListNode{
    int val;
    ListNode* next;
    ListNode():val(0),next(nullptr){}
    ListNode(int _val):val(_val),next(nullptr){}
    ListNode(int _val,ListNode* n):val(_val),next(n){}
};

#endif //SHUATI_LISTNODE_H
