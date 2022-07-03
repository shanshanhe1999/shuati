//
// Created by shanshan on 2022/5/20.
//
/*
 * 链表是一种通过指针串联在一起的线性结构，
 * 每一个节点由两部分组成：数据域和指针域，最后一个节点的指针指向null
 * 链表分为单链表和双链表，还有循环链表
 * 链表在内存中不是连续分布的
 */
//链表结构的定义
struct ListNode{
    int val;
    ListNode* next;
    ListNode():val(0),next(nullptr){};
    ListNode(int _val):val(_val),next(nullptr){};
};
//链表的操作
//删除节点
/*
 * 删除节点时需要借助该节点的前后两个节点
 * 删除后释放内存
 */
//添加节点
/*
 * 添加节点本身是O(1)，但找到该节点是o(n)
 */