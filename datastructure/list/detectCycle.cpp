//
// Created by shanshan on 2022/5/20.
//
#include "ListNode.h"
ListNode* detectCycle(ListNode* head)
{
    ListNode* fast=head;
    ListNode* slow=head;
    while(fast!= nullptr&&fast->next!= nullptr)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast) break;
    }
    if(fast==nullptr||fast->next==nullptr) return nullptr;
    slow=head;
    while(fast!=slow){
        fast=fast->next;
        slow=slow->next;
    }
    return slow;
}