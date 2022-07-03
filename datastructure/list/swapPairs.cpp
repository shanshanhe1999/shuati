//
// Created by shanshan on 2022/5/20.
//
#include "ListNode.h"

ListNode* swapPairs(ListNode* head){
    ListNode* dummy=new ListNode(0,head);
    //ListNode* cur=head;
    ListNode* cur=dummy;
    while(cur->next!=nullptr&&cur->next->next!=nullptr){
        ListNode* temp1=cur->next;
        ListNode* temp2=cur->next->next->next;
        
        cur->next=cur->next->next;
        cur->next->next=temp1;
        cur->next->next->next=temp2;
        cur=cur->next->next;
    }
    return dummy->next;
}