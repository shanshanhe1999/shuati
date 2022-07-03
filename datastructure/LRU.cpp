//
// Created by shanshan on 2022/4/21.
#include <unordered_map>
using namespace std;

struct Node{
    int key,val;
    Node* next;
    Node* prev;
    Node():key(0),val(0),next(nullptr),prev(nullptr){};
};
class LRUCache{
private:
    unordered_map<int,Node*> cache;
    Node* head=new Node();
    Node* tail=new Node();
    int size;
    int capacity;
public:
    LRUCache(int capacity){
        head->next=tail;
        tail->prev=head;
        this->capacity=capacity;
        size=0;
    }
    int get(int key){
        if(!cache.count(key)){
            return -1;
        }else{
            Node* node=cache[key];
            moveToHead(node);
            return node->val;
        }
    }
    void put(int key,int value){
        if(!cache.count(key)){
            Node* node=new Node();
            addToHead(node);
            size++;
            if(size>capacity){
                Node* node=removeTail();
                size--;
                cache.erase(node->key);
            }
        }else{
            Node* node=cache[key];
            moveToHead(node);
            node->val=value;
        }
    }
    void addToHead(Node* node){
        node->prev=head;
        node->next=head->next;
        head->next->prev=node;
        head->next=node;
    }
    void moveToHead(Node* node){
        removeNode(node);
        addToHead(node);
    }
    Node* removeTail(){
        Node* node=tail->prev;
        tail->prev=node->prev;
        node->prev->next=tail;
        return node;
    }
    void removeNode(Node* node){
        node->prev->next=node->next;
        node->next->prev=node->prev;
    }
};