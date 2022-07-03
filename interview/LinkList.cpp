//
// Created by shanshan on 2022/5/9.
//
struct Node{
    int value;
    Node* next;
    Node* prev;
    Node():value(0),next(nullptr),prev(nullptr){};
    Node(int val):value(val),next(nullptr),prev(nullptr){};
};
class linkList{
public:
    linkList();
    linkList(const linkList& l);
    ~linkList();
    void addTail(Node* node);
    void addHead(Node* node);
    void search(int value);
    void delNode(int value);
    void showNode();
private:
    int size;
    Node* head;
    Node* tail;
};
linkList::linkList() {
    size=0;
    head->next=tail;
    tail->prev=head;
}
linkList::linkList(const linkList &l) {
    while(l.head!= nullptr){
        Node* nd=l.head;
        head=new Node();
        head->value=nd->value;
        nd=nd->next;
    }
}
void linkList::addHead(Node *node) {
    node->next=head->next;
    node->prev=head;
    head->next->prev=node;
    head->next=node;
}
void linkList::addTail(Node *node) {
    Node* nd=new Node(node->value);
    tail->next=nd;
    size++;
    nd->prev=tail;
    nd->next=nullptr;
    tail=tail->next;
}