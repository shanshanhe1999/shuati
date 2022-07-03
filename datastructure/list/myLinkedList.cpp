//
// Created by shanshan on 2022/5/20.
//
#include "ListNode.h"

class myLinkedList{
public:
    myLinkedList(){
        size=0;
        head= nullptr;
    }
    ~myLinkedList(){
        ListNode* cur=head;
        while(size>=0){
        
        }
    }
    int get(int index);
    void addAtHead(int val);
    void addAtTail(int val);
    void addAtIndex(int index,int val);
    void deleteAtIndex(int index);
private:
    int size;
    ListNode* head;
};
int myLinkedList::get(int index){
    if(index>(size-1)||index<0)
        return -1;
    ListNode* cur=head;
    while(index>=0){
        cur=cur->next;
        index--;
    }
    return cur->val;
}
void myLinkedList::addAtHead(int val) {
    ListNode* newNode=new ListNode(val);
    newNode->next=head->next;
    head->next=newNode;
    size++;
}
void myLinkedList::addAtTail(int val) {
    ListNode* newNode=new ListNode(val);
    ListNode* cur=head;
    while(cur->next!= nullptr){
        cur=cur->next;
    }
    cur->next=newNode;
    newNode->next=nullptr;
    size++;
}
void myLinkedList::addAtIndex(int index,int val) {
    if(index>size){
        return;
    }
    ListNode* newNode=new ListNode(val);
    ListNode* cur=head;
    while(index!=0){
        cur=cur->next;
        index--;
    }
    newNode->next=cur->next;
    cur->next=newNode;
    size++;
}
void myLinkedList::deleteAtIndex(int index) {
    if(index>=size||index<0){
        return;
    }
    ListNode* cur=head;
    while(index--){
        cur=cur->next;
    }
    ListNode* temp=cur->next;
    cur->next=cur->next->next;
    delete temp;
    size--;
}
