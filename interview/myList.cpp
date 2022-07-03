//
// Created by shanshan on 2022/5/9.
//
struct Node{
    int value;
    Node* next;
    Node():value(0),next(nullptr){};
    Node(int val):value(val),next(nullptr){};
};
class myList{
public:
    myList();
    void insert(int pos,const Node* node);
    ~myList();
private:
    int size;
    Node* head;
    //Node* tail;
};
myList::myList() {
    head=new Node();
    size=0;
}

void myList::insert(int pos,const Node *node) {
    if(pos>size||pos<0) return;
    Node* cur=head;
    while(pos>0){
        cur=cur->next;
        pos--;
    }
    Node* nd=new Node();
    nd->value=node->value;
    nd->next=cur->next;
    cur->next=nd;
    size++;
}
myList::~myList() {
    while(size>0){
        Node* cur=head;
        for(int i=0;i<size-1;i++){
            cur=cur->next;
        }
        delete cur->next;
        cur->next= nullptr;
        size--;
    }
    delete head;
}