//
// Created by shanshan on 2022/5/20.
//
#include "ListNode.h"

ListNode* getIntersectionNode(ListNode* headA,ListNode* headB)
{
    ListNode* p1=headA;
    ListNode* p2=headB;
    while(p1!=p2){
        if(p1== nullptr) p1=headB;
        else p1=p1->next;
        if(p2==nullptr) p2=headA;
        else p2=p2->next;
    }
    return p1;
}