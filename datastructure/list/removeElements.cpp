//
// Created by shanshan on 2022/5/20.
//
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode* removeElements(ListNode* head,int val){
    ListNode* dummy=new ListNode(-1,head);
    ListNode* cur=dummy;
    while(cur->next!=nullptr){
        if(cur->next->val==val){
            cur->next=cur->next->next;
        }else{
            cur=cur->next;
        }
    }
    return dummy->next;
}
